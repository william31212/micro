#include <stdio.h>

void delay(unsigned int time)
{
	while (time > 0)
		time--;
}

int main(void)
{
	int i;
	for(i = 0; i < 10; ++i)
	{
		delay(50000);
		puts("2018 AndeSight MCU v2.1.1");
	}
	return 1;
}