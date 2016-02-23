#include<reg51.h>
void delay(void)
{
unsigned int a;
a=55000;
while(a--);
}
void main()
{

while(1)
{
P0=0xfe;
delay();

P0=0xff;
delay();
}
}