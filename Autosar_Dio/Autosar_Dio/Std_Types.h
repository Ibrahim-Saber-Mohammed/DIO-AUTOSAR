/**********************************************************************/
 /****************** SWC : Std_Types.h       **************************/
 /****************** Version: V00            **************************/
 /****************** Date: Sep 21, 2022      **************************/
 /****************** Author: ibrahim.saber   **************************/
 /*********************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Include the Platform types */
#include "Platform_Types.h"
/* Include Compiler.h */
#include "Compiler.h"

typedef uint8_t   Std_ReturnType;
typedef uint8_t   Std_ErrorState;
#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */
#define STD_IN          0x01U       /* Standard ON */
#define STD_OUT         0x00U       /* Standard OFF */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */

#define NULL            ( (void*)0)

#endif /* STD_TYPES_H_ */
