#include<stdint.h>
#include<stm32f401xe.h>
#include "Timer.h"
#include "SystemClock.h"



#define led_on 		GPIOD->ODR |= 1<<13
#define led_off		GPIOD->ODR &= ~(1<<13)
#define led_is_off	(GPIOD->ODR & 1<<13) == 0

#define toggle_led 					led_is_off ? led_on : (led_off)
//#define button_is_pressed			(GPIOA->IDR & 1) == 1
//#define waiting_button_is_released 	while (button_is_pressed)



void GPIO_init(void);



int main()
{
	SystemClock_config();
	GPIO_init();
	Timer1_init();

	while(1)
	{
		toggle_led;
		delay_ms(500);
	}
}



void GPIO_init(void)
{
	RCC->AHB1ENR |= (1<<3);		// IO port D clock enable

	GPIOD->MODER |= (1<<26);	// General purpose output mode
	GPIOD->MODER &= ~(1<<27);

	GPIOD->OTYPER &= ~(1<<13);	// Output push-pull (reset state)
}
