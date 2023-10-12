#include"Set_timer.h"









int counter1 = 100;
int counter2=50, flag =1;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter1--;
	if(counter1 <= 0){
		counter1 = 100;
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
	counter2--;
	if(counter2 <= 0){
		counter2 = 50;
		switch(flag){
		case 1:
			flag = 2;
			display7SEG(1);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			break;
		case 2:
			flag = 1;
			display7SEG(2);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			break;
		default:
			flag=1;
			break;
		}
	}
}
