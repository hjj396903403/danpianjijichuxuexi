#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char	
#define uint unsigned int
uchar code tabel[]={~0x3f,~0x06,~0x5b,~0x47,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
sbit sda=P2^1;
sbit scl=P2^0;
void delay1()
{
	uint a=30000;
	while(a--);
}
void init()
{
	sda=1;
	scl=1;
}
void delay()
{
	
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
void start()
{
	sda=1;
	scl=1;
	delay();
	sda=0;
	delay();
	scl=0;

}
void stop()
{
	sda=0;
	delay();
	scl=1;
	delay();
	sda=1;
	delay();
}
void ack()
{
	uchar i;
	sda=1;
	scl=1;
	delay();
	while(sda==1&&i<200)i++;
	scl=0;
	delay;
}
void noack()
{
	sda=1;
	scl=1;
	delay();
	scl=0;
	delay();
}
void write(uchar a)
{
	uchar i;
	scl=0;
	for(i=0;i<8;i++)
	{
		if((a&0x80)==0x80)
		{
		sda=1;
		}
		else
		{
		sda=0;
		}
		a=a<<1;
		delay();
		scl=1;
		delay();
		scl=0;
		delay();

	}
	sda=1;
	delay();
}
uchar read(uchar a)
{
	uchar i;
	scl=0;
	delay();
	sda=1;
	delay();
	for(i=0;i<8;i++)
	{
		scl=1;
		delay();
		a=a<<1;
		if(sda==1)
		{
		   a++;	
		}
		scl=0;
		delay;
	}
	return a;
}

void write_data(uchar add,uchar a)
{
    init();
	start();
	write(0xa0);
	ack;
	write(add);
	ack;
	write(a);
	ack;
	stop();	
}
uchar read_data(uchar add)
{
    uchar b;
	init();
	start();
	write(0xa0);
	ack;
	write(add);
	ack();
	start();
	write(0xa1);
	ack;
	read();
	b=read();
	noack;
	stop;
	return b;
}
void main()
{
/*	init();
	start();
	write(0xa0);
	ack;
	write(10);
	ack;
	write(0x55);
	ack;
	stop();

	delay1();
		
	init();
	start();
	write(0xa0);
	ack;
	write(10);
	ack();
	start();
	write(0xa1);
	ack;
	read();
	P0=read();
	noack;
	stop;
	while(1);  */
	uchar k;
	k=read_data(7);
	k=k%10;
	P0=tabel[k];
	k++;
	write_data(7,k);
}