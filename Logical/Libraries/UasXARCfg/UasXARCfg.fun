
{REDUND_ERROR} FUNCTION_BLOCK UasXCfgSetTimeZone (*OPC UA wrapper for CfgSetTimezone*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		MethodName : STRING[255] := 'SetTimeZone'; (*Name of the method. *)
		TimezoneID : UINT; (*ID of the timezone you would like to set.*)
	END_VAR
	VAR_OUTPUT
		Status : UINT; (*Error number (0 = no error)*)
	END_VAR
	VAR
		Method : UasXMethodType;
		fbSetTimeZone : CfgSetTimeZone;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK UasXCfgSetIPAddr (*OPC UA wrapper for CfgSetIPAddr*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		MethodName : STRING[255] := 'SetIPAddr'; (*Name of the method. *)
		Device : STRING[255] := 'IF2'; (*Device name (syntax: SL<x>.SS<y>.IF<z>)

Work with the following syntax when using a POWERLINK card: 
V1		SL<x>.SS<y>.IF<z>.PLKETH
V2		SL<x>.SS<y>.IF<z>.ETH*)
		IPAddress : STRING[15]; (*IP address
 
Valid range "1.0.0.1" - "247.255.255.255"*)
	END_VAR
	VAR_OUTPUT
		Status : UINT; (*Error number (0 = no error)*)
	END_VAR
	VAR
		Method : UasXMethodType;
		fbSetIPAddr : CfgSetIPAddr;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK UasXCfgSetNtpClient (*OPC UA wrapper for CfgSetNtpClient*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		MethodName : STRING[255] := 'SetNtpClient'; (*Name of the method. *)
		Start : BOOL; (*0: Stop client (cfgNTP_STOP)
1: Start client (cfgNTP_START)*)
		ServerAddress1 : STRING[15]; (*IP address of the 1st NTP server*)
		ServerAddress2 : STRING[15]; (*IP address of the 2nd NTP server*)
		ServerAddress3 : STRING[15]; (*IP address of the 3rd NTP server*)
		ServerAddress4 : STRING[15]; (*IP address of the 4th NTP server*)
	END_VAR
	VAR_OUTPUT
		Status : UINT; (*Error number (0 = no error)*)
	END_VAR
	VAR
		Method : UasXMethodType;
		fbSetNtpClient : CfgSetNtpClient;
	END_VAR
END_FUNCTION_BLOCK
