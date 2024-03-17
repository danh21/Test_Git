



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
