
#include <bur/plctypes.h>
#include "UasX.h"

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
}

void _CYCLIC ProgramCyclic(void)
{
	UasXCfgSetTimeZone(&fbSetTimeZone);
	UasXCfgSetIPAddr(&fbSetIPAddr);
}

void _EXIT ProgramExit(void)
{
}

