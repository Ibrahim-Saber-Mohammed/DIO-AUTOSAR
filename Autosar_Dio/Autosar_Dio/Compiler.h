 /*********************************************************************/
 /****************** SWC : Compiler.h        **************************/
 /****************** Version: V00            **************************/
 /****************** Date: Sep 21, 2022      **************************/
 /****************** Author: ibrahim.saber   **************************/
 /*********************************************************************/

#ifndef COMPILER_H_
#define COMPILER_H_

#define AUTOMATIC
#define STATIC          static

#define FUNC(returntype, memclass)                      returntype
#define VAR(vartype, memclass)                          vartype
#define CONST(consttype, memclass)                      consttype
#define P2FUNC(returntype, memclass, funcname)          returntype (* funcname)
#define P2CONST(ptrtype, memclass, ptrclass)            const ptrtype *
#define P2VAR(ptrtype, memclass, ptrclass)              ptrtype *
#define CONSTP2CONST(ptrtype, memclass, ptrclass)       const ptrtype * const
#define CONSTP2VAR(ptrtype, memclass, ptrclass)         ptrtype * const


#endif /* COMPILER_H_ */
