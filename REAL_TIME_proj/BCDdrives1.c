/*
 * BCDdrives1.c
 *
 * Created: 09/06/2023 01:48:25 م
 *  Author: handsa
 */ 
#include "DIO_drives.h"
void sev_seg_pcd_init_l(unsigned char port)
{
	dio_set_pin(port,0,1);
		dio_set_pin(port,1,1);
			dio_set_pin(port,2,1);
				dio_set_pin(port,3,1);
}
void sev_seg_pcd_init_h(unsigned char port)
{
	dio_set_pin(port,4,1);
	dio_set_pin(port,5,1);
	dio_set_pin(port,6,1);
	dio_set_pin(port,7,1);
}
sev_seg_pcd_write_l(char port ,unsigned char val)
{
	dio_write_lo_level( port, val);
}
sev_seg_pcd_write_h(char port ,unsigned char val)
{
	dio_write_hi_level( port, val);
}