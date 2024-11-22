#include "stm32f10x.h"

void delay (int time);

int main(void) 
{
  RCC->APB2ENR |= 0x0c;

  GPIOB->CRL &= ~0xfffff;
  GPIOB->CRL |= 0x33333;
	
	GPIOA->CRH &= ~0xf;
	GPIOA->CRH |= 0x4;
	
	int led_binary = 0;
	int i = 0;

  while (1)
	{
		if ((GPIOA->IDR & 0x100) && led_binary <= 0x1f)
		{
			i = 0;
			GPIOB->ODR = (GPIOB->ODR & ~0x1F) | led_binary;
      led_binary++;
      delay(200);
			if (led_binary > 0x1f) led_binary = 0;
		}
		else
		{
			led_binary = 0;
			GPIOB->ODR = (1 << i);
      delay(200);
      GPIOB->ODR &= ~0x1F;
      delay(200);
			i++;
			if (i >= 5) i = 0;
		}
  }
}

void delay (int time)
{
  for (int i = 0; i < time * 1000; i++) 
	{
    __NOP();
  }
}