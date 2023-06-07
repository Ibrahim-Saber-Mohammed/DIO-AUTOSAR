/*
 * Dio_Private.h
 *
 *  Created on: Sep 21, 2022
 *      Author: ibrahim.saber
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Definition of Macros represents Symbolic Names of the DIO Ports  */
#define DIOA   (uint8_t)0U
#define DIOB   (uint8_t)1U
#define DIOC   (uint8_t)2U
#define DIOD   (uint8_t)3U

#define PIN0    (uint8_t)0U
#define PIN1    (uint8_t)1U
#define PIN2    (uint8_t)2U
#define PIN3    (uint8_t)3U
#define PIN4    (uint8_t)4U
#define PIN5    (uint8_t)5U
#define PIN6    (uint8_t)6U
#define PIN7    (uint8_t)7U

/* type definition of the a structure represents the Configurations of a channel */
typedef struct{
	/* variable holds the Port channel is connected to  */
    Dio_PortType PortNum;
	/* the Channel number in the port  */
    Dio_ChannelType ChannelNum;
	/* the Channel Direction STD_IN/STD_OUT  */
    Dio_PinDirection ChannelDirection;
}Dio_Channel_Configs_t;

typedef struct{
    Dio_PortType PortNum;
    Dio_PortDirection PortDirection;
}Dio_Port_Configs_t;

#endif /* DIO_PRIVATE_H_ */
