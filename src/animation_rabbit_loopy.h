#include "rabbit_loopy_bitmap.h"


// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ A5, /* data=*/ A4, /* reset=*/ U8X8_PIN_NONE);


// 54x64
void draw_rabbit_loopy_positive(int xpos){
	// Xóa màn hình
    u8g2.clearBuffer();
    // Hiển thị bitmap Loopy tại tọa độ (32, 0) để căn giữa (128-64)/2
    u8g2.drawXBMP(xpos, 0,54, 64, rabbit_loopy); // x,y,width, height, data
    // Gửi dữ liệu lên màn hình
    u8g2.sendBuffer();
}

void draw_rabbit_loopy_negative(int xpos){
	// Xóa màn hình
	u8g2.clearBuffer();
	// Hiển thị bitmap Loopy tại tọa độ (32, 0) để căn giữa (128-64)/2
	u8g2.drawXBMP(60-xpos, 0,54, 64, rabbit_loopy); // x,y,width, height, data
	// Gửi dữ liệu lên màn hình
	u8g2.sendBuffer();
}
