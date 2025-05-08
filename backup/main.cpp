#include <U8g2lib.h>
#include <Wire.h>
#include <loopy_bitmap.h>
// Khởi tạo đối tượng U8g2 cho màn hình OLED SH1106
//U8G2_SH1106_128X64_NONAME_F_SW_I2C software giao tiếp I2C
//U8G2_SH1106_128X64_NONAME_F_HW_I2C Hardware giao tiếp I2C -> faster 
U8G2_SH1106_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A5, /* data=*/ A4, /* reset=*/ U8X8_PIN_NONE);


void setup() {
  // Khởi động thư viện U8g2
	u8g2.begin();
	u8g2.clearBuffer();
	u8g2.setFont( u8g2_font_roentgen_nbp_tf);
	u8g2.drawStr(10,40,"Hello Yen Nhi!!!") ;
	u8g2.sendBuffer();
	delay(500);
}
void draw_loopy_positive(int xpos){
	// Xóa màn hình
		u8g2.clearBuffer();
		// Hiển thị bitmap Loopy tại tọa độ (32, 0) để căn giữa (128-64)/2
		u8g2.drawXBMP(xpos, 0,68, 64, loopy_bitmap); // x,y,width, height, data
		// Gửi dữ liệu lên màn hình
		u8g2.sendBuffer();
}

void draw_loopy_negative(int xpos){
	// Xóa màn hình
	u8g2.clearBuffer();
	// Hiển thị bitmap Loopy tại tọa độ (32, 0) để căn giữa (128-64)/2
	u8g2.drawXBMP(60-xpos, 0,68, 64, loopy_bitmap); // x,y,width, height, data
	// Gửi dữ liệu lên màn hình
	u8g2.sendBuffer();
}

int xpos = 0;
int status = 0;
int step = 5;
void loop() {
	if(status == 0){
		xpos = xpos + step;
		draw_loopy_negative(xpos);
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