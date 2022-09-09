/*
 * stm32f4xx.h
 *
 *  Created on: Sep. 8, 2022
 *      Author: Andrew Ingram
 */

#ifndef CMSIS_STM32F4XX_H_
#define CMSIS_STM32F4XX_H_

#include <stdint.h>

/* STRUCTURES */
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
} Gpio_t;

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t _RESERVED;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t _RESERVED2[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
} Rcc_t;

/* ENUMS */
typedef enum
{
	GpioMode_IN  = 0, // Input
	GpioMode_OUT = 1, // Output
	GpioMode_AF  = 2, // Alternate Function
	GpioMode_AN  = 3  // Analog
} GpioMode_t;

/* DEFINITIONS */
#define MAX_GPIO_REGISTERS    11
#define GPIO_REGISTERS_OFFSET 0x00400UL

/* Register Addresses */
#define PERIPH_BASE 0x40000000UL /* Peripheral base address */

#define APB1PERIPH_BASE       (PERIPH_BASE)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

#define CRC_BASE            (AHB1PERIPH_BASE + 0x03000UL)

#define RCC_BASE            (AHB1PERIPH_BASE + 0x03800UL)

#define GPIO_BASE		   (AHB1PERIPH_BASE)
#define GPIOA_BASE         (AHB1PERIPH_BASE + 0x00000UL)
#define GPIOB_BASE         (AHB1PERIPH_BASE + 0x00400UL)
#define GPIOC_BASE         (AHB1PERIPH_BASE + 0x00800UL)
#define GPIOD_BASE         (AHB1PERIPH_BASE + 0x00C00UL)
#define GPIOE_BASE         (AHB1PERIPH_BASE + 0x01000UL)
#define GPIOF_BASE         (AHB1PERIPH_BASE + 0x01400UL)
#define GPIOG_BASE         (AHB1PERIPH_BASE + 0x01800UL)
#define GPIOH_BASE         (AHB1PERIPH_BASE + 0x01C00UL)
#define GPIOI_BASE         (AHB1PERIPH_BASE + 0x02000UL)
#define GPIOJ_BASE         (AHB1PERIPH_BASE + 0x02400UL)
#define GPIOK_BASE         (AHB1PERIPH_BASE + 0x02800UL)

#define GPIOA ((Gpio_t *) GPIOA_BASE)
#define GPIOB ((Gpio_t *) GPIOB_BASE)
#define GPIOC ((Gpio_t *) GPIOC_BASE)
#define GPIOD ((Gpio_t *) GPIOD_BASE)
#define GPIOE ((Gpio_t *) GPIOE_BASE)
#define GPIOF ((Gpio_t *) GPIOF_BASE)
#define GPIOH ((Gpio_t *) GPIOH_BASE)
#define GPIOI ((Gpio_t *) GPIOI_BASE)
#define GPIOJ ((Gpio_t *) GPIOJ_BASE)
#define GPIOK ((Gpio_t *) GPIOH_BASE)

#define RCC  ((Rcc_t *) RCC_BASE)

#endif /* CMSIS_STM32F4XX_H_ */
