/*
 * ex3.c
 *
 *  Created on: Sep 17, 2025
 *      Author: cthanh
 */

#include"ex3.h"

int state_horizontal = RED;
int state_vertical = GREEN;
int counter_horizontal = 0,
	counter_vertical = 0;


void init_ex3(){}

void red_on_horizontal(){

	// DEN GIAO THONG TRAI
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET); // yellow led off

	// DEN GIAO THONG PHAI
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET); // yellow led off
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET); // green led off

}

void green_on_horizontal(){

	// DEN GIAO THONG TRAI
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET); // yellow led off

	// DEN GIAO THONG PHAI
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET); // yellow led off
}

void yellow_on_horizontal(){

	// DEN GIAO THONG TRAI
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET); // yellow led on

	// DEN GIAO THONG PHAI
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET); // yellow led on
}


void red_on_vertical(){

	// DEN GIAO THONG TREN
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET); // green led off

	// DEN GIAO THONG DUOI
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET); // yellow led off

}

void green_on_vertical(){

	// DEN GIAO THONG TREN
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET); // yellow led off

	// DEN GIAO THONG DUOI
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET); // yellow led off
}

void yellow_on_vertical(){

	// DEN GIAO THONG TREN
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET); // yellow led on

	// DEN GIAO THONG DUOI
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET); // yellow led on
}

void ex3_run()
{
	switch(state_horizontal)
	{
		case RED:
			red_on_horizontal();
			counter_horizontal++;
			if (counter_horizontal >= 5)
			{
				state_horizontal = GREEN;
				counter_horizontal = 0;
			}
			break;
		case GREEN:
			green_on_horizontal();
			counter_horizontal++;
			if (counter_horizontal >= 3)
			{
				state_horizontal = YELLOW;
				counter_horizontal = 0;
			}
			break;
		case YELLOW:
			yellow_on_horizontal();
			counter_horizontal++;
			if (counter_horizontal >= 2)
			{
				state_horizontal = RED;
				counter_horizontal = 0;
			}
			break;
		default:
			break;

	}


	switch(state_vertical)
		{
			case RED:
				red_on_vertical();
				counter_vertical++;
				if (counter_vertical >= 5)
				{
					state_vertical = GREEN;
					counter_vertical = 0;
				}
				break;
			case GREEN:
				green_on_vertical();
				counter_vertical++;
				if (counter_vertical >= 3)
				{
					state_vertical = YELLOW;
					counter_vertical = 0;
				}
				break;
			case YELLOW:
				yellow_on_vertical();
				counter_vertical++;
				if (counter_vertical >= 2)
				{
					state_vertical = RED;
					counter_vertical = 0;
				}
				break;
			default:
				break;
		}
}


