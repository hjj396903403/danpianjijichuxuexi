#include<reg52.h>
sbit beep=P1^5;
void delay(unsigned int a)
{
	unsigned int j;
	for(;a>0;a--)
	for(j=6245;j>0;j--);
}
void main()
{
beep=1;
delay(20);
beep=0;
delay(10);
while(1);

}