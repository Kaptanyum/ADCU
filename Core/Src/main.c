#include <stm32f411xe.h>
#include <stm32f4xx_hal.h>
#include <stdint.h>
#include <main.h>

/*	TO DO LIST

	--> HCSR04 DRIVER
	--> IR DRIVER
	--> MPU6050 IMU DRIVER	-> RAW DATA
	--> NEO-6M GPS DRIVER	-> RAW DATA

	--> GPIO DRIVER
	--> I2C DRIVER
	--> PWM DRIVER
	--> UART DRIVER
	--> CAN DRIVER

	--> DMA DRIVER
	--> FLASH DRIVER

	--> HCSR04 CAPTURE COMPARE INTERRUPT DRIVER UPGRADE
	--> HCSR04 MULTI DATA READING
	--> HCSR04 + MOTOR FUSION
	--> IMU + GPS SENSOR FUSION

 * */

uint16_t distance;


void SystemClock_Config(void);


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	TIM2_Init();
	GPIO_Init();

	while (1)
	{
		distance = HCSR04_Read(&htim2);
	}
}


void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 16;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
	RCC_OscInitStruct.PLL.PLLQ = 4;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
}
