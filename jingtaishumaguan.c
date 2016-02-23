#include<reg51.h>
unsigned char a[]={0x3f,0x06,0x5b};
void main()
{
P1=a[1];
}