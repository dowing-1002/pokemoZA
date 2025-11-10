#include	"main.h"
#include	"yukari.h"
void Yukari_tournament(void)
{
	/* * 画像のシーケンスを実行する
     * 1. ZLを押しっぱなしにする
     */
    pressZL();

    /* 2. (ZLが押されたまま) Aを4回タップする */
    Yukari_Use_SkillA();
    Yukari_Use_SkillA();
    Yukari_Use_SkillA();
    Yukari_Use_SkillA();

    /* 3. ZLを離す */
    releaseZL();

    /* 4. 右スティックを押し込む */
    pushRStick();
    
    /* 終わったら何もしない */
}

void Yukari_Use_SkillA() {
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