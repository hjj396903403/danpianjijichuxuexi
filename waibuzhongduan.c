#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit led=P0^0;

uchar code tabel[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
void delay(uint a)
{
	uint j;
	for(;a>0;a--)
	for(j=6245;j>0;j--);
}
void main()
{
	uint i;
	EA=1;
	EX0=1;
	IT0=0;

	 while(1)
	 {
	for(i=0;i<10;i++)
	{
		P1=tabel[i];
		delay(20);
	}
	}
}
void duan () interrupt 0
{	P0=0x00;
	led=1;
	delay(20);
	led=0;
}