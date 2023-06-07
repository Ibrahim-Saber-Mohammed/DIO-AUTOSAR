 /*********************************************************************/
 /****************** SWC : Common_Macros.h   **************************/
 /****************** Version: V00            **************************/
 /****************** Date: Sep 21, 2022      **************************/
 /****************** Author: ibrahim.saber   **************************/
 /*********************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    SET_BIT
[DESCRIPTION]  :    This macro is responsible for setting certain bit in a certain register
                    or variable
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable in which
                            the bit will set
                in  -> a_BIT:
                            This argument indicates the bit number which will set
------------------------------------------------------------------------------------------*/
#define SET_BIT(REG , BIT)  ( (REG)|=(1<<(BIT)))



#define GET_BIT(REG , BIT)   (( (REG)>>(BIT) ) &0x01)
/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    CLEAR_BIT
[DESCRIPTION]  :    This macro is responsible for clearing certain bit in a certain register
                    or variable
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable in which
                            the clear will be cleared
                in  -> a_BIT:
                            This argument indicates the bit number which will be cleared
------------------------------------------------------------------------------------------*/

#define CLEAR_BIT(REG , BIT)   (REG &= ~(1<<(BIT)))

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    TOGGLE_BIT
[DESCRIPTION]  :    This macro is responsible for toggling certain bit in a certain register
                    or variable
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable in which
                            the clear will be toggled
                in  -> a_BIT:
                            This argument indicates the bit number which will be toggled
------------------------------------------------------------------------------------------*/
#define TOGGLE_BIT(REG , BIT)   (REG ^= (1<<(BIT)))


/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    ROL_BIT
[DESCRIPTION]  :    This macro is responsible for rotating left certain register value with
                    specific number of rotates.
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable which will
                            will be rotated
                in  -> a_NUM:
                            This argument indicates the number of rotates
------------------------------------------------------------------------------------------*/
#define ROL(REG , NUM)      ( REG = (REG << (NUM))|(REG >> (8-(NUM)) ) )


/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    ROR_BIT
[DESCRIPTION]  :    This macro is responsible for rotating right certain register value with
                    specific number of rotates.
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable which will
                            will be rotated
                in  -> a_NUM:
                            This argument indicates the number of rotates
------------------------------------------------------------------------------------------*/
#define ROR(REG , NUM)      ( REG = (REG >> (NUM))|(REG << (8-(NUM)) ) )

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    IS_BIT_SET
[DESCRIPTION]  :    This macro is responsible for checking if a specific bit is set in any
                    register or not
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable in which the
                            bit will be checked the bit
                in  -> a_BIT:
                            This argument indicates the bit number
[Return]       :
                True if the bit is set

                False if the bit is clear
------------------------------------------------------------------------------------------*/
#define IS_BIT_SET(REG , BIT)   ( ( (REG)>>(BIT) )&1 )

/* -----------------------------------------------------------------------------------------
[MACRO NAME]   :    IS_BIT_CLEAR
[DESCRIPTION]  :    This macro is responsible for checking if a specific bit is clear in any
                    register or not
[Args]         :
                in  -> a_REG:
                            This argument indicates the register or the variable in which the
                            bit will be checked the bit
                in  -> a_BIT:
                            This argument indicates the bit number
[Return]       :
                True if the bit is clear

                False if the bit is set
------------------------------------------------------------------------------------------*/
#define IS_BIT_CLEAR(REG , BIT)  ( !( ( (REG)>>(BIT) ) &1) )

#endif /* COMMON_MACROS_H_ */
