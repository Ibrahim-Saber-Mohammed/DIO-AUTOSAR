

#include "Std_Types.h"
#include "Dio.h"
#include "Dio_Private.h"
#include "Dio_Cfg.h"

Dio_Channel_Configs_t DioChannels[DIO_CONFIGURED_CHANNELS] = {
                                                   {DIOA, PIN0, STD_IN},
                                                   {DIOB, PIN0, STD_OUT},
                                                   {DIOA, PIN7, STD_IN},
                                                   {DIOA, PIN5, STD_IN}
};

Dio_Port_Configs_t DioPorts[DIO_CONFIGURED_PORTS] = {
                                                     {DIOC, STD_OUT},
													 {DIOD, STD_IN}
};

