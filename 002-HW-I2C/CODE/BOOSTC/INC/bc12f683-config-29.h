#ifndef _BC12F683CONFIG_H_
#define _BC12F683CONFIG_H_

//Configures all registers related to the PIC's hardware

  option_reg = 0xb11111111; 
  /*  
  OPTION REGISTER
		 11111111
                 1          bit 7 GPPU: GPIO Pull-up Enable bit
                                  1 = GPIO pull-ups are disabled
                                  0 = GPIO pull-ups are enabled by individual port latch values in WPU register
                  1         bit 6 INTEDG: Interrupt Edge Select bit
                                  1 = Interrupt on rising edge of GP2/INT pin
                                  0 = Interrupt on falling edge of GP2/INT pin
                   1        bit 5 T0CS: TMR0 Clock Source Select bit
                                  1 = Transition on GP2/T0CKI pin
                                  0 = Internal instruction cycle clock (CLKOUT)
                    1       bit 4 T0SE: TMR0 Source Edge Select bit
                                  1 = Increment on high-to-low transition on GP2/T0CKI pin
                                  0 = Increment on low-to-high transition on GP2/T0CKI pin
                     1      bit 3 PSA: Prescaler Assignment bit
                                  1 = Prescaler is assigned to the WDT
                                  0 = Prescaler is assigned to the Timer0 module
                      111   bit 2-0 PS<2:0>: Prescaler Rate Select bits
                                  bit        TMR0       WDT (1)
                                  000        1:2        1:1
                                  001        1:4        1:2
                                  010        1:8        1:4
                                  011        1:16       1:8
                                  100        1:32       1:16
                                  101        1:64       1:32
                                  110        1:128      1:64
                                  111        1:256      1:128
                                  Note 1: A dedicated 16-bit WDT postscaler is available for the PIC12F683. See
                                  Section 12.6 “Watchdog Timer (WDT)” for more information.  *)

*/                                  
//----------------------------------------------------------------------------
  intcon = 0b00000000;  
  /*
  INTERRUPT CONTROL REGISTER
                 00000000
                 0-------   bit 7 GIE: Global Interrupt Enable bit
                  -------         1 = Enables all unmasked interrupts
                  -------         0 = Disables all interrupts
                  0------  bit 6 PEIE: Peripheral Interrupt Enable bit
                   ......         1 = Enables all unmasked peripheral interrupts
                   ......         0 = Disables all peripheral interrupts
                   0-----   bit 5 T0IE: TMR0 Overflow Interrupt Enable bit
                    .....         1 = Enables the TMR0 interrupt
                    .....         0 = Disables the TMR0 interrupt
                    0----   bit 4 INTE: GP2/INT External Interrupt Enable bit
                     ....         1 = Enables the GP2/INT external interrupt
                     ....         0 = Disables the GP2/INT external interrupt
                     0---   bit 3 GPIE: GPIO Change Interrupt Enable bit(1)
                      ...         1 = Enables the GPIO change interrupt
                      ...         0 = Disables the GPIO change interrupt
                      0--   bit 2 T0IF: TMR0 Overflow Interrupt Flag bit(2)
                       ..         1 = TMR0 register has overflowed (must be cleared in software)
                       ..         0 = TMR0 register did not overflow
                       0-   bit 1 INTF: GP2/INT External Interrupt Flag bit
                        .         1 = The GP2/INT external interrupt occurred (must be cleared in software)
                        .         0 = The GP2/INT external interrupt did not occur
                        0   bit 0 GPIF: GPIO Change Interrupt Flag bit
                                  1 = When at least one of the GPIO<5:0> pins changed state (must be cleared in software)
                                  0 = None of the GPIO<5:0> pins have changed state
                                  Note 1: IOC register must also be enabled.
                                  2: T0IF bit is set when Timer0 rolls over. Timer0 is unchanged on Reset and should
                                  be initialized before clearing T0IF bit. 
*/                                  
//----------------------------------------------------------------------------
  pie1 = 0x00000000; 
  /*
  PERIPHERAL INTERRUPT ENABLE REGISTER 1
                 00000000
                 0          bit 7 EEIE: EE Write Complete Interrupt Enable bit
                                  1 = Enables the EE write complete interrupt
                                  0 = Disables the EE write complete interrupt
                  0         bit 6 ADIE: A/D Converter Interrupt Enable bit
                                  1 = Enables the A/D converter interrupt
                                  0 = Disables the A/D converter interrupt
                   0        bit 5 CCP1IE: CCP1 Interrupt Enable bit
                                  1 = Enables the CCP1 interrupt
                                  0 = Disables the CCP1 interrupt
                    0       bit 4 Unimplemented: Read as ‘0’
                     0      bit 3 CMIE: Comparator Interrupt Enable bit
                                  1 = Enables the Comparator 1 interrupt
                                  0 = Disables the Comparator 1 interrupt
                      0     bit 2 OSFIE: Oscillator Fail Interrupt Enable bit
                                  1 = Enables the oscillator fail interrupt
                                  0 = disables the oscillator fail interrupt
                       0    bit 1 TMR2IE: Timer 2 to PR2 Match Interrupt Enable bit
                                  1 = Enables the Timer 2 to PR2 match interrupt
                                  0 = Disables the Timer 2 to PR2 match interrupt
                        0   bit 0 TMR1IE: Timer 1 Overflow Interrupt Enable bit
                                  1 = Enables the Timer 1 overflow interrupt
                                  0 = Disables the Timer 1 overflow interrupt 
*/                                  
//----------------------------------------------------------------------------
  pir1 = 0b00000000; 
  /*
  PERIPHERAL INTERRUPT REQUEST REGISTER 1
                 00000000
                 0          bit 7 EEIF: EEPROM Write Operation Interrupt Flag bit
                                  1 = The write operation completed (must be cleared in software)
                                  0 = The write operation has not completed or has not been started
                  0         bit 6 ADIF: A/D Interrupt Flag bit
                                  1 = A/D conversion complete
                                  0 = A/D conversion has not completed or has not been started
                   0        bit 5 CCP1IF: CCP1 Interrupt Flag bit
                                  Capture mode:
                                  1 = A TMR1 register capture occurred (must be cleared in software)
                                  0 = No TMR1 register capture occurred
                                  Compare mode:
                                  1 = A TMR1 register compare match occurred (must be cleared in software)
                                  0 = No TMR1 register compare match occurred
                                  PWM mode:
                                  Unused in this mode.
                    0       bit 4 Unimplemented: Read as ‘0’
                     0      bit 3 CMIF: Comparator Interrupt Flag bit
                                  1 = Comparator 1 output has changed (must be cleared in software)
                                  0 = Comparator 1 output has not changed
                      0     bit 2 OSFIF: Oscillator Fail Interrupt Flag bit
                                  1 = System oscillator failed, clock input has changed to INTOSC (must be cleared in software)
                                  0 = System clock operating
                       0    bit 1 TMR2IF: Timer 2 to PR2 Match Interrupt Flag bit
                                  1 = Timer 2 to PR2 match occurred (must be cleared in software)
                                  0 = Timer 2 to PR2 match has not occurred
                        0   bit 0 TMR1IF: Timer 1 Overflow Interrupt Flag bit
                                  1 = Timer 1 register overflowed (must be cleared in software)
                                  0 = Timer 1 has not overflowed 
*/                                  
//----------------------------------------------------------------------------
  pcon = 0b00000000; 
  /*
  POWER CONTROL REGISTER
                 00010000
                 00          bit 7-6 Unimplemented: Read as ‘0’
                   1         bit 5 ULPWUE: Ultra Low-Power Wake-up Enable bit
                                  1 = Ultra Low-Power Wake-up enabled
                                  0 = Ultra Low-Power Wake-up disabled
                    0        bit 4 SBODEN: Software BOD Enable bit(1)
                                  1 = BOD enabled
                                  0 = BOD disabled
                     00     bit 3-2 Unimplemented: Read as ‘0’
                       0    bit 1 POR: Power-on Reset Status bit
                                  1 = No Power-on Reset occurred
                                  0 = A Power-on Reset occurred (must be set in software after a Power-on Reset occurs)
                        0   bit 0 BOD: Brown-out Detect Status bit
                                  1 = No Brown-out Detect occurred
                                  0 = A Brown-out Detect occurred (must be set in software after a Brown-out Detect occurs)
                                  Note 1: BODEN<1:0> = 01 in the Configuration Word register for this bit to control the BOD. 
*/                                  
//----------------------------------------------------------------------------
  osctune = 0b00000000; 
  /*
  OSCILLATOR TUNING RESISTOR
                 00000000
                 000        bit 7-5 Unimplemented: Read as ‘0’
                    11111   bit 4-0 TUN<4:0>: Frequency Tuning bits
                                  01111 = Maximum frequency
                                  01110 =
                                  •••
                                  00001 =
                                  00000 = Oscillator module is running at the calibrated frequency.
                                  11111 =
                                  •••
                                  10000 = Minimum frequency 
*/                                  
//----------------------------------------------------------------------------
  osccon = 0b01110000; 
  /*
  OSCILLATOR CONTROL REGISTER
                 01100000
                 0          bit 7 Unimplemented: Read as ‘0’
                  111       bit 6-4 IRCF<2:0>: Internal Oscillator Frequency Select bits
                                  000 = 31 kHz
                                  001 = 125 kHz
                                  010 = 250 kHz
                                  011 = 500 kHz
                                  100 = 1 MHz
                                  101 = 2 MHz
                                  110 = 4 MHz
                                  111 = 8 MHz
                     0      bit 3 OSTS: Oscillator Start-up Time-out Status bit
                                  1 = Device is running from the external system clock defined by FOSC<2:0>
                                  0 = Device is running from the internal system clock (HFINTOSC or LFINTOSC)
                      0     bit 2 HTS: HFINTOSC (High Frequency – 8 MHz to 125 kHz) Status bit
                                  1 = HFINTOSC is stable
                                  0 = HFINTOSC is not stable
                       0    bit 1 LTS: LFINTOSC (Low Frequency – 31 kHz) Stable bit
                                  1 = LFINTOSC is stable
                                  0 = LFINTOSC is not stable
                        0   bit 0 SCS: System Clock Select bit
                                  1 = Internal oscillator is used for system clock
                                  0 = Clock source defined by FOSC<2:0>
                                  Note 1: Bit resets to ‘0’ with Two-Speed Start-up and LP, XT or HS selected as the oscillator
                                  mode or Fail-Safe mode is enabled. 
*/                                  
//----------------------------------------------------------------------------
  gpio = 0b00000000;
  /*
  GENERAL PURPOSE I/O REGISTER
                 00xxxx00
                 00         bit 7-6: Unimplemented: Read as ‘0’
                   000000   bit 5-0: GPIO<5:0>: GPIO I/O pin
                                  1 = Port pin is > VIH
                                  0 = Port pin is < VIL 
*/                                  
//----------------------------------------------------------------------------
  trisio = 0b00111000;
  /*
  GPIO TRI-STATE REGISTER
                 00111111
                 00         bit 7-6: Unimplemented: Read as ‘0’
                   000000  bit 5-0: TRISIO<5:0>: GPIO Tri-State Control bit
                                  1 = GPIO pin configured as an input (tri-stated)
                                  0 = GPIO pin configured as an output
                                  Note 1: TRISIO<3> always reads ‘1’.
                                  2: TRISIO<5:4> reads ‘1’ in XT, LP and HS modes. 
*/                                  
//----------------------------------------------------------------------------
  wpu = 0b00000000;
  /*
  WEAK PULL-UP REGISTER
                 00110111
                 00         bit 7-6 Unimplemented: Read as ‘0’
                   00       bit 5-4 WPU<5:4>: Weak Pull-up register bit
                                  1 = Pull-up enabled
                                  0 = Pull-up disabled
                     0      bit 3 Unimplemented: Read as ‘0’
                      000   bit 2-0 WPU<2:0>: Weak Pull-up register bit
                                  1 = Pull-up enabled
                                  0 = Pull-up disabled
                                  Note 1: Global GPPU must be enabled for individual pull-ups to be enabled.
                                  2: The weak pull-up device is automatically disabled if the pin is in output mode
                                  (TRISIO = 0).
                                  3: The GP3 pull-up is enabled when configured as MCLR and disabled as an I/O in
                                  the Configuration Word.
                                  4: WPU<5:4> reads ‘1’ in XT, LP and HS modes. 
*/                                  
//----------------------------------------------------------------------------
  ioc = 0b00000000; 
  /*
  INTERRUPT-ON-CHANGE GPIO REGISTER
                 00000000
                 00         bit 7-6 Unimplemented: Read as ‘0’
                   000000   bit 5-0 IOC<5:0>: Interrupt-on-change GPIO Control bit
                                  1 = Interrupt-on-change enabled
                                  0 = Interrupt-on-change disabled
                                  Note 1: Global Interrupt Enable (GIE) must be enabled for individual interrupts to be
                                  recognized.
                                  2: IOC<5:4> reads ‘1’ in XT, LP and HS modes.
*/                                  
//----------------------------------------------------------------------------
  t1con = 0b00000100; 
  /*
  TIMER1 CONTROL REGISTER
                 00000000
                 0          bit 7 T1GINV: Timer1 Gate Invert bit(1)
                                  1 = Timer1 gate is inverted
                                  0 = Timer1 gate is not inverted
                  0         bit 6 TMR1GE: Timer1 Gate Enable bit(2)
                                  If TMR1ON = 0:
                                  This bit is ignored.
                                  If TMR1ON = 1:
                                  1 = Timer1 is on if Timer1 gate is not active
                                  0 = Timer1 is on
                   00       bit 5-4 T1CKPS<1:0>: Timer1 Input Clock Prescale Select bits
                                  11 = 1:8 Prescale Value
                                  10 = 1:4 Prescale Value
                                  01 = 1:2 Prescale Value
                                  00 = 1:1 Prescale Value
                     0      bit 3 T1OSCEN: LP Oscillator Enable Control bit
                                  If INTOSC without CLKOUT oscillator is active:
                                  1 = LP oscillator is enabled for Timer1 clock
                                  0 = LP oscillator is off
                                  Else:
                                  This bit is ignored.
                      1     bit 2 T1SYNC: Timer1 External Clock Input Synchronization Control bit
                                  TMR1CS = 1:
                                  1 = Do not synchronize external clock input
                                  0 = Synchronize external clock input
                                  TMR1CS = 0:
                                  This bit is ignored. Timer1 uses the internal clock.
                       0    bit 1 TMR1CS: Timer1 Clock Source Select bit
                                  1 = External clock from T1CKI pin (on the rising edge)
                                  0 = Internal clock (FOSC/4)
                        0   bit 0 TMR1ON: Timer1 On bit
                                  1 = Enables Timer1
                                  0 = Stops Timer1
                                  Note 1: T1GINV bit inverts the Timer1 gate logic, regardless of source.
                                  2: TMR1GE bit must be set to use either T1G pin or COUT, as selected by the T1GSS
                                  bit (CMCON1<1>), as a Timer1 gate source.
*/                                  
//----------------------------------------------------------------------------
  t2con = 0b00000000; 
  /*
  TIMER2 CONTROL REGISTER
                 00000000
                 0          bit 7 Unimplemented: Read as ‘0’
                  0000      bit 6-3 TOUTPS<3:0>: Timer2 Output Postscale Select bits
                                  0000 = 1:1 postscale
                                  0001 = 1:2 postscale
                                  •••
                                  1111 = 1:16 postscale
                      0     bit 2 TMR2ON: Timer2 On bit
                                  1 = Timer2 is on
                                  0 = Timer2 is off
                       00   bit 1-0 T2CKPS<1:0>: Timer2 Clock Prescale Select bits
                                  00 = Prescaler is 1
                                  01 = Prescaler is 4
                                  1x = Prescaler is 16 
*/                                  
//----------------------------------------------------------------------------
  cmcon0 = 0b00000111; 
  /*
  COMPARATOR CONTROL REGISTER 0
                 00000000
                 0          bit 7 Unimplemented: Read as ‘0’
                  0         bit 6 COUT: Comparator Output bit
                                  When CINV = 0:
                                  1 = VIN+ > VIN-
                                  0 = VIN+ < VINWhen
                                  CINV = 1:
                                  1 = VIN+ < VIN-
                                  0 = VIN+ > VINbit
                   0        bit 5 Unimplemented: Read as ‘0’
                    0       bit 4 CINV: Comparator Output Inversion bit
                                  1 = Output inverted
                                  0 = Output not inverted
                     0      bit 3 CIS: Comparator Input Switch bit
                                  When CM<2:0> = 110 or 101:
                                  1 = VIN- connects to CIN+
                                  0 = VIN- connects to CINbit
                      111   bit 2-0 CM<2:0>: Comparator Mode bits
                                  Figure 8-3 shows the Comparator modes and CM<2:0> bit settings.
*/                                  
//----------------------------------------------------------------------------
  cmcon1 = 0b00000000; 
  /*
  COMPARATOR CONTROL REGISTER 1
                 00000010
                 000000     bit 7-2: Unimplemented: Read as ‘0’
                       1    bit 1 T1GSS: Timer1 Gate Source Select bit
                                  1 = Timer1 gate source is T1G pin (GP4 must be configured as digital input)
                                  0 = Timer1 gate source is comparator output
                        0   bit 0 CMSYNC: Comparator Synchronize bit
                                  1 = COUT output synchronized with falling edge of Timer1 clock
                                  0 = COUT output not synchronized with Timer1 clock
*/                                  
//----------------------------------------------------------------------------
  vrcon = 0b00000000; 
  /*
  VOLTAGE REFERENCE CONTROL REGISTER
                 00000000
                 0          bit 7 VREN: CVREF Enable bit
                                  1 = CVREF circuit powered on
                                  0 = CVREF circuit powered down, no IDD drain and CVREF = VSS
                  0         bit 6 Unimplemented: Read as ‘0’
                   0        bit 5 VRR: CVREF Range Selection bit
                                  1 = Low range
                                  0 = High range
                    0       bit 4 Unimplemented: Read as ‘0’
                     0000   bit 3-0 VR<3:0>: CVREF Value Selection 0 . VR <3:0> . 15
                                  When VRR = 1: CVREF = (VR<3:0>/24) * VDD
                                  When VRR = 0: CVREF = VDD/4 + (VR<3:0>/32) * VDD
*/                                  
//----------------------------------------------------------------------------
  adcon0 = 0b10001100;
  /*
  A/D CONTROL REGISTER
                 00000000
                 1          bit 7 ADFM: A/D Result Formed Select bit
                                  1 = Right justified
                                  0 = Left justified
                  0         bit 6 VCFG: Voltage Reference bit
                                  1 = VREF pin
                                  0 = VDD
                   00       bit 5-4 Unimplemented: Read as ‘0’
                     11     bit 3-2 CHS<1:0>: Analog Channel Select bits
                                  00 = Channel 00 (AN0)
                                  01 = Channel 01 (AN1)
                                  10 = Channel 02 (AN2)
                                  11 = Channel 03 (AN3)
                       0    bit 1 GO/DONE: A/D Conversion Status bit
                                  1 = A/D conversion cycle in progress. Setting this bit starts an A/D conversion cycle.
                                  This bit is automatically cleared by hardware when the A/D conversion has completed.
                                  0 = A/D conversion completed/not in progress
                        0   bit 0 ADON: A/D Conversion Status bit
                                  1 = A/D converter module is operating
                                  0 = A/D converter is shut off and consumes no operating current 
*/                                  
  //----------------------------------------------------------------------------
  ansel = 0b00000000;
  /*
  ANALOG SELECT REGISTER
                 00001111
                 0          bit 7 Unimplemented: Read as ‘0’
                  000       bit 6-4 ADCS<2:0>: A/D Conversion Clock Select bits
                                  000 = FOSC/2
                                  001 = FOSC/8
                                  010 = FOSC/32
                                  x11 = FRC (clock derived from a dedicated internal oscillator = 500 kHz max)
                                  100 = FOSC/4
                                  101 = FOSC/16
                                  110 = FOSC/64
                     0000   bit 3-0 ANS<3:0>: Analog Select bits
                                  Analog select between analog or digital function on pins ANS<3:0>, respectively.
                                  1 = Analog input. Pin is assigned as analog input(1).
                                  0 = Digital I/O. Pin is assigned to port or special function.
                                  Note 1: Setting a pin to an analog input automatically disables the digital input circuitry,
                                  weak pull-ups and interrupt-on-change if available. The corresponding TRISIO bit
                                  must be set to input mode in order to allow external control of the voltage on the pin. 
*/                                  
//----------------------------------------------------------------------------
  ccp1con = 0b00000000; 
  /*
  CCP CONTROL REGISTER 1
                 00000000
                 00         bit 7-6 Unimplemented: Read as ‘0’
                   00       bit 5-4 DC1B<1:0>: PWM Least Significant bits
                                  Capture mode:
                                  Unused.
                                  Compare mode:
                                  Unused.
                                  PWM mode:
                                  These bits are the two LSbs of the PWM duty cycle. The eight MSbs are found in CCPR1L.
                     0000   bit 3-0 CCP1M<3:0>: CCP1 Mode Select bits
                                  0000 = Capture/Compare/PWM disabled (resets CCP1 module)
                                  0100 = Capture mode, every falling edge
                                  0101 = Capture mode, every rising edge
                                  0110 = Capture mode, every 4th rising edge
                                  0111 = Capture mode, every 16th rising edge
                                  1000 = Compare mode, set output on match (CCP1IF bit is set)
                                  1001 = Compare mode, clear output on match (CCP1IF bit is set)
                                  1010 = Compare mode, generate software interrupt on match (CCP1IF bit is set,
                                  CCP1 pin is unaffected)
                                  1011 = Compare mode, trigger special event (CCP1IF bit is set, CCP1 pin is unaffected);
                                  CCP1 resets TMR1 and starts an A/D conversion (if A/D module is enabled)
                                  11xx = PWM mode 
*/                                  
//----------------------------------------------------------------------------
  wdtcon = 0b00001000;
  /*
  WATCHDOG TIMER CONTROL REGISTER
                 00001000
                 000        bit 7-5 Unimplemented: Read as ‘0’
                    0100    bit 4-1 WDTPS<3:0>: Watchdog Timer Period Select bits
                                  Bit Value = Prescale Rate
                                  0000 = 1:32
                                  0001 = 1:64
                                  0010 = 1:128
                                  0011 = 1:256
                                  0100 = 1:512 (Reset value)
                                  0101 = 1:1024
                                  0110 = 1:2048
                                  0111 = 1:4096
                                  1000 = 1:8192
                                  1001 = 1:16384
                                  1010 = 1:32768
                                  1011 = 1:65536
                                  1100 = Reserved
                                  1101 = Reserved
                                  1110 = Reserved
                                  1111 = Reserved
                        0   bit 0 SWDTEN: Software Enable or Disable the Watchdog Timer(1)
                                  1 = WDT is turned on
                                  0 = WDT is turned off (Reset value)
                                  Note 1: If WDTE configuration bit = 1, then WDT is always enabled, irrespective of this
                                  control bit. If WDTE configuration bit = 0, then it is possible to turn WDT on/off with
                                  this control bit.
*/                                  
//----------------------------------------------------------------------------
/*
  CONFIG – CONFIGURATION WORD                     <--This is set during the programming of the PIC, NOT in the source code
      bit 13-12 Unimplemented: Read as ‘1’
      bit 11 FCMEN: Fail-Safe Clock Monitor Enabled bit
            1 = Fail-Safe Clock Monitor is enabled
            0 = Fail-Safe Clock Monitor is disabled
      bit 10 IESO: Internal External Switchover bit
            1 = Internal External Switchover mode is enabled
            0 = Internal External Switchover mode is disabled
      bit 9-8 BODEN<1:0>: Brown-out Detect Selection bits(1)
            11 = BOD enabled
            10 = BOD enabled during operation and disabled in Sleep
            01 = BOD controlled by SBODEN bit (PCON<4>)
            00 = BOD disabled
      bit 7 CPD: Data Code Protection bit(2)
            1 = Data memory code protection is disabled
            0 = Data memory code protection is enabled
      bit 6 CP: Code Protection bit(3)
            1 = Program memory code protection is disabled
            0 = Program memory code protection is enabled
      bit 5 MCLRE: GP3/MCLR pin function select bit(4)
            1 = GP3/MCLR pin function is MCLR
            0 = GP3/MCLR pin function is digital input, MCLR internally tied to VDD
      bit 4 PWRTE: Power-up Timer Enable bit
            1 = PWRT disabled
            0 = PWRT enabled
      bit 3 WDTE: Watchdog Timer Enable bit
            1 = WDT enabled
            0 = WDT disabled and can be enabled by SWDTEN bit (WDTCON<0>)
      bit 2-0 FOSC<2:0>: Oscillator Selection bits
            111 = RC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, RC on RA5/OSC1/CLKIN
            110 = RCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, RC on RA5/OSC1/CLKIN
            101 = INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
            100 = INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
            011 = EC: I/O function on RA4/OSC2/CLKOUT pin, CLKIN on RA5/OSC1/CLKIN
            010 = HS oscillator: High-speed crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
            001 = XT oscillator: Crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
            000 = LP oscillator: Low-power crystal on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
            Note 1: Enabling Brown-out Detect does not automatically enable Power-up Timer.
            2: The entire data EEPROM will be erased when the code protection is turned off.
            3: The entire program memory will be erased when the code protection is turned off. When MCLR is asserted
            in INTOSC or RC mode, the internal clock oscillator is disabled.
*/            
//HardwareConfigPIC12F683;
//------------------------------------------------------------------------------

#endif //_BC12F683CONFIG_H_