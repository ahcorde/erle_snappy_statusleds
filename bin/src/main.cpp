#include "GPIO_BBB.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#define HIGH 1
#define LOW 0

#define HAL_GPIO_A_LED_PIN        61
#define HAL_GPIO_B_LED_PIN        48
#define HAL_GPIO_C_LED_PIN        117
#define HAL_GPIO_LED_ON           LOW
#define HAL_GPIO_OUTPUT 1
#define HAL_GPIO_LED_OFF          HIGH

int main(int argc, char* argv[])
{
	if(argc<4){
		std::cout << "Usage: erle_status_led G R B" << std::endl;
		return -1;
	}
	GPIO_BBB pin;
	pin.init();
	pin.pinMode(HAL_GPIO_A_LED_PIN, HAL_GPIO_OUTPUT);
	pin.pinMode(HAL_GPIO_B_LED_PIN, HAL_GPIO_OUTPUT);
	pin.pinMode(HAL_GPIO_C_LED_PIN, HAL_GPIO_OUTPUT);

	pin.write(HAL_GPIO_A_LED_PIN, atoi(argv[1])==0);
	pin.write(HAL_GPIO_B_LED_PIN, atoi(argv[3])==0);
	pin.write(HAL_GPIO_C_LED_PIN, atoi(argv[2])==0);
	return 0;
}
