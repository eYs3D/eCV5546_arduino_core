#ifndef __eCV5546_HAL_WDG_H
#define __eCV5546_HAL_WDG_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "ecv5546_hal_def.h"
#include "ecv5546_cm4.h"
#include "ecv5546xx.h"

#define WDG_MAX_TICKS 		0xFFFFFFFFUL
#define IS_WDG_TICKS(X)		((X) <= WDG_MAX_TICKS)

typedef enum
{
	WDG_INTR	= 0x0U,
	WDG_RST		= 0x2U,
	WDG_INTR_RST	= 0x3U
} HAL_WDG_ModeTypeDef;

/**
  * @brief  IWDG Handle Structure definition
  */
typedef struct
{
	WDG_TypeDef		*Instance;	/*!< Register base address	 */
	uint8_t 		BitShift;	/*!< Enable the RBUS/WDG Reset	 */
	HAL_WDG_ModeTypeDef 	IrqMode;	/*!<  */
	IRQHandler_t		IrqHandle;
	uint32_t		IrqTicks;
	IRQn_Type		IrqNum;
} WDG_HandleTypeDef;

typedef void (*WdgCallbackFunc)(void);


#define WDG_CMD_UNLOCK		0xAB00		/*!< WDG conuter value can be written   */
#define WDG_CMD_LOCK		0xAB01		/*!< WDG conuter value can't be written */
#define WDG_CMD_STOP		0x3877		/*!< WDG conuter value will be kept     */
#define WDG_CMD_START		0x4A4B		/*!< WDG will be actived                */
#define WDG_CMD_CLRF		0x7482		/*!< Clear WDG interrupt flag           */
#define WDG_CMD_CNTMAX		0xDEAF		/*!< Set WDG conuter maximum value      */

void HAL_WDG_IRQHandler(void *arg);
void HAL_WDG_SetTimeout(WDG_HandleTypeDef *hwdg, uint32_t val_ms);
uint32_t HAL_WDG_GetTimeout(WDG_HandleTypeDef *hwdg);
void HAL_WDG_Stop(WDG_HandleTypeDef *hwdg);
void HAL_WDG_Start(WDG_HandleTypeDef *hwdg);

HAL_StatusTypeDef HAL_WDG_Init(WDG_HandleTypeDef *hwdg);

#ifdef __cplusplus
}
#endif

#endif
