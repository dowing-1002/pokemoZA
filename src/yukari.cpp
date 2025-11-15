#include	"main.h"
#include	"yukari.h"
#include	"my_control.h"

void Yukari_tournament(void) {
	while(1){
	    /* 1. 技Aの使用(ZLが押されたまま) Aを4回押す */
		for(uint8_t i = 0; i < 4; i++){
			HoldAndPushButton(Button::ZL,Button::A);	
		}

		/* 2. 右スティックを押し込む(メガシンカ) */
		pushButton(Button::RCLICK,DELAY_100MS);
	}
}