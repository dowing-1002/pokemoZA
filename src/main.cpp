#include	"main.h"
#include	"morning_evening.h"

/* 関数宣言 */
static void main_Connect_NintendoSw_init();
static void yukari();
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

void yukari() {
/* 1. ZLは押したまま、Aも押す (ZL + A の同時押し状態) */
    SwitchControlLibrary().pressButton(Button::ZL); /* ZLを押し続ける */
    SwitchControlLibrary().pressButton(Button::A);
    SwitchControlLibrary().sendReport();
    /* Aが認識されるまで待つ */
    delay(DELAY_100MS); 
    
    /* 2. ZLは押したまま、Aだけを離す */
    SwitchControlLibrary().pressButton(Button::ZL); /* ZLを押し続ける */
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
    /* 次のyukri()呼び出しまでの間隔 */
    delay(DELAY_100MS);
}

/**
 * @brief 右スティックを押し込む (RSTICK)
 */
void pushRStick() {
/* 1. 右スティックを押し込む */
    SwitchControlLibrary().pressButton(Button::RCLICK);
    SwitchControlLibrary().sendReport();
    
    /* 2. 認識されるまで待つ */
    delay(DELAY_100MS);
    
    /* 3. 右スティックを離す */
    SwitchControlLibrary().releaseButton(Button::RCLICK);
    SwitchControlLibrary().sendReport();
    
    /* 4. 次の操作までの間隔 */
    delay(DELAY_100MS);
}

/**
 * @brief ZLを押しっぱなしにする
 */
void pressZL() {
    SwitchControlLibrary().pressButton(Button::ZL);
    SwitchControlLibrary().releaseButton(Button::A); /* 念のため */
    SwitchControlLibrary().sendReport();
    /* ZLが認識されるまで待つ */
    delay(DELAY_100MS);
}

/**
 * @brief ZLを離す
 */
void releaseZL() {
    SwitchControlLibrary().releaseButton(Button::ZL);
    SwitchControlLibrary().releaseButton(Button::A); /* 念のため */
    SwitchControlLibrary().sendReport();
    /* 離れたことを認識させる */
    delay(DELAY_100MS);
}


/* loop */
void loop(){
	//morning_to_evening();
/* * 画像のシーケンスを実行する
     * 1. ZLを押しっぱなしにする
     */
    pressZL();

    /* 2. (ZLが押されたまま) Aを4回タップする */
    yukari();
    yukari();
    yukari();
    yukari();

    /* 3. ZLを離す */
    releaseZL();

    /* 4. 右スティックを押し込む */
    pushRStick();
    
    /* 終わったら何もしない */
}