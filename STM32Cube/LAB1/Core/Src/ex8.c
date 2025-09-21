/*
 * ex8.c
 *
 *  Created on: Sep 21, 2025
 *      Author: cthanh
 */


#include "ex8.h"


int counter = 0;

void init_exercise8(){}



uint16_t LED[12] =
{
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15

};

void setNumberOnClock(int num)
{

	HAL_GPIO_WritePin(GPIOA, LED[num], GPIO_PIN_RESET);
}

void ex8_run()
{

}
