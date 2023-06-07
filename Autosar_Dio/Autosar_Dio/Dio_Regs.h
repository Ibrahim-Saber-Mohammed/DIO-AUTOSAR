 /*********************************************************************/
 /****************** SWC : Dio_Regs.h        **************************/
 /****************** Version: V00            **************************/
 /****************** Date: Sep 21, 2022      **************************/
 /****************** Author: ibrahim.saber   **************************/
 /*********************************************************************/


#ifndef DIO_REGS_H_
#define DIO_REGS_H_

#define PORTA         ( *( ( volatile uint8_t * )0X3B)  )
#define PINA          ( *( ( volatile uint8_t * )0X39)  )
#define DDRA          ( *( ( volatile uint8_t * )0X3A)  )
#define PORTB         ( *( ( volatile uint8_t * )0X38)  )
#define PINB          ( *( ( volatile uint8_t * )0X36)  )
#define DDRB          ( *( ( volatile uint8_t * )0X37)  )
#define PORTC         ( *( ( volatile uint8_t * )0X35)  )
#define PINC          ( *( ( volatile uint8_t * )0X33)  )
#define DDRC          ( *( ( volatile uint8_t * )0X34)  )
#define PORTD         ( *( ( volatile uint8_t * )0X32)  )
#define PIND          ( *( ( volatile uint8_t * )0X30)  )
#define DDRD          ( *( ( volatile uint8_t * )0X31)  )



#endif /* DIO_REGS_H_ */
