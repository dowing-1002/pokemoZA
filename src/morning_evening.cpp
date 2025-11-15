/* ポケモンZAで朝晩をベンチで経過させる */

#include	"main.h"

void morning_to_evening()
{
	/*
     * スティックを真下(Y: MAX)に 500ms(DELAY_500MS) 移動した後、
     * Aボタンを 3 回連打する。
     * これを全体で 30秒間(DELAY_1S * 30) 繰り返す。
	 * tiltLeftStick()で再現できない挙動のためmoveAndRenda()で対応
     */
    moveAndRenda(
        Stick::NEUTRAL,     /* lx (X軸は中央) */
        Stick::MAX,         /* ly (Y軸は下) */
		Button::A,			/* Aボタン */
        DELAY_1S * 30,      /* total_time (30秒間) */
        DELAY_500MS,        /* move_time (1回の移動時間 0.5秒) */
        3                   /* renda_count (Aを3回押す) */
    );
}