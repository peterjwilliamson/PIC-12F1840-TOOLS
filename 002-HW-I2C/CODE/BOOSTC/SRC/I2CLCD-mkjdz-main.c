/** \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *  
 * etc...
 */
 
 /** \page page1 Data Sheets
  \tableofcontents
    \section sec An example section
  This page contains the subsections \ref subsection1 and \ref subsection2.
  
  \subsection subsection1 The first subsection
  Text.
  \subsection subsection2 The second subsection
  More text.

  <ul>
  <li><a href="E:\29-I2C_LCD\DOCS\datasheet.pdf">Hitachi LCD</a></li>
  <li><a href="E:\29-I2C_LCD\DOCS\ADM1602K-NSA-FBS-3.3v.pdf">LCD Module</a></li>
  <li><a href="E:\29-I2C_LCD\DOCS\PCF8574_PCF8574A.pdf">PCF8574 - I2C I/O Expander</a></li>
  
 
</ul> 

*/




/*
        Project Name:    29-I2C LCD

        Program Name:    I2CLCD-mkjdz-main.c

 Program Description:    Programme to test the I2C LCD back pack from www.mkjdz.com
 						 ebay supplier e_goto

      Program Author:    Peter Williamson.

                Date:    29/05/2013

            Compiler:    BoostC Optimizing C Compiler Version 6.97 (for PIC16 architecture)
                     	   BoostLink Optimizing Linker Version 6.97
	                       http://www.sourceboost.com

Compile Instructions:    refer Boostc IDE

             Licence:    Creative Commons Attribution-ShareAlike 3.0 Unported License
                         http://creativecommons.org/licenses/by-sa/3.0/
                         See http://www.sourceboost.com  for Boostc licences.

Changes:

Date	     Author            Change

*/




#ifndef _PIC12F683
#warning "_PIC12F683 not defined"
#define _PIC12F683
#endif







//--- System Includes --------------------------------------
#include <system.h>

//--- Program Includes -------------------------------------
#include "INC\CPIC12F683.h"
//#include "INC\I2CLCD-MKJDZ.H"
#include "INC\LCD.h"
#include "INC\SWI2C.H"


//--- Device Config ----------------------------------------
// If using Sourceboost IDE then set target in settings > target



#warning "Main.c"

/*
#pragma CLOCK_FREQ 8000000 //!< Clock frequency in Hz

#pragma DATA _CONFIG, 	_FCMEN_OFF & 
						_IESO_OFF	& 
						_BOD_OFF	& 
						_CPD_OFF 	& 
						_CP_OFF 	&
						_MCLRE_OFF 	& 
						_PWRTE_OFF  & 	                          
						_WDT_OFF	&   
						_INTOSCIO;        
//						_INTRC_OSC_CLKOUT; 	// output clock to GP4 for speed test. 
											//For FOSC of 8mhz freq out on GP4 should be 8 / 4 = 2mhz
											
*/										
											
//rom char *picid = "12F638-002-009"; //!< Embeded ID string. 


/*--- Define Pins ------------------------------------------

                           +-----+
                           |     |
                      VDD->+1   8+<-VSS
                           |     |
                           |     |
    GP5/T1CKI/OSC1/CLKIN<->+2   7+<->GP0/AN0/CIN+/ICSPDAT/ULPWU (SCL green)
                           |     |
                           |     |    
GP4/AN3/T1G-/OSC2/CLKOUT<->+3   6+<->GP1/AN1/CIN-/VREF/ICSPCLK (SDA blue)
                           |     |
                           |     |
            GP3/MCLR-/VPP->+4   5+<->GP2/AN2/T0CKI/INT/COUT/CCP1 (Blinky led)
                           |     |
                           +-----+

Note Pin 4 is input only

*/

//--- Global Variables  ------------------------------------


//--- Interrupt handler 

void interrupt(void)
{
	asm nop;
}

//--- Start Main  I2CLCD-mkjdz-main ----------------------------------

void main(void)
{
//--- Local main Variable definitions

unsigned char acnt;
unsigned long icnt;

//--- Turn interrupts off while configuring

while (intcon.GIE)
	{
	intcon.GIE = 0; // Global interrupts disable
	}

//--- Include general configuation items

#include "INC\bc12f683-config-29.h"

//--- Tailor device configuration by overiding general configueartion items 
//    where necessary

// set pin IO direction. This is for 12F638

trisio.GP0 = DOUT; // SCL
trisio.GP1 = DOUT; // SDA
trisio.GP2 = DOUT;
trisio.GP3 = DIN;  // always an input
trisio.GP4 = DOUT;
trisio.GP5 = DOUT;

clear_bit(ansel,SCL);
clear_bit(ansel,SDA);

// start main while loop

i2c_init();


gpio.GP2 = 0;
LCD_init();
//LCD_cmd(display_shift_left);
LCD_printf("Ping Pong Poo Piddle Dong");
LCD_cmd(LCD_LINE2 );
LCD_printf("Dong Do Diddle");
icnt = 0;

delay_s(5);

LCD_cmd(LCD_LINE1 );
LCD_printf("a new test pello world");

delay_s(5);

LCD_cmd(LCD_LINE1 );
LCD_printf("Test . . . . . . ?");

delay_s(5);

LCD_cmd(LCD_LINE2 );
//LCD_printb(picid);

LCD_cmd(LCD_CLEAR);

delay_s(5);
 
while(1) 
{

icnt ++;
LCD_printn(icnt,SIZE,2,0,1);
LCD_printn(icnt,SIZE,0,1,2);
delay_ms(100);


} // end main while loop
} //--- end main -------------------------------------------



