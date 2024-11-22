#include "stm32f10x.h"

void delay (int time);

int main(void) 
{
  RCC->APB2ENR |= 0x08;

  GPIOB->CRL &= ~(0xfffff);
  GPIOB->CRL |= 0x33333;

  while (1)
	{
		GPIOB->ODR |= 0x01;
		delay (500);
		GPIOB->ODR &= 0x00;
		delay (500);
		GPIOB->ODR |= 0x02;
		delay (500);
		GPIOB->ODR &= 0x00;
		delay (500);
		GPIOB->ODR |= 0x04;
		delay (500);
		GPIOB->ODR &= 0x00;
		delay (500);
		GPIOB->ODR |= 0x08;
		delay (500);
		GPIOB->ODR &= 0x00;
		delay (500);
		GPIOB->ODR |= 0x010;
		delay (500);
		GPIOB->ODR &= 0x00;
		delay (500);
  }
}

void delay (int time)
{
  for (int i = 0; i < time * 1000; i++) 
	{
    __NOP();
  }
}