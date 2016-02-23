#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit key1=P3^2;
sbit led=P0^0;
uchar code tabel1[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
uchar tabel2[]={0x08,0x18,0x28,0x38,0x48,0x58,0x68,0x78};
void delay(uint a)
{
	uint j;
	for(;a>0;a--)
	for(j=19;j>0;j--);
}
void main()
{
	uchar num;
	P3=0xff;
	while(1)
	{
	if(key1==0)
	{
		delay(400);				   //œ˚∂∂
		if(key1==0)
		{
			led=0;
			num=num+1;
			if(num==10)num=0;
			while(!key1);				//À… ÷ºÏ≤‚
		}
		delay(400);
		while(!key1);
	}
		else
		led=1;
		P1=tabel1[num];
	 }
}