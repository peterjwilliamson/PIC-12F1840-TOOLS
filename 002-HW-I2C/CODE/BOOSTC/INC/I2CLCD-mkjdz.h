#ifndef __I2CLCD_MKJDZ_H__
#define __I2CLCD_MKJDZ_H__

#include <system.h>
//#include "i2c.h"

#define DIN	 1
#define DOUT 0

// I2C address of the PCF8574 on the mkjdz board.
// This is hard wired. PCB tracks will need to be cut
// and jumpered to change I2C address.

#define I2C_LCD_ADDR 0b01000000 	//PCF8574

// How the mkjdz board connects the PCF8754 to the LCD P0 - P7 are PCF8754 I/O bit Nos
// refer datasheet for pin Nos.

#define I2C_LCD_BL	7 // Backlight - P7
#define I2C_LCD_RS	6 // RS - P6 Register select. 0 = cmd write 1 = data write
#define I2C_LCD_RW	5 // RW - P5 Read/Write       0 = write to display 1 = read from display
#define I2C_LCD_EN	4 // EN - P4 Enable

// LCD is run in 4 bit mode
 
#define I2C_LCD_D7	3 // D7 - P3 LCD Data bit 7
#define I2C_LCD_D6	2 // D6 - P2 LCD Data bit 6
#define I2C_LCD_D5	1 // D5 - P1 LCD Data bit 5
#define I2C_LCD_D4	0 // D4 - P0 LCD Data bit 4


#define CMD  0x10 // for mkjdz board  was 0x20
#define DATA 0x50 // for mkjdz board was 0x30

/*

#define I2C_LCD_LINES    2
#define I2C_LCD_CHARS   16
#define I2C_LCD_EDELAY  10 //was 40


#define I2C_LCD_CLEAR      		0x01 // Clear Display
#define I2C_LCD_HOME       		0x02 // Cursor to Home position
#define I2C_LCD_CUR_ON     		0x0E // Switch Cursor ON
#define I2C_LCD_CUR_OFF    		0x0C // Switch Cursor OFF
#define I2C_LCD_CUR_BLINK  		0x0F // Cursor plus blink

#define I2C_LCD_DISP_ON    		0x0C // Display ON - 2 line mode
#define I2C_LCD_DISP_OFF   		0x08 // Display off
#define I2C_LCD_LINE1      		0x80 // Line 1 position 1
#define I2C_LCD_LINE2     		0xC0 // Line 2 position 1

#define set_dd_ram        		0x80 // Line 1 position 1
#define cursor_shift_right		0x14 // Move cursor right
#define cursor_shift_left 		0x10 // Move cursor left
#define display_shift_right		0x1C // Scroll display right
#define display_shift_left		0x18 // Scroll display left



#define LCD_cmd(cbyte)	(LCD_wbyte((cbyte),(CMD)))
#define LCD_data(cbyte)	(LCD_wbyte((cbyte),(DATA)))


void i2c_lcd_strobe(char lbyte);
void i2c_lcd_wbyte(char lbyte,char act);
void i2c_lcd_init(void);
void i2c_lcd_printf(const char* text);
void i2c_lcd_printb(char* lbuff);
void i2c_lcd_printn(long lnum,char cnum,char dp,char x,char y);
*/

#endif //__I2CLCD_MKJDZ_H__
