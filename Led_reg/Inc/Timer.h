/*
 * Timer.h
 *
 *  Created on: Mar 3, 2024
 *      Author: danh21
 */

#ifndef TIMER_H_
#define TIMER_H_



#define f_PCLK		16000000
#define T_timer		0.001		// ms
#define AutoReload	65535		// Auto-reload value



/*
 * Initialize Timer 1
 * */
void Timer1_init()
{
	uint32_t F_timer, prescaler;

	// F_timer = f_PCLK / (PSC + 1)
	F_timer = 1 / T_timer;
	prescaler = f_PCLK / F_timer - 1;

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; 		// TIM1 clock enable

	TIM1->PSC |= prescaler;

	TIM1->ARR = AutoReload;

	TIM1->CR1 |= TIM_CR1_CEN;					// Counter enable
	TIM1->CR1 &= ~(1<<4);						// Counter used as up counter
}



/*
 * delay by ms
 * */
void delay_ms(int ms)
{
	TIM1->CNT = 0;
	while (TIM1->CNT < ms);
}



#endif /* TIMER_H_ */
