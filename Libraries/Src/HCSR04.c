/* HCSR04 DISTANCE MEASUREMENT SENSOR */

#include <hcsr04.h>

static TIM_HandleTypeDef *_htim;

uint16_t HCSR04_val1 = 0;
uint16_t HCSR04_val2 = 0;
uint16_t HCSR04_distance = 0;

uint16_t HCSR04_Read(TIM_HandleTypeDef *htim)
{
	_htim = htim;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

	while(!(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)));
	HAL_TIM_Base_Start(_htim);
	HCSR04_val1 = __HAL_TIM_GET_COUNTER(_htim);
	while((HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)));
	HCSR04_val2 = __HAL_TIM_GET_COUNTER(_htim);
	HCSR04_distance = (((HCSR04_val2 - HCSR04_val1)*2) / 58);
	HAL_TIM_Base_Stop(_htim);
	HAL_Delay(60);

	return HCSR04_distance;
}

/*
	HCSR GPIO SETTINGS
	==================
-->TRIG OUTPUT| ECHO INPUT
|1|T -> PB5   | E -> PB4
|2|T -> PB3   | E -> PA15
|3|T -> PB11  | E -> PB10
|4|T -> PB2   | E -> PB1
|5|T -> PA4   | E -> PA3
|6|T -> PC15  | E -> PC14

*/
