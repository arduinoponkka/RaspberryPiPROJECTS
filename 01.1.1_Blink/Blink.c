/**********************************************************************
* Filename    : Blink.c
* Description : Basic usage of GPIO. Let led blink.
* auther      : www.freenove.com
* modification: 2019/12/26
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define  ledPin    0	//define the led pin number

int main(void)
{
	printf("Ohjelma alkaa ... \n");

	wiringPiSetup();	//Initialize wiringPi.

	pinMode(ledPin, OUTPUT);//Set the pin mode
	printf("Kaytetaan pin%d\n",ledPin);	//Output information on terminal
	while(1){
		digitalWrite(ledPin, HIGH);  //Make GPIO output HIGH level
		printf("led on paalla >>>\n");		//Output information on terminal
		delay(3000);						//Wait for 1 second
		digitalWrite(ledPin, LOW);  //Make GPIO output LOW level
		printf("led on pois paalta <<<\n");		//Output information on terminal
		delay(150);						//Wait for 1 second
	}
	return 0;
}

