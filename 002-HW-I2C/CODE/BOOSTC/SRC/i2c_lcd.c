#include "INC\I2CLCD-MKJDZ.H"
#include "INC\I2C.H"
#include "INC\ltostr.h"

void i2c_lcd_strobe(char lbyte) // strobe the enable pin hi -> lo
{

	set_bit(lbyte,I2C_LCD_EN);
	i2c_write_byte(I2C_LCD_ADDR,lbyte);
	delay_10us(I2C_LCD_EDELAY);
	clear_bit(lbyte,I2C_LCD_EN);
	i2c_write_byte(I2C_LCD_ADDR,lbyte);
	delay_10us(I2C_LCD_EDELAY);
}
 

void i2c_lcd_wbyte(char lbyte,char act)


{
char ltemp;

// act = 0x10 E hi R/S 0 -> cmd
//       0x50 E hi R/S 1 -> data

// hi nibble	
	ltemp = lbyte;
	lbyte &= 0b11110000;
	lbyte >>= 4;
	lbyte += act;
	i2c_write_byte(I2C_LCD_ADDR,lbyte);
	i2c_lcd_strobe(lbyte);
	//delay_ms(5);
//lo nibble	
	lbyte = ltemp;
	lbyte &= 0b00001111;
	lbyte += act;
	i2c_write_byte(I2C_LCD_ADDR,lbyte);
	i2c_lcd_strobe(lbyte);
	//delay_ms(5);
}	

/*

Init LCD as connected to mkjdz backpack

When the LCD display powers up, it is configured as follows:

1. Display clear
2. Function set: 
   DL = 1; 8-bit interface data 
    N = 0; 1-line display 
    F = 0; 5x8 dot character font 
3. Display on/off control: 
    D = 0; Display off 
    C = 0; Cursor off 
    B = 0; Blinking off 
4. Entry mode set: 
    I/D = 1; Increment by 1
    S   = 0; No shift 

*/
void i2c_lcd_init(void)
{
// This init follows the Hitachi datasheet page 46 - Fig 24 4Bit Interface
//                    D7 D6 D5 D4     
i2c_lcd_cmd(0x03); //  0  0  1  1  Function set to 8 bit interface
i2c_lcd_cmd(0x03); //  0  0  1  1  Function set to 8 bit interface
i2c_lcd_cmd(0x03); //  0  0  1  1  Function set to 8 bit interface
i2c_lcd_cmd(0x02); //  0  0  1  0  Function set to 4 bit interface
i2c_lcd_cmd(0x28);
i2c_lcd_cmd(0x0C);

}

void i2c_lcd_printf(const char* text)
{
    char i = 0;
    while(text[i] != 0)
		{
        i2c_lcd_data(text[i++]);
        }
        
}


void i2c_lcd_printb(char* lbuff)
{
char i = 0;
    for (i=0;i<I2C_LCD_CHARS;i++)
		{
		if (lbuff[i] == 0x20) return;
		i2c_lcd_data(lbuff[i]+ 48);
        }

}


void i2c_lcd_printn(long lnum,char cnum,char dp,char x,char y)
//lnum - long to print
//cnum - number of digits to print
//x    - column
//y    - row
{
char i;
char row;
char dbuff[SIZE];

		ltostr(lnum,cnum,dp,dbuff);
		switch(y)
			{
			case 1:
				{
				row = I2C_LCD_LINE1;
				break;
				}
			case 2:
				{
				row = I2C_LCD_LINE2;
				break;
				}
			default:
				{
				row = I2C_LCD_LINE1;
				}
			}
		
		// set start row + column
		i2c_lcd_cmd(row + x);

		i = 0;
		while(dbuff[i] != 0)
			{
			i2c_lcd_data(dbuff[i++]);
			}
}

void i2c_lcd_gotoxy(char x,char y)
// x= column y = row
{

}

