#include <mpu6050.h>

uint8_t data;
uint8_t check;

void MPU6050_Init(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, WHO_AM_I, 1, &check, 1, 100);

	data = 0;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, PWR_MGMT_1, 1, &data, 1, 100);
}
