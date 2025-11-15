#ifndef	MY_CONTROL_H
#define	MY_CONTROL_H

/* 関数宣言 */
void moveAndRenda(uint8_t lx, uint8_t ly, uint16_t button, unsigned long total_time, unsigned long move_time, int renda_count);
void pushRStick();
void pressZL();
void releaseZL();


#endif /* MY_CONTROL_H */