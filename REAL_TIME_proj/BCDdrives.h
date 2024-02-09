/*
 * BCDdrives.h
 *
 * Created: 07/06/2023 10:17:12 م
 *  Author: handsa
 */ 


#ifndef BCDDRIVER_H_
#define BCDDRIVER_H_
void sev_seg_pcd_init_l(unsigned char port);
void sev_seg_pcd_init_h(unsigned char port);
sev_seg_pcd_write_l(char port ,unsigned char val);
sev_seg_pcd_write_h(char port ,unsigned char val);



#endif /* BCDDRIVER_H_ */