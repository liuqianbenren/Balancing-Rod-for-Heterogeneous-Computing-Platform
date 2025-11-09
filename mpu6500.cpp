#include"fuction.h"



void  Absolute_Value(int16_t *X,int16_t *Y,int16_t *Z)//绝对值函数
{
 if (*X<0)
  {
    *X = 0 - (*X);
  }
  if (*Y<0)
  {
    *Y =0 - (*Y);
  }
  if (*Z<0)
  {
    *Z = 0 - (*Z);
  }
}

void mpu_write_byte(uint8_t reg,uint8_t value)//寄存器函数
{
  
  Wire.beginTransmission(0x68);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}
void all_mpu6500_write_byte(void)
{
  Wire.begin();
  mpu_write_byte(0x6b,0x00);
  delay(100);
  mpu_write_byte(0x1a,0x03);
  mpu_write_byte(0x1b,0x08);
  mpu_write_byte(0x1c,0x08);
  mpu_write_byte(0x1d,0x03);
}


void mpu6500_read(void)
{
  Wire.beginTransmission(0x68);
  Wire.write(0x3b);
  Wire.endTransmission();
  Wire.requestFrom(0x68,14);
  raw_accel_x = Wire.read()<<8|Wire.read();
  raw_accel_y = Wire.read()<<8|Wire.read();
  raw_accel_z = Wire.read()<<8|Wire.read();
  //temp = Wire.read()<<8|Wire.read();
  //raw_angle_x = Wire.read()<<8|Wire.read();
  //raw_angle_y = Wire.read()<<8|Wire.read();
  //raw_angle_z = Wire.read()<<8|Wire.read();
}




void the_fault_of_accel(void)//校准
{
  accel_fault_x = raw_accel_x;
  accel_fault_y = raw_accel_y;
  accel_fault_z = (raw_accel_z-8192);
  accel_fault_x += raw_accel_x;
  accel_fault_y += raw_accel_y;
  accel_fault_z += (raw_accel_z-8192);
  accel_fault_x/=2;
  accel_fault_y/=2;
  accel_fault_z/=2;
  delay(10);


}
  
  
void mpu6500_value(void)
{
    accel_x=(raw_accel_x-accel_fault_x)/8192.0;
    accel_y=(raw_accel_y-accel_fault_y)/8192.0;
    accel_z=(raw_accel_z-accel_fault_z)/8192.0;
 
}

  

   





