#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar key;
uchar key1;
uchar key2;
uchar tabel[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
void delay(uint a)
{
	uint j;
	for(;a>0;a--)
	for(j=19;j>0;j--);
}
void main()

{	 	
	while(1)
	{
		P3=0xf0;
		key=P3;

		if(key!=0xf0)
		{
			delay(10);
			if(key!=0xf0)
			{
			key1=key|0x0f;
			P3=key1;
			key2=P3;
			key2=key2&0x0f;
			key1=key1&0xf0;
			key=key1+key2;
			}
	}
	switch(key)
	{
		
		case(0xee):	P1=tabel[0]; break;
		case(0xde):	P1=tabel[1];break;
		case(0xbe):	P1=tabel[2];break;
		case(0x7e):	P1=tabel[3];break;
		case(0xed):	P1=tabel[4];break;
		case(0xdd):	P1=tabel[5];break;
		case(0xbd):	P1=tabel[6];break;
		case(0x7d):	P1=tabel[7];break;
		case(0xeb):	P1=tabel[8];break;
		case(0xdb):	P1=tabel[9];break;
		case(0xbb):	P1=tabel[10];break;
		case(0x7b):	P1=tabel[11];break;
		case(0xe7):	P1=tabel[12];break;
		case(0xd7):	P1=tabel[13];break;
		case(0xb7):	P1=tabel[14];break;
		case(0x77):	P1=tabel[15];break;


	}
	}
}
	