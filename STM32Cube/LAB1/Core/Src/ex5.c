/*
 * ex5.c
 *
 *  Created on: Sep 19, 2025
 *      Author: cthanh
 */

#include"ex5.h"


int state_horizontal = RED,
	state_vertical = GREEN,
	counter_horizontal = 5,
	counter_vertical = 3;


void init_exercise5(){}

void red_on_horizontal()
{
	// DEN GIAO THONG TRAI
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET); // yellow led off

	// DEN GIAO THONG PHAI
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET); // yellow led off
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET); // green led off

}

void green_on_horizontal()
{
	// DEN GIAO THONG TRAI
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET); // yellow led off

	// DEN GIAO THONG PHAI
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET); // yellow led off
}

void yellow_on_horizontal()
{
	// DEN GIAO THONG TRAI
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET); // yellow led on

	// DEN GIAO THONG PHAI
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET); // yellow led on
}


void red_on_vertical()
{
	// DEN GIAO THONG TREN
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET); // green led off

	// DEN GIAO THONG DUOI
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET); // red led on
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET); // yellow led off

}

void green_on_vertical()
{
	// DEN GIAO THONG TREN
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET); // yellow led off

	// DEN GIAO THONG DUOI
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET); // green led on
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET); // yellow led off
}

void yellow_on_vertical()
{
	// DEN GIAO THONG TREN
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET); // yellow led on

	// DEN GIAO THONG DUOI
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET); // red led off
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET); // green led off
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET); // yellow led on
}


char seg[10] =
{
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10
};

void display_number1(int number)
{
	char code = seg[number];

	// Kiem tra bit tuong ung SEG cua so can hien thi neu = 1 thi SEG OFF
	HAL_GPIO_WritePin(SEG_A1_GPIO_Port, SEG_A1_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_B1_GPIO_Port, SEG_B1_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_C1_GPIO_Port, SEG_C1_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_D1_GPIO_Port, SEG_D1_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_E1_GPIO_Port, SEG_E1_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_F1_GPIO_Port, SEG_F1_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_G1_GPIO_Port, SEG_G1_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void display_number2(int number)
{
	char code = seg[number];

	// Kiem tra bit tuong ung SEG cua so can hien thi neu = 1 thi SEG OFF
	HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}






void ex5_run()
{
	switch(state_horizontal)
	{
		case RED:
			red_on_horizontal();
			counter_horizontal--;
			display_number1(counter_horizontal);
			if (counter_horizontal <= 0)
			{
				state_horizontal = GREEN;
				counter_horizontal = 3;
			}
			break;
		case GREEN:
			green_on_horizontal();
			counter_horizontal--;
			display_number1(counter_horizontal);
			if (counter_horizontal <= 0)
			{
				state_horizontal = YELLOW;
				counter_horizontal = 2;
			}
			break;
		case YELLOW:
			yellow_on_horizontal();
			counter_horizontal--;
			display_number1(counter_horizontal);
			if (counter_horizontal <= 0)
			{
				state_horizontal = RED;
				counter_horizontal = 5;
			}
			break;
		default:
			break;

	}


	switch(state_vertical)
	{
		case RED:
			red_on_vertical();
			counter_vertical--;
			display_number2(counter_vertical);
			if (counter_vertical <= 0)
			{
				state_vertical = GREEN;
				counter_vertical = 3;
			}
			break;
		case GREEN:
			green_on_vertical();
			counter_vertical--;
			display_number2(counter_vertical);
			if (counter_vertical <= 0)
			{
				state_vertical = YELLOW;
				counter_vertical = 2;
			}
			break;
		case YELLOW:
			yellow_on_vertical();
			counter_vertical--;
			display_number2(counter_vertical);
			if (counter_vertical <= 0)
			{
				state_vertical = RED;
				counter_vertical = 5;
			}
			break;
		default:
				break;
		}
}

