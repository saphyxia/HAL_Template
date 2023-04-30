/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : bsp_gpio.c
  * @brief          : bsp gpio functions 
  * @author         : Yan Yuanbin
  * @date           : 2023/04/27
  * @version        : v1.0
  ******************************************************************************
  * @attention      : none
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_GPIO_H
#define BSP_GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Exported functions prototypes ---------------------------------------------*/
extern void BMI088_ACCEL_NS_L(void);
extern void BMI088_ACCEL_NS_H(void);
extern void BMI088_GYRO_NS_L(void);
extern void BMI088_GYRO_NS_H(void);

#endif //BSP_GPIO_H