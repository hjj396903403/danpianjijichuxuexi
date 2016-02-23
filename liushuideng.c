#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
void delay(uint a)
{
uint j;
for(;a>0;a--)
for(j=6245;j>0;j--);
}
void main()
{
	unsigned char i,k;
	while(1)
	{	
	k=0x01;
	for(i=0;i<8;i++)
	{	
  	P0=k;
	delay(20);
 	k=_crol_(k,1);
    }
    }
}