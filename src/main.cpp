#include	"main.h"
#include	"morning_evening.h"
#include	"yukari.h"


/* 関数宣言 */
static void main_Connect_NintendoSw_init();
static void Yukari_Use_SkillA();
static void pushRStick();


/* setup */
void setup(){
	/* 起動時、「持ち方/順番を変える」になっている前提 */
	main_Connect_NintendoSw_init();
}

/* 起動時の処理 */
static void main_Connect_NintendoSw_init()
{
	/* コントローラ認識処理実施 */
	pushButton(Button::L, DELAY_500MS, 5);			/* Switchがにマイコンを認識させる処理(500msごとに2回L押下) */
	/* コントローラ認識済み */
	pushButton(Button::HOME, DELAY_1S*2,2);			/* homeに戻る、ゲームに戻る */
}



/* loop */
void loop(){
	//morning_to_evening();
	Yukari_tournament();
}
