#ifndef _PIC12F683
#warning "_PIC12F683 not defined"
#define _PIC12F683
#endif

//--- System Includes --------------------------------------

#include <system.h>

//--- Program Includes -------------------------------------

#include "INC\I2CLCD-MKJDZ.H"

//using namespace std;


//--- Device Config ----------------------------------------
// If using Sourceboost IDE then set target in settings > target


#pragma CLOCK_FREQ 8000000 //!< Clock frequency in Hz

#pragma DATA _CONFIG,
				_FCMEN_OFF	& // description
				_IESO_OFF	& 
				_BOD_OFF	& 
				_CPD_OFF 	& 
				_CP_OFF 	&
				_MCLRE_OFF 	& 
				_PWRTE_OFF  & 	                          
				_WDT_OFF	&   
				_INTOSCIO;    
				    
class I2CLCD
{
	private:
		unsigned char _DeviceAddr;
		unsigned char _Flags;
    
	public:
	
		I2CLCD(unsigned char DevAddr); //constructor
		
		unsigned char GetAddr();
		unsigned char TestAddr();
		unsigned char GetFlags();
		
		void SetAddr(unsigned char DevAddr);
		void SetFlags(unsigned char FlagVal);
		
			
};

I2CLCD::I2CLCD(unsigned char DevAddr)
	{
	SetAddr(DevAddr);
	TestAddr();
	SetFlags(0xFE);
	}

void I2CLCD::SetAddr(unsigned char DevAddr)
	{
	_DeviceAddr = DevAddr;
	};
	
	
unsigned char I2CLCD::GetAddr()
	{
	return (_DeviceAddr);
	}
	
	
void I2CLCD::SetFlags(unsigned char FlagVal)
	{
	_Flags = FlagVal;

	};	
unsigned char I2CLCD::GetFlags()
	{
	return (_Flags);
	}	
	
unsigned char I2CLCD::TestAddr()
	{
	unsigned char xx;
	xx = GetAddr();
	return xx;
	};	


											
void interrupt(void)
{
	asm nop;
}

//--- Start Main  ----------------------------------

void main(void)
{
//--- Local main Variable definitions
int x = 0;
unsigned char y = 0x01;
unsigned char Taddr01 = 0x00;
unsigned char Taddr02 = 0x00;

I2CLCD LCD01(0x20);
I2CLCD LCD02(0x40);

//LCD01.SetFlags(0xf0);

y = LCD01.GetFlags();

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

Taddr01 = LCD01.GetAddr();
Taddr02 = LCD02.GetAddr();

// start main while loop
while(1) 
{
	
	gpio.GP0 = 1;
	//delay_s(1);
	gpio.GP0 = 0;
	//delay_s(1);
	x++;
		
} // end main while loop
} //--- end main -------------------------------------------
											