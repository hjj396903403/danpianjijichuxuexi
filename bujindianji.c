#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

uchar Step_Tabel[]={0x40,0x20,0x10,0x08};
void delay(uint a)
{
while(a--);
}
void main()
{  uchar i;
uint j;
j=512;
while(j--)
{
 for(i=0;i<4;i++)
 {
 P0=Step_Tabel[i];
 delay(800);
 }
}
}