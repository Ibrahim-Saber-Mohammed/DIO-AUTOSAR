/*********************************************************************/
/****************** SWC : Dio.c             **************************/
/****************** Version: V00            **************************/
/****************** Date: Sep 21, 2022      **************************/
/****************** Author: ibrahim.saber   **************************/
/*********************************************************************/

/* Include Common Macros */
#include "Common_Macros.h"
/* Include  DIO Interface File*/
#include "Dio.h"
/* Include DIO Memory map file */
#include "Dio_MemMap.h"
/* Include Det File ->SATISFY [SWS_Dio_00194]*/
#include "Det.h"
/* Include SchM_Dio File */
#include "SchM_Dio.h"
/* Include DIO Registers */
#include "Dio_Regs.h"
/* Include the Configuration File of the DIO */
#include "Dio_Cfg.h"
/* Include DIO Private File */
#include "Dio_Private.h"

extern const Dio_Channel_Configs_t DioChannels[DIO_CONFIGURED_CHANNELS];
extern const Dio_Port_Configs_t DioPorts[DIO_CONFIGURED_PORTS];

/************************************************************************************
 * Service Name      : Dio_ReadChannel
 * Service ID[hex]   : 0x00
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : ChannelId - ID of DIO channel.
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : Dio_LevelType
 * Description       : Function to return the value of the specified DIO channel.
 ************************************************************************************/
/* Satisfy [SWS_Dio_00012] */

FUNC(Dio_LevelType, DIO_MEM_CLASS) Dio_ReadChannel (VAR(Dio_ChannelType, DIO_MEM_CLASS) ChannelId)
{
    Dio_LevelType Local_DioChannelValue = STD_LOW;
    if (ChannelId < DIO_CONFIGURED_CHANNELS)
    {
        switch(DioChannels[ChannelId].PortNum)
        {
        case DIOA:
            Local_DioChannelValue = GET_BIT(PINA, DioChannels[ChannelId].ChannelNum);
            break;
        case DIOB:
            Local_DioChannelValue = GET_BIT(PINB, DioChannels[ChannelId].ChannelNum);
            break;
        case DIOC:
            Local_DioChannelValue = GET_BIT(PINC, DioChannels[ChannelId].ChannelNum);
            break;
        case DIOD:
            Local_DioChannelValue = GET_BIT(PIND, DioChannels[ChannelId].ChannelNum);
            break;
        default:
            /* Report Error */
            break;
        }
    }
    else
    {
#if DIO_DEV_ERROR_DETECT == STD_ON

        /* Report an Error */
        Local_DioChannelValue = STD_LOW;

#endif
    }

    return Local_DioChannelValue;
}

/************************************************************************************
 * Service Name      : Dio_WriteChannel
 * Service ID[hex]   : 0x01
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : ChannelId - ID of DIO channel.
 *                       Level - Value to be written.
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Function to set a level of a channel.
 * SATISFY           : [SWS_Dio_00064]
 ************************************************************************************/

FUNC(void, DIO_MEM_CLASS) Dio_WriteChannel(VAR(Dio_ChannelType, DIO_MEM_CLASS) ChannelId , VAR(Dio_LevelType, DIO_MEM_CLASS) Level)
{
    volatile uint8_t * PortPtr = NULL;
    /* Check if valid Channel Id */
    if (ChannelId < DIO_CONFIGURED_CHANNELS)
    {
        if ( DioChannels[ChannelId].ChannelDirection == STD_OUT )
        {
            switch(DioChannels[ChannelId].PortNum)
            {
            case DIOA:
                PortPtr = &PORTA;
                break;
            case DIOB:
                PortPtr = &PORTB;
                break;
            case DIOC:
                PortPtr = &PORTC;
                break;
            case DIOD:
                PortPtr = &PORTD;
                break;
            default:
                /* No Action Required */
                break;
            }
            if(STD_HIGH == Level )
            {
                SET_BIT(*PortPtr,DioChannels[ChannelId].ChannelNum);
            }
            else if (STD_LOW == Level)
            {
                CLEAR_BIT(*PortPtr , DioChannels[ChannelId].ChannelNum);
            }
            else
            {
                /* No Action Required */
            }
        }
        else
        {
            /* No Action Required */
            /* SATISFY : [SWS_Dio_00070]            */
        }
    }
    else
    {
#if DIO_DEV_ERROR_DETECT == STD_ON
        /* Report an Error */

#endif
    }
}

FUNC(Dio_PortLevelType, DIO_MEM_CLASS) Dio_ReadPort ( VAR(Dio_PortType, DIO_MEM_CLASS) PortId)
{
    Dio_PortLevelType Local_DioReturnValue = STD_LOW;

    if( PortId < DIO_CONFIGURED_PORTS )
    {
        switch(DioPorts[PortId].PortNum)
        {
        case DIOA:
            Local_DioReturnValue = PINA;
            break;
        case DIOB:
            Local_DioReturnValue = PINB;
            break;
        case DIOC:
            Local_DioReturnValue = PINC;
            break;
        case DIOD:
            Local_DioReturnValue = PIND;
            break;
        default:
            /* No Action Required */
            break;
        }
    }
    else
    {
#if (DIO_DEV_ERROR_DETECT == STD_ON)

        /* Report Error */

#endif
    }
    return Local_DioReturnValue;
}

FUNC(void, DIO_MEM_CLASS) Dio_WritePort( VAR(Dio_PortType, DIO_MEM_CLASS) PortId , VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level)
{
    /* Check if valid Channel Id */
    if( PortId < DIO_CONFIGURED_PORTS )
    {
        if ( DioPorts[PortId].PortDirection == STD_OUT )
        {
            switch(DioPorts[PortId].PortNum)
            {
            case DIOA:
                PORTA = Level;
                break;
            case DIOB:
                PORTB = Level;
                break;
            case DIOC:
                PORTC = Level;
                break;
            case DIOD:
                PORTD = Level;
                break;
            default:
                /* No Action Required */
                break;
            }
        }
        else
        {
            /* No Action Required */
            /* SATISFY : [SWS_Dio_00070]            */
        }
    }
    else
    {
#if DIO_DEV_ERROR_DETECT == STD_ON
        /* Report an Error */
#endif
    }
}

/************************************************************************************
 * Service Name          : Dio_FlipChannel
 * Service ID[hex]       : 0x11
 * Sync/Async            : Synchronous
 * Reentrancy            : Reentrant
 * Parameters (in)       : ChannelId - ID of DIO channel.
 * Parameters (inout)    : None
 * Parameters (out)      : None
 * Return value          : Dio_LevelType
 * Description           : Function to flip the level of a channel and
                          return the level of the channel after flip.
 ************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
FUNC(Dio_LevelType, DIO_MEM_CLASS) Dio_FlipChannel( VAR( Dio_ChannelType, DIO_MEM_CLASS) ChannelId )
{
    Dio_LevelType Local_DioReturnResult = STD_LOW;
    volatile uint8_t * PortPtr = NULL;

    if ( ChannelId < DIO_CONFIGURED_CHANNELS )
    {
        switch(DioChannels[ChannelId].PortNum)
        {
        case DIOA:
            PortPtr = &PORTA;
            break;
        case DIOB:
            PortPtr = &PORTB;
            break;
        case DIOC:
            PortPtr = &PORTC;
            break;
        case DIOD:
            PortPtr = &PORTD;
            break;
        default:
            /* No Action Required */
            break;
        }

        if ( IS_BIT_SET(*PortPtr, DioChannels[ChannelId].ChannelNum))
        {
            CLEAR_BIT(*PortPtr, DioChannels[ChannelId].ChannelNum);
            Local_DioReturnResult = STD_LOW;
        }
        else
        {
            SET_BIT(*PortPtr, DioChannels[ChannelId].ChannelNum);
            SET_BIT(*PortPtr, DioChannels[ChannelId].ChannelNum);
            Local_DioReturnResult = STD_HIGH;
        }
    }
    else
    {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        /* Report Errors */
        Local_DioReturnResult = STD_LOW;
#endif
    }
    return Local_DioReturnResult;
}
#endif

FUNC(void, DIO_MEM_CLASS) Dio_MaskedWritePort( VAR(Dio_PortType, DIO_MEM_CLASS) PortId, VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level, VAR(Dio_PortLevelType, DIO_MEM_CLASS) Mask);

FUNC(Dio_PortLevelType, DIO_MEM_CLASS) Dio_ReadChannelGroup( P2CONST( Dio_ChannelGroupType, DIO_MEM_CLASS , DIO_PTR_CLASS) ChannelGroupIdPtr)
{
	Dio_PortLevelType Local_Dio_ChannelGroupValue = STD_LOW;
	volatile uint8_t * DioPortPtr = NULL; 
	if(ChannelGroupIdPtr != NULL)
	{
		switch(ChannelGroupIdPtr->port)
		{
			case DIOA:
			DioPortPtr = &PINA;
			break;
			case DIOB:
			DioPortPtr = &PINB;
			break;
			case DIOC:
			DioPortPtr = &PINC;
			break;
			case DIOD:
			DioPortPtr = &PIND;
			break;
			default:
			/* Report Error to DET */
			break;
		}
		Local_Dio_ChannelGroupValue = (*DioPortPtr&(ChannelGroupIdPtr->mask) >> ChannelGroupIdPtr->offset);
		
	}
	else
	{
		#if DIO_DEV_ERROR_DETECT == STD_ON
		/* Report Error to DET */

#endif
	}
	return Local_Dio_ChannelGroupValue;
}

FUNC(void, DIO_MEM_CLASS) Dio_WriteChannelGroup( P2CONST(Dio_ChannelGroupType, DIO_MEM_CLASS , DIO_PTR_CLASS )ChannelGroupIdPtr , VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level)
{
	if (NULL == ChannelGroupIdPtr)
	{
		switch(ChannelGroupIdPtr->port)
		{
			case DIOA:
				/* Clear the Bits First  */
				PORTA &=~(ChannelGroupIdPtr->mask);
				/* Write the value to the Channel Group */
				PORTA |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			case DIOB:
				/* Clear the Bits First  */
				PORTB &=~(ChannelGroupIdPtr->mask);
				/* Write the value to the Channel Group */
				PORTB |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			case DIOC:
				/* Clear the Bits First  */
				PORTC &=~(ChannelGroupIdPtr->mask);
				/* Write the value to the Channel Group */
				PORTC |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			case DIOD:
				/* Clear the Bits First  */
				PORTD &=~(ChannelGroupIdPtr->mask);
				/* Write the value to the Channel Group */
				PORTD |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			default:
			/* Report Error */
			break;
		}
	}
	else
	{
		#if DIO_DEV_ERROR_DETECT == STD_ON
		/* Report Error to Det */
#endif
	}
}


