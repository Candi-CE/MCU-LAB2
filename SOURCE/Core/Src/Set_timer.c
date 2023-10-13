#include"Set_timer.h"



int index_led = 0;
int counter1 = 100;
int counter = 100;
int counter2=25, flag = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	if(counter <= 0){
		counter = 100;
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
	counter1--;
	if(counter1 <= 0){
		counter1 = 100;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	counter2--;
	if(counter2 <= 0){
		counter2 = 25;
		switch(index_led){
		case 0:
			update7SEG(index_led);
			index_led = 1;
			break;
		case 1:
			update7SEG(index_led);
			index_led = 2;
			break;
		case 2:
			update7SEG(index_led);
			index_led = 3;
			break;
		case 3:
			update7SEG(index_led);
			index_led = 0;
			break;
		default:
			break;
		}
	}
}






