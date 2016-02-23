#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;
uchar tabel1[]=" www.t1xmcu.com ";
uchar tabel2[]="LCD1602 text ok!";
void delay(uint a)
{
	uint j;
	for(;a>0;a--)
	for(j=19;j>0;j--);
}
void write_com(uchar com)
{
	e=0;
	rs=0;
	rw=0;
    P0=com;
//	_nop_();
//	delay(10);
	e=1;
//	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_(); _nop_();_nop_();
	delay(20);
	e=0;

}
void write_data(uchar dat)
{
	 e=0;
	rs=1;
	rw=0;
	P0=dat;
//	_nop_();
//	delay(10);
	e=1;
//	_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	delay(20);
	e=0;
}
void init(void)
{
	delay(300);
	write_com(0x38);
	delay(100);
	write_com(0x38);
	delay(100);
	write_com(0x38);
	write_com(0x38);
	write_com(0x08);
	write_com(0x01);
	write_com(0x06);
	write_com(0x0c);


}
void main()
{
	 uchar i;
	 init();
     write_com(0x80);
	 for(i=0;i<16;i++)
	 {
	 	write_data(tabel1[i]);
		delay(10);
	 }
	 write_com(0x80+0x40);
	 for(i=0;i<16;i++)
	 {
	 	write_data(tabel2[i]);
		delay(10);
	 }
	 while(1);

}