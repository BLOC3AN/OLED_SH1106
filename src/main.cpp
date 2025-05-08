#include <U8g2lib.h>
#include <Wire.h>
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ A5, /* data=*/ A4, /* reset=*/ U8X8_PIN_NONE);
// custom bitmap
#include "loopy_fish.h"
#include "animation_loopy.h"
#include "animation_rabbit_loopy.h"


const char* text ="Hello NhiNyy";
int text_length = strlen(text);
int text_width = text_length * 6; // 6 pixel per character
const int text_x = 5; // Vị trí x ban đầu của văn bản
int text_y =40; // Vị trí y của văn bản


void setup() {
  // Khởi động thư viện U8g2
	u8g2.begin();
	u8g2.clearBuffer();
	u8g2.setFont(u8g2_font_profont17_tr);
	u8g2.drawStr(text_x, text_y, text); 
	u8g2.sendBuffer();
	delay(3000);
	// draw_loopy_fish_positive(10);
	// delay(3000);
}


int xpos = 0;
int status = 0;
int step = 2;
void loop() {
	if(status == 0){
		xpos = xpos + step;
		// draw_loopy_negative(xpos);
		draw_rabbit_loopy_negative(xpos);
		if(xpos >= 60){
			status = 1;
			xpos= 0;}
	}
	if(status == 1){
		xpos = xpos + step;
		draw_loopy_positive(xpos);
		if(xpos>=60){status = 0;xpos=0;}
	}
	// delay(200); //ms
}	