/**********************************************************************
* Filename    : MPU6050RAW.c
* Description : Read data of MPU6050
* Author      : www.freenove.com
* modification: 2019/12/27
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <unistd.h>
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro;      //creat MPU6050 class object

int16_t ax, ay, az;     //store acceleration data
int16_t gx, gy, gz;     //store gyroscope data
int16_t lampotila;

void setup() {
    // initialize device
    printf("Initializing I2C devices...\n");
    accelgyro.initialize();     //initialize MPU6050

    // verify connection
    printf("Testing device connections...\n");
    printf(accelgyro.testConnection() ? "MPU6050 connection successful\n" : "MPU6050 connection failed\n");
    accelgyro.setTempSensorEnabled(true);
}

void loop() {
    // read accel/gyro values of MPU6050
    lampotila = accelgyro.getTemperature();
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // display accel/gyro x/y/z values
    printf("a/g: %6hd %6hd %6hd   %6hd %6hd %6hd\n",ax,ay,az,gx,gy,gz);
    printf("a/g: %.2f g %.2f g %.2f g   %.2f d/s %.2f d/s %.2f d/s \n\n",(float)ax/16384,(float)ay/16384,(float)az/16384,
        (float)gx/131,(float)gy/131,(float)gz/131);
    printf("Temperature: %.2f C\n\n", (float)lampotila/340 + 36.53);

    usleep(1000000); // Wait in microseconds
}

int main()
{
    setup();
    while(1){
        loop();
    }
    return 0;
}

