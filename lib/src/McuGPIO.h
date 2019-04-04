/*
 * McuGPIO.h
 */

#ifndef McuGPIO_H_
#define McuGPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "fsl_gpio.h"
#include "McuLibconfig.h"
#include "McuGPIOconfig.h"
#include <stdbool.h>

typedef void *McuGPIO_Handle_t;

typedef struct {
  bool isInput;
  bool isLowOnInit;
  GPIO_Type *gpio;
#if McuLib_CONFIG_CPU_IS_KINETIS
  PORT_Type *port;
#elif McuLib_CONFIG_CPU_IS_LPC
  uint32_t port;
#endif
  uint32_t pin;
} McuGPIO_Config_t;

void McuGPIO_GetDefaultConfig(McuGPIO_Config_t *config);

McuGPIO_Handle_t McuGPIO_InitGPIO(McuGPIO_Config_t *config);

McuGPIO_Handle_t McuGPIO_DeinitGPIO(McuGPIO_Handle_t gpio);

void McuGPIO_SetInput(McuGPIO_Handle_t gpio);
void McuGPIO_SetOutput(McuGPIO_Handle_t gpio);
void McuGPIO_Low(McuGPIO_Handle_t gpio);
void McuGPIO_High(McuGPIO_Handle_t gpio);
void McuGPIO_Neg(McuGPIO_Handle_t gpio);
bool McuGPIO_Get(McuGPIO_Handle_t gpio);
void McuGPIO_Set(McuGPIO_Handle_t gpio, bool toLow);

/* driver initialization */
void McuGPIO_Init(void);

/* driver de-initialization */
void McuGPIO_Deinit(void);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* McuGPIO_H_ */
