/*
 * Port.c
 *
 * Created: 9/26/2022 3:54:26 PM
 *  Author: ibrahim.saber
 */ 

/* Include the Port.h file [SWS_Port_00131]  */
#include "Port.h"
/* Include the Port_MemMap.h [SWS_Port_00131]  */
#include "Port_MemMap.h"
/*Include Det.h  [SWS_Port_00131]  */
#include "Det.h"
/* Include SchM_Port.h [SWS_Port_00131]  */
#include "SchM_Port.h"
/* Include Port_Cbk.h. [SWS_Port_00204] */
#include "Port_Cbk.h."

FUNC(void, PORT_MEM_CLASS) Port_Init(P2CONST(Port_ConfigType, PORT_MEM_CLASS, PORT_PTR_CLASS)ConfigPtr);

FUNC(void , PORT_MEM_CLASS) Port_SetPinDirection( VAR(Port_PinType, PORT_MEM_CLASS) Pin , VAR(Port_PinDirectionType , PORT_MEM_CLASS)Direction );
FUNC(void , PORT_MEM_CLASS) Port_RefreshPortDirection(void);/*FUNC(void , PORT_MEM_CLASS) Port_GetVersionInfo( P2VAR(Std_VersionInfoType , PORT_MEM_CLASS)versioninfo );*/

FUNC(void , PORT_MEM_CLASS) Port_SetPinMode(VAR(Port_PinType , PORT_MEM_CLASS)Pin , VAR(Port_PinModeType , PORT_MEM_CLASS)Mode);
