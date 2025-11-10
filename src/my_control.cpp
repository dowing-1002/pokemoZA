#include	"main.h"

/**
 * @brief 「移動」と「A連打」を交互に繰り返す（同時ではない）
 * @note A連打中はスティックを中央に戻すことで、メニューの誤操作を完全に防ぐ
 * @param lx, ly スティック方向
 * @param total_time 総実行時間 (ms)
 * @param move_time 1回あたりの移動時間 (ms)
 * @param renda_count 1回のA連打フェーズでAボタンを押す回数
 */
void moveAndRenda(uint8_t lx, uint8_t ly, unsigned long total_time, unsigned long move_time, int renda_count) {
    
    unsigned long start_time = millis();
    unsigned long elapsed_time = 0;

    /* total_time を超えるまでループ */
    while (elapsed_time < total_time) {

        /* --- 1. 移動フェーズ --- */
        /* スティックを倒し、Aは押さない */
        SwitchControlLibrary().moveLeftStick(lx, ly);
        SwitchControlLibrary().releaseButton(Button::A);
        SwitchControlLibrary().sendReport();
        /* 'move_time' ミリ秒間、移動し続ける */
        delay(move_time);

        /* --- 2. A連打フェーズ --- */
        /* スティックを中央に戻し、カーソルが動かないようにする */
        SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
        SwitchControlLibrary().releaseButton(Button::A); /* 念のため */
        SwitchControlLibrary().sendReport();
        delay(DELAY_20MS); /* 状態を安定させる */
        
        for (int i = 0; i < renda_count; i++) {
            /* Aを押す */
            SwitchControlLibrary().pressButton(Button::A);
            SwitchControlLibrary().sendReport();
            delay(DELAY_100MS); /* メニューがAを認識するまで待つ */

            /* Aを離す */
            SwitchControlLibrary().releaseButton(Button::A);
            SwitchControlLibrary().sendReport();
            /* スティックが中央なので、この遅延は長くても問題ない */
            delay(DELAY_100MS); 
        }

        /* 経過時間を更新 */
        elapsed_time = millis() - start_time;
    }

    /* すべての操作を終了 */
    SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().sendReport();
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
