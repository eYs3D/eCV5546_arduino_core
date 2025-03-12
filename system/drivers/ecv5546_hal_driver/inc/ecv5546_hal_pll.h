#ifndef __ecv5546_HAL_PLL_H
#define __ecv5546_HAL_PLL_H

#include "ecv5546xx.h"
#include "ecv5546_cm4.h"
#include "ecv5546_hal_def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __HAL_PLL_GET_SYS_CLK_SEL() (READ_BIT(MOON3_REG->sft_cfg[28], GENMASK(8, 6)) >> 6)

#define __HAL_PLL_GET_SYS_CM4_SEL() (READ_BIT(MOON3_REG->sft_cfg[27], GENMASK(4, 2)) >> 2)

uint32_t HAL_PLL_GetSystemFreq(void);
uint32_t HAL_PLL_GetCortexM4Freq(void);

#ifdef __cplusplus
}
#endif

#endif
