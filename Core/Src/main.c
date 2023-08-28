#include <main.h>

/*	TO DO LIST

C	--> HCSR04 DRIVER
	--> IR DRIVER
C	--> MPU6050 IMU DRIVER	-> RAW DATA
	--> NEO-6M GPS DRIVER	-> RAW DATA

C	--> GPIO DRIVER
C	--> I2C DRIVER
	--> PWM DRIVER | OPEN LOOP MOTOR DRIVE (VIA MOSFET DRIVER)
	--> UART DRIVER
	--> CAN DRIVER

P	--> DMA DRIVER
X	--> FLASH DRIVER

P	--> HCSR04 CAPTURE COMPARE INTERRUPT DRIVER UPGRADE
P	--> HCSR04 MULTI DATA READING
	--> HCSR04 DATA FILTERING
	--> HCSR04 + MOTOR FUSION
	--> IMU + GPS SENSOR FUSION
	--> IMU EULER ANGLES | QUATERNIONS
	--> IMU EXTENDED KALMAN FILTER OR COMPEMENTARY FILTER
	--> MPU6050 OFFSET CONFIGS

	--> TIM2 DEACTIVATION

	C: COMPLETED
	P: IN PROGRESS
	X: CANCELLED
*/


uint8_t _distance;
MPU6050_Raw _MPU6050_Raw;


void PeripInit(void);
void SystemClock_Config(void);


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	PeripInit();
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);

	while (1)
	{
		HCSR04_Read();
		HAL_Delay(100);
//		MPU6050_Read_Accel(&hi2c1, &_MPU6050_Raw);
//		MPU6050_Read_Gyro(&hi2c1, &_MPU6050_Raw);
//		MPU6050_Read_Temp(&hi2c1, &_MPU6050_Raw);
	}
}

void PeripInit(void)
{
	GPIO_Init();
	TIM1_Init();
	I2C1_Init();
	MPU6050_Init(&hi2c1);
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

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	HCSR04_Distance(htim);
}
