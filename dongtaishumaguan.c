#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar tabel1[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uchar tabel2[]={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70};
//sbit smegen=P2^3;
void delay(uint a)
{
	uchar j;
   for(;a>0;a--)
   for(j=110;j>0;j--);

}		   
void main()
{
uchar i;
while(1)
{
for(i=0;i<8;i++)
{
P2=tabel2[i];
//smegen=1;
P0=tabel1[i];
delay(5);
}
}
}