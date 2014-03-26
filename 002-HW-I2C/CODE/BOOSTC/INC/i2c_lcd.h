#ifndef _I2C_LCD_H_
#define _I2C_LCD_H_

#include <system.h>
#include "i2c.h"

#define CMD  0x20
#define DATA 0x30

#define I2C_LCD 0b01000100 	//PCF8574_02
#define I2C_LCD_LINES    2
#define I2C_LCD_CHARS   16
#define I2C_LCD_EDELAY  40

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

#define i2c_lcd_cmd(cbyte)	(i2c_lcd_wbyte((cbyte),(CMD)))
#define i2c_lcd_data(cbyte)	(i2c_lcd_wbyte((cbyte),(DATA)))

void i2c_lcd_strobe(char lbyte);
void i2c_lcd_wbyte(char lbyte,char act);
void i2c_lcd_init(void);
void i2c_lcd_printf(const char* text);
void i2c_lcd_printb(char* lbuff);
void i2c_lcd_printn(long lnum,char cnum,char dp,char x,char y);

#endif //_I2C_LCD_H_