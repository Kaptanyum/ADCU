/*	MPU6050 IMU SENSOR
	--> ACCEL SET TO +2g SCALE WITH 16384.0 LSB SENSTIVITY
	--> GYRO SET TO +250° WITH 131.0 LSB SENSTIVITY
	--> CALCULATION OF TEMPRATURE: VALUE / 340 + 36.53
  	*/

#include <mpu6050.h>

uint8_t check;
uint8_t data;

void MPU6050_Init(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, WHO_AM_I, 1, &check, 1, 100);

	data = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, PWR_MGMT_1, 1, &data, 1, 100);

	data = 0x07;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, SMPLRT_DIV, 1, &data, 1, 100);

	data = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, ACCEL_CONFIG, 1, &data, 1, 100);

	data = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, GYRO_CONFIG, 1, &data, 1, 100);
}

void MPU6050_ReadAccel(I2C_HandleTypeDef *hi2c, MPU6050_Raw *Struct)
{
	uint8_t raw_Data[6] = {0};

	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, ACCEL_XOUT_H, 1, raw_Data, 6, 100);

	Struct->Accel_X_Raw = (int16_t)(raw_Data[0] << 8 | raw_Data[1]);
	Struct->Ax = Struct->Accel_X_Raw / 16384.0;

	Struct->Accel_Y_Raw = (int16_t)(raw_Data[2] << 8 | raw_Data[3]);
	Struct->Ay = Struct->Accel_Y_Raw / 16384.0;

	Struct->Accel_Z_Raw = (int16_t)(raw_Data[4] << 8 | raw_Data[5]);
	Struct->Az = Struct->Accel_Z_Raw / 16384.0;
}

void MPU6050_ReadGyro(I2C_HandleTypeDef *hi2c, MPU6050_Raw *Struct)
{
	uint8_t raw_Data[6] = {0};

	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, GYRO_XOUT_H, 1, raw_Data, 6, 100);

	Struct->Gyro_X_Raw = (int16_t)(raw_Data[0] << 8 | raw_Data[1]);
	Struct->Gx = Struct->Gyro_X_Raw / 131.0;

	Struct->Gyro_Y_Raw = (int16_t)(raw_Data[2] << 8 | raw_Data[3]);
	Struct->Gy = Struct->Gyro_Y_Raw / 131.0;

	Struct->Gyro_Z_Raw = (int16_t)(raw_Data[4] << 8 | raw_Data[5]);
	Struct->Gz = Struct->Gyro_Z_Raw / 131.0;
}

void MPU6050_ReadTemp(I2C_HandleTypeDef *hi2c, MPU6050_Raw *Struct)
{
	uint8_t raw_Data[2] = {0};
	float temp_Data;

	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, TEMP_OUT_H, 1, raw_Data, 2, 100);

	Struct->Temp_Raw = (int16_t)(raw_Data[0] << 8 | raw_Data[1]);
	temp_Data = (float)((Struct->Temp_Raw / 340.0) + 36.53);
}

