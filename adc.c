#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int 
uchar tabel1[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uchar tabel2[]={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70};
sbit scl=P2^1;
sbit sda=P2^0;
uchar d[3];
void delay1(uchar a)
{
	uchar j;
	for(;a>0;a--)
	for(j=19;j>0;j--);
}
void init()
{
	scl=1;
	sda=1;
}
void delay()
{
	_nop_();   	_nop_();	_nop_();	_nop_();	_nop_();	_nop_();
}
void start()
{
	sda=1;
	delay();
	scl=1;
	delay();
	sda=0;
	delay();
	scl=0;
	delay();
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
	scl=1;
	delay();
	while((sda==1)&&i<200)i++;
	sda=0;
	delay();
	scl=0;
	delay();
}
void noack()
{
	scl=1;
	delay();
	sda=1;
	delay();
	scl=0;
	delay();
}

void write_byte(uchar dat)
{
	uchar i;
	scl=0;
	for(i=0;i<8;i++)
	{
/*		scl=0;
		delay();
		sda=dat&0x80;				   //´íÎó´ð°¸
		dat=dat<<1;
		scl=1;	  			 */
		if(dat&0x80)
		sda=1;
		else
		sda=0;
		scl=1;
		delay();
		scl=0;
		delay();
		dat=dat<<1;			
	}
	sda=1;
	delay();
}
uchar read_byte()
{	
	uchar i,dat,k;
	scl=0;
	delay();
	sda=1;
	delay();
	
	for(i=0;i<8;i++)
	{
		scl=1;
		delay();
		dat=sda;
		k=(k<<1)|dat;
		scl=0;
		delay();
	}
	
	return k;
		
}
void channel(uchar a)
{
	start();
	write_byte(0x90);
	ack();
	write_byte(0x40|a);	
	noack();
	stop();
}
void write(uchar dat)
{
	start();
	write_byte(0x90);
	ack();
	write_byte(0x40);
	ack();
	write_byte(dat);
	noack();
	stop();
}
uchar read()
{
	uchar dat;
	start();
	write_byte(0x91);
	ack();
	dat=read_byte();
	noack();
	stop();
	return dat;
}
void display()
{
	uchar i;
	for(i=0;i<3;i++)
  	{	
		P2=tabel2[i];
		P0=tabel1[d[i]];
		delay1(10);
	}
}
void main()
{
/*	uchar a;								//ad×ª»»
	channel(0);
	while(1)
	{
	a=read();
	d[0]=a/100;
	d[1]=a/10%10;
	d[2]=a%10;
	display();		   	
	}						   */
	uchar dat;								//da×ª»»
	channel(0);
	while(1)
	{
		write(dat);
		dat++;
		delay1(100);
	}
}