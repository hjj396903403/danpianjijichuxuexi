#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
uchar i,k;
uchar code tabel[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};

void main()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;	  //����ֵ
	TL0=(65536-50000)%256;
	EA=1;							 //�����ж��ܿ���
	ET0=1;							 //������ʱ���жϿ���
	TR0=1;							//������ʱ��
	while(1)
	{
		if(k==20)
		{
			k=0;
		P2=tabel[i];
		i++	 ;
		if(i==10) i=0;
		 }	
	}
}
 void timer () interrupt 1
 {
 	  TH0=(65536-50000)/256;	  //����ֵ
	TL0=(65536-50000)%256;
	k++;
 }