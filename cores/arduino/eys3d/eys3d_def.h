#ifndef _EYS3D_DEF_
#define _EYS3D_DEF_

#define EYS3D_CORE_VERSION_MAJOR    (0x01U) /*!< [31:24] major version */
#define EYS3D_CORE_VERSION_MINOR    (0x00U) /*!< [23:16] minor version */
#define EYS3D_CORE_VERSION_PATCH    (0x00U) /*!< [15:8]  patch version */
#define EYS3D_CORE_VERSION_EXTRA    (0x00U) /*!< [7:0]  extra version */

#define EYS3D_CORE_VERSION          ((EYS3D_CORE_VERSION_MAJOR << 24U)\
                                        |(EYS3D_CORE_VERSION_MINOR << 16U)\
                                        |(EYS3D_CORE_VERSION_PATCH << 8U )\
                                        |(EYS3D_CORE_VERSION_EXTRA))

#define USE_HAL_DRIVER


#include "ecv5546xx.h"

#ifndef F_CPU
  #define F_CPU SystemCoreClock
#endif



/**
 * Libc porting layers
 */
#if defined (  __GNUC__  ) /* GCC CS3 */
  #define WEAK __attribute__ ((weak))
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// weaked functions declaration
void SystemClock_Config(void);

void _Error_Handler(const char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif 
