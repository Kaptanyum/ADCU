#include <stm32f4xx_hal.h>
#include <tim.h>

TIM_HandleTypeDef htim2;

void TIM2_Init(void)
{
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};


	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 179;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 4294967295;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&htim2);


	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;


	HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig);
	HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);
}
