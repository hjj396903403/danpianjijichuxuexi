#include<reg52.h>
sbit led=P0^0;
void main()
{
	P0=0xfc;
}