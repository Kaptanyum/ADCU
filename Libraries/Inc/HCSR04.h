#ifndef INC_HCSR04_H_
#define INC_HCSR04_H_


#include <stm32f4xx_hal.h>
#include <stdint.h>
#include <tim.h>

void HCSR04_DATA(TIM_HandleTypeDef *);
void HCSR04_Read (void);

extern uint16_t IC_Val1;
extern uint16_t IC_Val2;
extern uint16_t IC_Diff;
extern uint8_t Pol_Flg;
extern uint8_t Distance;


#endif /* INC_HCSR04_H_ */
