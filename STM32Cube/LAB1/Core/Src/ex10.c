/*
 * ex6.c
 *
 *  Created on: Sep 21, 2025
 *      Author: cthanh
 */


#include "ex10.h"

int counter = 0,
	hour = 8,
	minute = 28,
	second = 8;

void init_ex10(){}

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


void clearAllClock()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14 , GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15 , GPIO_PIN_SET);
}

void setNumberOnClock(int num)
{
	HAL_GPIO_WritePin(GPIOA, LED[num], GPIO_PIN_RESET);
}

void clearNumberOnClock(int num)
{
	HAL_GPIO_WritePin(GPIOA, LED[num], GPIO_PIN_SET);
}



void ex10_run()
{
	if (second >= 60)
	{
		second = 0;
		minute++;
	}
	if (minute >= 60)
	{
		minute = 0;
		hour++;
	}
	if (hour >= 12)
	{
		hour = 0;
	}
	clearAllClock();
	setNumberOnClock(hour);
	setNumberOnClock(minute/5);
	setNumberOnClock(second/5);
	second++;

}

