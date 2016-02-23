#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar tabel1[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f};
uchar tabel2[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void delay(uint a)
{
	uint j;
	for(;a>0;a--)
	for(j=19;j>0;j--);
}
void main()
{
	uchar i;
	while(1)
	{
	for(i=0;i<8;i++)
	{
		P0=tabel1[i];
		P1=tabel2[i];
		delay(10);
	}
	}
}