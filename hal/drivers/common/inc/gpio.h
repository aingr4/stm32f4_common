/*
 * gpio.h
 *
 *  Created on: Sep. 7, 2022
 *      Author: Andrew Ingram
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include <stdint.h>
#include <common.h>

/* MACROS */

#define GPIO_MODER_MSK(pin)        (3 << ((pin) << 1))
#define GPIO_MODER_SET(pin, mode)  (mode << ((pin) << 1))

#define RCC_AHB1ENR_SET(gpio)  (1 << gpio)


/* FUNCTIONS */
CoreStatus halGpioInit(Gpio_t* gpio);
CoreStatus halGpioPinModeSet(Gpio_t* gpio, uint32_t pin, GpioMode_t mode);
CoreStatus halGpioPinOutputSet(Gpio_t* gpio, uint32_t pin, uint8_t val);

#endif /* HAL_GPIO_H_ */
