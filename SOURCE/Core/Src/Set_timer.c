#include"Set_timer.h"









int counter1 = 100;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter1--;
	if(counter1 <= 0){
		counter1 = 100;
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
}
