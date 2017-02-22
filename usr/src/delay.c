#include "includes.h"

/*
ʱ�ӣ�f=9M HZ Ƶ�ʣ�ÿ�����9M������
    ÿ�뾧����9M�Σ�һ��һ������
��ʱʱ��= ����ֵ*��һ��������ʱ��
һ������--��������ֵ�仯һ��
һ������ʱ��==���� T=1/f=1/9M (s)
��ʱ1s:������ֵ�仯9M��
��ʱ1ms: ---------9000��
��ʱ1us:----------9��
*/

u16 sys_ms=9000 ;//��ʾ��9MHZʱ������ʱ1ms����ļ���ֵ
u8  sys_us =9;//��ʾ��9MHZʱ������ʱ1us����ļ���ֵ

/*
������;Delay_init
������������
��������ֵ����
�������ܣ�ʵ�ֵδ�ʱ�ӵĳ�ʼ��
*/
void Delay_init(void)
{
	//������0ʱ�����ж�
	SysTick->CTRL &=~(1<<1);
	//ѡ���ⲿʱ�� 9M HZ
	SysTick->CTRL &=~(1<<2);
}

/*
������;Delay_ms
���������� u32 nms
         Ҫ��ʱ�ĺ�����
��������ֵ����
�������ܣ�ʵ�ֺ��뼶�����ʱ
*/
void Delay_ms(u32 nms)
{
	//������ļ���ֵд�뵽��װ�ؼĴ�����
	// ��ʽ����װ��ֵ=nms *��ʱ1ms����ļ���ֵ
  SysTick->LOAD =nms*sys_ms;
	//��յ�ǰֵ������
	SysTick->VAL =0;
	//�򿪵δ�ʱ��
	SysTick->CTRL |=(1<<0);
	//�ȴ�����������ֵ�ݼ���0
	while((SysTick->CTRL &(1<<16))==0);
	//�رյδ�ʱ��
	SysTick->CTRL &=~(1<<0);
}

/*
������;Delay_us
���������� u32 nus
         Ҫ��ʱ��΢����
��������ֵ����
�������ܣ�ʵ��΢�뼶�����ʱ
*/
void Delay_us(u32 nus)
{
	//������ļ���ֵд�뵽��װ�ؼĴ�����
	// ��ʽ����װ��ֵ=nus *��ʱ1us����ļ���ֵ
  SysTick->LOAD =nus*sys_us;
	//��յ�ǰֵ������
	SysTick->VAL =0;
	//�򿪵δ�ʱ��
	SysTick->CTRL |=(1<<0);
	//�ȴ�����������ֵ�ݼ���0
	while((SysTick->CTRL &(1<<16))==0);
	//�رյδ�ʱ��
	SysTick->CTRL &=~(1<<0);
}






