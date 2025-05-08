#include <loopy_bitmap.h>

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
