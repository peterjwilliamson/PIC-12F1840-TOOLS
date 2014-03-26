#ifndef _CPIC12F683_H_
#define _CPIC12F683_H_


#ifndef _PIC12F683
#warning "_PIC12F683 not defined"
#define _PIC12F683
#endif



//--- Device Config ----------------------------------------
// If using Sourceboost IDE then set target in settings > target

#warning "CPIC12F683.h"


#pragma CLOCK_FREQ 8000000 //!< Clock frequency in Hz


#pragma DATA _CONFIG, _FCMEN_OFF & 
				_IESO_OFF	& 
				_BOD_OFF	& 
				_CPD_OFF 	& 
				_CP_OFF 	&
				_MCLRE_OFF 	& 
				_PWRTE_OFF  & 	                          
				_WDT_OFF	&   
				_INTOSCIO;        
//				_INTRC_OSC_CLKOUT; 	// output clock to GP4 for speed test. 
											//For FOSC of 8mhz freq out on GP4 should be 8 / 4 = 2mhz
											
										
										
rom char *picid = "12F638-002-009"; //!< Embeded ID string. 


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

#endif //_CPIC12F683_H_