#include"Set_timer.h"





const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {2, 8, 0, 6};
void update7SEG(int index){
    switch (index){
        case 0:
            //Display the first 7SEG with led_buffer[0]
        	display7SEG(led_buffer[0]);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 1:
        	display7SEG(led_buffer[1]);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            //Display the second 7SEG with led_buffer[1]
            break;
        case 2:
        	display7SEG(led_buffer[2]);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            //Display the third 7SEG with led_buffer[2]
            break;
        case 3:
            //Display the forth 7SEG with led_buffer[3]
        	display7SEG(led_buffer[3]);
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}




int counter1 = 100;
int counter = 100;
int counter2=25;
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
			index_led=1;
			break;
		}
	}
}




