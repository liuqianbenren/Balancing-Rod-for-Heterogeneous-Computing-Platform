#ifndef FUCTION_H
#define FUCTION_H
#include<Wire.h>
#include<Arduino.h>

#define  AIN1 13
#define  AIN2 12
#define  PWMA 11
#define  BIN1 10
#define  BIN2 9
#define  PWMB 8


extern int8_t speed;
void define_pinmode(void);
void A_motor_forward(void);
void A_motor_forward(void);
void A_motor_backward(void);
void B_motor_backward(void);
void A_motor_break(void);
void B_motor_break(void);
void B_motor_stop(void);
void A_motor_stop(void);
void move_straight(void);
void move_right(void);
void move_left(void);
void command_stop(void);
void Emergency_brake(void);

extern int16_t raw_accel_x,raw_accel_y,raw_accel_z;
extern int8_t accel_fault_x,accel_fault_y,accel_fault_z;
extern float accel_x,accel_y,accel_z;
//extern int16_t raw_angle_x,raw_angle_y,raw_angle_z;
//extern int16_t temp;
//extern int8_t angle_fault_x,angle_fault_y,angle_fault_z;
//extern float angle_x,angle_y,angle_z;

void mpu_write_byte(uint8_t reg,uint8_t value);
void all_mpu6500_write_byte(void);
void mpu6500_read(void);
void  Absolute_Value(int16_t *X,int16_t *Y,int16_t *Z);
void the_fault_of_accel(void);
void mpu6500_value(void);

//上面部分是是传感器相关函数以及全局变量











#endif
