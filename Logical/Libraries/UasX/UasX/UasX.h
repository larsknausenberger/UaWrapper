#include <bur/plctypes.h>
#include <string.h>
#include <UasXTypes.h>

#define TRUE 1
#define FALSE 0

typedef UINT (*fpFubCallerType)(void* FubInstance);	// calls FUB and returns its status

/* macro to auto-generate fpFubCallerType function */
#define UASX_FUB_CALLER(FubType)\
static UINT FubType##Caller(void* FubInstance){\
	if (FubInstance == NULL) return UASX_ERR_NULL_POINTER;\
	struct FubType *fbInst = (struct FubType *)FubInstance;\
	FubType (fbInst);\
	return fbInst ->status;\
}

/* Cyclically process method object */
void UasXMethodOperate(struct UasXMethodType* Method, char* MethodName, fpFubCallerType fpFubCaller, void* FubInstance);
