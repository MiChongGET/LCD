#include "includes.h"



int main()
{
	int data;
  //u8 x=0;
	
	int x,y;
	
	//滴答时钟初始化
	Delay_init();
	//LED初始化
	LED_init();
	//LED全亮
	//蜂鸣器初始化
	BEEP_init();
	//按键初始化
	KEY_init();
  LED_ALLOFF();
  USART1_init(9600);
  USART1_NVIC_init();
	USART2_init(115200);
	//LCD屏初始化
	LCD_init();
	
	//奥运五环
	draw_circle(80,190,50,YELLOW);
	draw_circle(80,300,50,GREEN);
	draw_circle(150,140,50,GRAYBLUE);
	draw_circle(150,250,50,BLACK);
	draw_circle(150,360,50,RED);
	
	while(1)
	{ 
		
		//通过串口输入制定字符改变屏幕颜色
//			data = Receive_byte();
//			if(data == 'a'){
//			//BEEP(50000);
//			LCD_clear(0x6666);
//			}
//			else if(data == 'b'){
//				LCD_clear(0x8888);
//			}	
		
//		for(x=30;x<100;x++){
//			for(y=30;y<50;y++){
//			LCD_Display_Point(x,y,RED);
//				
//			}
//		}
		
		
	}
}
