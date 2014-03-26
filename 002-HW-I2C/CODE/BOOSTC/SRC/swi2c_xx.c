#include "INC\swi2c.h"


/**
 * ... text ...
 */

void i2c_init(void)
{
	
	i2c_tris.SCL = 1;
	i2c_tris.SDA = 1;
	

}

/**
 *  \brief     Pretty nice class.
 *  \details   This class is used to demonstrate a number of section commands.
 *  \author    PJW
 *  \version   4.1a
 *  \date      1990-2011
 *  \pre       First initialize the system.
 *  \todo      Not all memory is freed when deleting an object of this class.
 *  \warning   Improper use can crash your application
 *  \copyright GNU Public License.
 *  \par       New paragraph under the same heading.
 *
 * \note
 * This note consists of two paragraphs.
 * This is the first paragraph.
 *
 *   
 */

// InByte
char SWI2C_InByte(void)  //done
{
char i_byte = 0;
char n;

   SWI2C_HighSda();
   
   for (n=0; n<8; n++)
		{
		SWI2C_HighScl();

		if (i2c_port.SDA)
			{
			i_byte = (i_byte << 1) | 0x01; // msbit first
			}
		else
			{
			i_byte = i_byte << 1;
			}
			
		SWI2C_LowScl();	
		}
		
   return(i_byte);
}

/**
*  \author    John Doe
*  \author    Jan Doe
*  \version   4.1a
*  \date      1990-2011
*  \pre       First initialize the system.
*  \bug       Not all memory is freed when deleting an object of this class.
*  \param[out] o_byte unsigned byte to write to SDA.

*/

// OutByte
// SWI2C_OutByte

void i2c_out_byte(unsigned char o_byte)  //done
{
unsigned char n; /** Loop counter*/

   for(n=0; n<8; n++)
   {
      if(o_byte&0x80)
		{
         SWI2C_HighSda();
		}
      else
		{
         i2c_low_sda();
		}
      SWI2C_HighScl();
      SWI2C_LowScl();
      o_byte = o_byte << 1;
   }
   SWI2C_HighSda();
}

void i2c_write_byte(char dev_addr, char idata) //done
{
	i2c_start();
	i2c_out_byte(dev_addr & 0xFE);  //-- Lowest bit = 0 => WRITE
	i2c_nack();
	i2c_out_byte(idata);			// and finally the data
	i2c_nack();
	i2c_stop();

}

char i2c_read_byte(char dev_addr)
{
char rval;

   i2c_start();
   i2c_out_byte(dev_addr & 0xFe); //-- Lowest bit = 0 => WRITE
   i2c_nack();
      
   i2c_start();				// no intermediate stop
   i2c_out_byte(dev_addr | 0x01); //-- Lowest bit = 1 => READ
   i2c_nack();
   
   rval=i2c_in_byte();
   i2c_stop();
   
   return(rval);
}

// Common I2C Routines




