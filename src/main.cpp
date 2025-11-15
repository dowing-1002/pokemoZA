#include	"main.h"
#include	"morning_evening.h"
#include	"yukari.h"
#include	"fwmode.h"


/* 関数宣言 */
static void main_Connect_NintendoSw_init();

/* setup */
void setup(){
	/* 起動時、「持ち方/順番を変える」になっている前提 */
	main_Connect_NintendoSw_init();
}

/* loop */
void loop(){
	if(FWSETTING_NUM > INVALID_SETTING){	/* 複数の機能が選択されている場合なにもしない */
		/* NOP */
	}else if(BENCHSKIP == FUNC_ON){			/* ベンチで朝晩スキップすることでの厳選 */
		morning_to_evening();
	}else if(YUKARI_TOURNAMENT == FUNC_ON){	/* ゆかりトーナメントでの金策レベリング */
		Yukari_tournament();
	}
}

/* 起動時の処理 */
static void main_Connect_NintendoSw_init()
{
	/* コントローラ認識処理実施 */
	pushButton(Button::L, DELAY_500MS, 5);			/* Switchがにマイコンを認識させる処理(500msごとに2回L押下) */
	/* コントローラ認識済み */
	pushButton(Button::HOME, DELAY_1S*2,2);			/* homeに戻る、ゲームに戻る */
}