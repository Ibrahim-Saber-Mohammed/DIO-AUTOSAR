/**********************************************************************/
 /****************** SWC : Platform_Types.h  **************************/
 /****************** Version: V00            **************************/
 /****************** Date: Sep 21, 2022      **************************/
 /****************** Author: ibrahim.saber   **************************/
 /*********************************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_



typedef unsigned char uint8_t;              /*            0   .. 255                      */
typedef signed char   sint8_t;              /*           -128 .. 127                      */
typedef unsigned short uint16_t;            /*            0   .. 65535                    */
typedef signed short sint16_t;              /*            -32768 .. +32767                */
typedef unsigned long uint32_t;             /*            0 .. 4294967295                 */
typedef signed long sint32_t;               /*           -2147483648 .. +2147483647       */
typedef unsigned long long uint64_t;        /*           0..18446744073709551615          */
typedef signed long long sint64_t;
typedef float   float32;
typedef double  float64;

#endif /* PLATFORM_TYPES_H_ */
