/* HCSR04 DISTANCE MEASUREMENT SENSOR */

#include <hcsr04.h>

uint16_t IC_Val1 = 0;
uint16_t IC_Val2 = 0;
uint16_t IC_Diff = 0;
uint8_t Pol_Flg = 0;
uint8_t Distance  = 0;

void HCSR04_Distance(TIM_HandleTypeDef* htim){
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			if (Pol_Flg == 0)
			{
				IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
				Pol_Flg = 1;

				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
			}

			else if (Pol_Flg == 1)
			{
				IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
				__HAL_TIM_SET_COUNTER(htim, 0);

				if (IC_Val2 > IC_Val1)
				{
					IC_Diff = IC_Val2-IC_Val1;
				}

				else if (IC_Val1 > IC_Val2)
				{
					IC_Diff = (0xffff - IC_Val1) + IC_Val2;
				}

				Distance = IC_Diff * 0.034 / 2;
				Pol_Flg = 0;

				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
				__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
			}
		}
}

void HCSR04_Read(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
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
