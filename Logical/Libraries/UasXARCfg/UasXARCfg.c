
#include <bur/plctypes.h>
#include <UasX.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "UasXARCfg.h"
#ifdef __cplusplus
	};
#endif

#define TRUE 1
#define FALSE 0

UASX_FUB_CALLER(CfgSetTimeZone);
UASX_FUB_CALLER(CfgSetIPAddr);
UASX_FUB_CALLER(CfgSetNtpClient);

/* OPC UA wrapper for CfgSetTimezone */
void UasXCfgSetTimeZone(struct UasXCfgSetTimeZone* inst)
{
	inst->fbSetTimeZone.enable		= TRUE;
	inst->fbSetTimeZone.option		= cfgOPTION_NON_VOLATILE;
	inst->fbSetTimeZone.timezoneID	= inst->TimezoneID;
	
	UasXMethodOperate(&inst->Method, inst->MethodName, CfgSetTimeZoneCaller, &inst->fbSetTimeZone);
	
	inst->Status	= inst->fbSetTimeZone.status;
}


/* OPC UA wrapper for CfgSetIPAddr */
void UasXCfgSetIPAddr(struct UasXCfgSetIPAddr* inst)
{
	inst->fbSetIPAddr.enable	= TRUE;
	inst->fbSetIPAddr.Option	= cfgOPTION_NON_VOLATILE;
	inst->fbSetIPAddr.pDevice	= (UDINT)inst->Device;
	inst->fbSetIPAddr.pIPAddr	= (UDINT)inst->IPAddress;
	
	UasXMethodOperate(&inst->Method, inst->MethodName, CfgSetIPAddrCaller, &inst->fbSetIPAddr);
	
	inst->Status	= inst->fbSetIPAddr.status;
}


/* OPC UA wrapper for CfgSetNtpClient */
void UasXCfgSetNtpClient(struct UasXCfgSetNtpClient* inst)
{
	inst->fbSetNtpClient.enable				= TRUE;
	inst->fbSetNtpClient.option				= cfgOPTION_NON_VOLATILE;
	inst->fbSetNtpClient.pServerAddress1	= (UDINT)inst->ServerAddress1;
	inst->fbSetNtpClient.pServerAddress2	= (UDINT)inst->ServerAddress2;
	inst->fbSetNtpClient.pServerAddress3	= (UDINT)inst->ServerAddress3;
	inst->fbSetNtpClient.pServerAddress4	= (UDINT)inst->ServerAddress4;
	inst->fbSetNtpClient.start				= inst->Start;
	
	UasXMethodOperate(&inst->Method, inst->MethodName, CfgSetNtpClientCaller, &inst->fbSetNtpClient);
	
	inst->Status	= inst->fbSetNtpClient.status;
}
