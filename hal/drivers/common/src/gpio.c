/*
 * gpio.c
 *
 *  Created on: Sep. 7, 2022
 *      Author: Andrew Ingram
 */

#include <stm32f4xx.h>
#include <stdint.h>
#include <common.h>
#include <log.h>
#include <gpio.h>


CoreStatus halGpioInit(Gpio_t* pGpio)
{
	uint8_t i = 0;
	CoreStatus status = CoreStatus_ERROR;

	for (i = 0; i < MAX_GPIO_REGISTERS; i++)
	{
		if ((Gpio_t *)(GPIO_BASE + GPIO_REGISTERS_OFFSET*i) == pGpio)
		{
			RCC->AHB1ENR |= RCC_AHB1ENR_SET(i);
			status = CoreStatus_OK;
			break;
		}
	}

	if (status == CoreStatus_ERROR)
	{
		LOG(LogLevel_ERROR, "Invalid gpio: %p", pGpio);
	}
	return status;
}

CoreStatus halGpioPinModeSet(Gpio_t* gpio, uint32_t pin, GpioMode_t mode)
{
	CoreStatus status = CoreStatus_OK;

	if (pin < 16)
	{
		gpio->MODER  &= ~GPIO_MODER_MSK(pin);
		gpio->MODER  |= GPIO_MODER_SET(pin, mode);
	}
	else
	{
		LOG(LogLevel_ERROR, "Invalid pin: %d", pin);
		status = CoreStatus_ERROR;
	}

	return status;
}

CoreStatus halGpioPinOutputSet(Gpio_t* gpio, uint32_t pin, uint8_t val)
{
	if (val)
		gpio->ODR |= (1 << pin);
	else
		gpio->ODR &= ~(1 << pin);

	return CoreStatus_OK;
}


