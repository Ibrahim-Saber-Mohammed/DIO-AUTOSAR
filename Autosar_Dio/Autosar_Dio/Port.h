/*
 * Port.h
 *
 * Created: 9/26/2022 3:54:13 PM
 *  Author: ibrahim.saber
 */ 


#ifndef PORT_H_
#define PORT_H_

/* Include Std_Types.h the Standard types [SWS_Port_00130]  */
#include "Std_Types.h"
/* Include Port_Cfg.h [SWS_Port_00130]  */
#include "Port_Cfg.h"

#define PORT_E_PARAM_PIN 
#define PORT_E_DIRECTION_UNCHANGEABLE
#define PORT_E_INIT_FAILED
#define PORT_E_PARAM_INVALID_MODE
#define PORT_E_MODE_UNCHANGEABLE
#define PORT_E_UNINIT
#define PORT_E_PARAM_POINTER

/* Data type for the symbolic name of a port pin */
typedef uint8_t Port_PinType;

/* Possible directions of a port pin. */
typedef enum
{
	/* Sets port pin as input */
	PORT_PIN_IN,
	/* Sets port pin as output */
	PORT_PIN_OUT
}Port_PinDirectionType;

/* Different port pin modes. */
typedef uint8_t Port_PinModeType;
typedef uint8_t Port_PinDirectoinType;
typedef uint8_t Port_PinDirectionChangeable;
typedef uint8_t Port_PinDefaultLevel;
typedef uint8_t Port_PinModeChangeable;

typedef struct{
	
}Port_PinsConfigurationsType;
/* Type of the external data structure containing the initialization data for this module. */
typedef struct{
	
}Port_ConfigType;

FUNC(void, PORT_MEM_CLASS) Port_Init(P2CONST(Port_ConfigType, PORT_MEM_CLASS, PORT_PTR_CLASS)ConfigPtr);

FUNC(void , PORT_MEM_CLASS) Port_SetPinDirection( VAR(Port_PinType, PORT_MEM_CLASS) Pin , VAR(Port_PinDirectionType , PORT_MEM_CLASS)Direction );
FUNC(void , PORT_MEM_CLASS) Port_RefreshPortDirection(void);/*FUNC(void , PORT_MEM_CLASS) Port_GetVersionInfo( P2VAR(Std_VersionInfoType , PORT_MEM_CLASS)versioninfo );*/

FUNC(void , PORT_MEM_CLASS) Port_SetPinMode(VAR(Port_PinType , PORT_MEM_CLASS)Pin , VAR(Port_PinModeType , PORT_MEM_CLASS)Mode);

#endif /* PORT_H_ */