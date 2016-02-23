#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int 
uchar tabel[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,
~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
void main()
{
	EA=1;
	EX0=1;
	IT0=0;
	
	while(1);

}
void duan () interrupt 0
{	 
	uint j,i;
	i=0;
	while(1)
	{
	
	
	P0=tabel[i];
	i++;
	if(i==10)
	{ 
	i=0;
	}
	j=10000;
	while(j--);
	 }
}