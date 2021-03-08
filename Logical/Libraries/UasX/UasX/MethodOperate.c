#include <UasX.h>

typedef enum {STATE_Init, STATE_CheckIsCalled, STATE_IsCalled, STATE_Finishing, STATE_Error = 255} StateEnum;
typedef enum {Good_Success = 0, Bad_InvalidState = 0x80AF0000} ErrorCodeEnum;


/* Cyclically process method object */
void UasXMethodOperate(struct UasXMethodType* Method, char* MethodName, fpFubCallerType fpFubCaller, void* FubInstance){
	if (MethodName == NULL) return;
	if (fpFubCaller == NULL) return;
	if (FubInstance == NULL) return;
	
	BOOL FirstCycleInState = (Method->State != Method->State_1);
	Method->State_1	= Method->State;
	
	switch (Method->State){
		case STATE_Init:
		case STATE_Error:
			Method->State	= STATE_CheckIsCalled;
			break;
		
		case STATE_CheckIsCalled:
			if (FirstCycleInState){
				Method->fbOperate.Execute	= FALSE;
				UaSrv_MethodOperate(&Method->fbOperate);
				strlcpy(Method->fbOperate.MethodName, MethodName, sizeof(Method->fbOperate.MethodName));
				Method->fbOperate.Execute	 = TRUE;
				Method->fbOperate.Action	 = UaMoa_CheckIsCalled;
			}
			UaSrv_MethodOperate(&Method->fbOperate);
			if (Method->fbOperate.Done){
				if (Method->fbOperate.IsCalled){
					Method->State	= STATE_IsCalled;
				}
				else {
					//remain in this state, call UaSrv_MethodOperate again
					Method->fbOperate.Execute	= FALSE;
					UaSrv_MethodOperate(&Method->fbOperate);
					Method->fbOperate.Execute	= TRUE;
				}
			}
			else if (Method->fbOperate.Error){
				Method->State	= STATE_Error;
			}
			break;
		
		case STATE_IsCalled:
			switch (fpFubCaller(FubInstance)){
				case ERR_FUB_BUSY:
					//do nothing, remain in state
					break;
				
				default:
					Method->State	= STATE_Finishing;
					break;
			}
			break;
		
		case STATE_Finishing:
			if (FirstCycleInState){
				Method->fbOperate.Execute	= FALSE;
				UaSrv_MethodOperate(&Method->fbOperate);
				Method->fbOperate.Execute	= TRUE;
				Method->fbOperate.Action	= UaMoa_Finished;
			}
			UaSrv_MethodOperate(&Method->fbOperate);
			if (Method->fbOperate.Done){
				Method->State	= STATE_CheckIsCalled;
			}
			else if (Method->fbOperate.Error){
				Method->State	= STATE_Error;
			}
			break;

		default:
			break;
	}
}


