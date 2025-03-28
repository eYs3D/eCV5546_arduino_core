#ifndef __eCV5546_HAL_STC_H__
#define __eCV5546_HAL_STC_H__

#include "ecv5546_cm4.h"
#include "ecv5546_hal_def.h"
#include "ecv5546xx.h"
#include "ecv5546_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STC_EXT_CLK_25M		25000000
#define STC_EXT_CLK_32K		32000
/* bit[14:0] stc_prescalel */
#define IS_STC_PRESCALE_VAL(X)	((X) < 32768UL)

typedef struct
{
	STC_TypeDef			 *Instance;     /*!< Register base address             */
	uint32_t			ClockSource;
	uint32_t 			Prescaler;
	uint32_t			ExtDiv;
} STC_HandleTypeDef;

HAL_StatusTypeDef HAL_STC_Init(STC_HandleTypeDef *Hstc);
HAL_StatusTypeDef HAL_STC_SetPrescaler(STC_HandleTypeDef *Hstc, uint32_t u32Prescaler);
HAL_StatusTypeDef HAL_STC_SetExtDiv(STC_HandleTypeDef *Hstc, uint32_t u32div);
uint64_t HAL_STC_GetCounter(STC_HandleTypeDef *Hstc);
uint32_t HAL_STC_GetPrescaler(STC_HandleTypeDef *Hstc);
uint32_t HAL_STC_GetExtDiv(STC_HandleTypeDef *Hstc);
uint32_t HAL_STC_GetClk(STC_TypeDef *STC_Instance);



#ifdef __cplusplus
}
#endif

#endif

