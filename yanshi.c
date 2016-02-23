#include<reg52.h>
#include"intrins.h"
void delay(char a)
{
	char i;
	for(i=0;i<a;i++)
	{
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
}
void main()
{
	delay(1);
}