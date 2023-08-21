#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_


#include <stm32f4xx_hal.h>

#define WHO_AM_I 0x75
#define PWR_MGMT_1 0x6B
#define SMPLRT_DIV 0x19
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_XOUT_H 0x3B	// --> BEGINNING OF THE ACCEL RAW DATA
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define TEMP_OUT_H 0x41		// --> BEGINNING OF THE TEMP RAW DATA
#define TEMP_OUT_L 0x42
#define GYRO_XOUT_H 0x43	// --> BEGINNING OF THE GYRO RAW DATA
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48
#define MPU6050_ADDR 0xD0

typedef struct MPU6050_Raw
{
	int16_t Accel_X_Raw;
	int16_t Accel_Y_Raw;
	int16_t Accel_Z_Raw;
	float Ax;
	float Ay;
	float Az;

	int16_t Gyro_X_Raw;
	int16_t Gyro_Y_Raw;
	int16_t Gyro_Z_Raw;
	float Gx;
	float Gy;
	float Gz;

	int16_t Temp_Raw;
} MPU6050_Raw;

extern uint8_t check;
extern uint8_t data;

void MPU6050_Init(I2C_HandleTypeDef *hi2c);
void MPU6050_ReadGyro(I2C_HandleTypeDef *hi2c, MPU6050_Raw *Struct);
void MPU6050_ReadAccel(I2C_HandleTypeDef *hi2c, MPU6050_Raw *Struct);
void MPU6050_ReadTemp(I2C_HandleTypeDef *hi2c, MPU6050_Raw *Struct);


#endif /* INC_MPU6050_H_ */
