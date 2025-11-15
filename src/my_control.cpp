#include	"main.h"

/**
 * @brief 「移動」と「ボタン連打」を交互に繰り返す（同時ではない）
 * @note ボタン連打中はスティックを中央に戻すことで、メニューの誤操作を完全に防ぐ
 * @param lx, ly スティック方向
 * @param button ボタン
 * @param total_time 総実行時間 (ms)
 * @param move_time 1回あたりの移動時間 (ms)
 * @param renda_count 1回のボタン連打フェーズでボタンを押す回数
 */
void moveAndRenda(uint8_t lx, uint8_t ly, uint16_t button, unsigned long total_time, unsigned long move_time, int renda_count) {
    
    unsigned long start_time = millis();
    unsigned long elapsed_time = 0;

    /* total_time を超えるまでループ */
    while (elapsed_time < total_time) {

        /* --- 1. 移動フェーズ --- */
        /* スティックを倒し、ボタンは押さない */
        SwitchControlLibrary().moveLeftStick(lx, ly);
        SwitchControlLibrary().releaseButton(button);
        SwitchControlLibrary().sendReport();
        /* 'move_time' ミリ秒間、移動し続ける */
        delay(move_time);

        /* --- 2. ボタン連打フェーズ --- */
        /* スティックを中央に戻し、カーソルが動かないようにする */
        SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
        SwitchControlLibrary().releaseButton(button); /* 念のため */
        SwitchControlLibrary().sendReport();
        delay(DELAY_20MS); /* 状態を安定させる */
        
        for (int i = 0; i < renda_count; i++) {
            /* ボタンを押す */
            SwitchControlLibrary().pressButton(button);
            SwitchControlLibrary().sendReport();
            delay(DELAY_100MS); /* メニューがAを認識するまで待つ */

            /* ボタンを離す */
            SwitchControlLibrary().releaseButton(button);
            SwitchControlLibrary().sendReport();
            /* スティックが中央なので、この遅延は長くても問題ない */
            delay(DELAY_100MS); 
        }

        /* 経過時間を更新 */
        elapsed_time = millis() - start_time;
    }

    /* すべての操作を終了 */
    SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
    SwitchControlLibrary().releaseButton(button);
    SwitchControlLibrary().sendReport();
    delay(DELAY_100MS);
}

/**
 * @brief button1を押したまま、button2を押し、その後、buttun1を解除する
 * @note　ポケモンZAで技を使いたい時はbutton1にZA、使いたい技をbutton2にする
 */
void HoldAndPushButton(uint16_t button1,uint16_t button2) {
	SwitchControlLibrary().pressButton(button1);	/* button1を押す */
    SwitchControlLibrary().sendReport();
    delay(DELAY_100MS*5);

    SwitchControlLibrary().pressButton(button1); 	/* button1を押し続ける */
    SwitchControlLibrary().pressButton(button2);	/* button2を押す */
    SwitchControlLibrary().sendReport();
    delay(DELAY_100MS*5);

	SwitchControlLibrary().pressButton(button1);	/* button1は押し続ける */
    SwitchControlLibrary().releaseButton(button2);	/* button2の解除 */
    SwitchControlLibrary().sendReport();
    delay(DELAY_100MS*5);

	SwitchControlLibrary().releaseButton(button1);	/* button1の解除 */
    SwitchControlLibrary().sendReport();
    delay(DELAY_100MS*5);
}