#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit DSIO=P3^4;
sbit rst=P3^5;
sbit sclk=P3^6;

uchar code tabel1[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x40};
uchar code tabel2[]={0x08,0x18,0x28,0x38,0x48,0x58,0x68,0x78};
uchar time_data[]={13,12,11,17,16,05,23};
uchar write_add[]={0x8c,0x8a,0x88,0x86,0x84,0x82,0x80};
uchar read_add[]={0x8d,0x8b,0x89,0x87,0x85,0x83,0x81};
uchar d[8];

void delay(uint a)
{
	uint j;
	for(;a>0;a--)
	for(j=19;j>0;j--);
}		
void write_byte(uchar dat)
{
	uchar i;
	for(i=0;i<8;i++)
	{
		sclk=0;
		DSIO=dat&0x01;
		dat=dat>>1;
		sclk=1;
	}
}	
void write(uchar add,uchar dat)
{
	sclk=0;
	_nop_();
	rst=0;			  //必须加上这个rst=0
	_nop_();
	rst=1;
	_nop_();
	write_byte(add);
	write_byte(dat);
	rst=0;
							 //可以不管sclk
}
uchar read(uchar add)
{
	uchar i,value;
	sclk=0;
	_nop_();
	rst=0;
	_nop_();
	rst=1;
	_nop_();
	write_byte(add);
	for(i=0;i<8;i++)
	{
		sclk=1; 					//读是下降沿
		value=value>>1;					 
		sclk=0;		
		if(DSIO)					//先读到IO再判断
		{				   
		value=value|0x80;
		}		 		
/*		sclk=1;					   //此方法错误
		_nop_();
		sclk=0;
		
		value=(value>>1)|DSIO;		 */        
	}
	rst=0;
	_nop_();
//	sclk=0;				 //可以不管sclk
	_nop_();
	DSIO=0;				 //一定要把IO口置为0
	return value;
} 
void set_rtc()
{
	uchar i,j;
	for(i=0;i<7;i++)
	{
		j=time_data[i]/10;
		time_data[i]=time_data[i]%10;
		time_data[i]=time_data[i]+j*16;
	}
	write(0x8e,0x00);
	for(i=0;i<7;i++)
	{
		write(write_add[i],time_data[i]);
	}
	
	write(0x8e,0x80);
}
void read_rtc(void)
{
	uchar i;
	for(i=0;i<7;i++)
	{
	   time_data[i]=read(read_add[i]);
    }
}

void pros()
{
	d[7]=time_data[6]%16;
	d[6]=time_data[6]/16;
	d[5]=16;
	d[4]=time_data[5]%16;
	d[3]=time_data[5]/16;
	d[2]=16;
	d[1]=time_data[4]%16;
	d[0]=time_data[4]/16;
	
}

void display()
{
	uchar i;


	for(i=0;i<8;i++)
	{
		P0=tabel1[d[i]];
		P2=tabel2[i];
		delay(10);
	}
}
void main()
{
	
	set_rtc();
	while(1)
	{
		read_rtc();
		pros();
		display();
	}

}