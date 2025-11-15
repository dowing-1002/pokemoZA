#ifndef	FWMODE_H
#define	FWMODE_H


#define	FUNC_ON		1	/* 機能有効 */
#define	FUNC_OFF	0	/* 機能無効 */

/* 機能選択 */
#define	BENCHSKIP			FUNC_OFF	/* ベンチで朝晩スキップすることでの厳選 */
#define	YUKARI_TOURNAMENT	FUNC_ON		/* ゆかりトーナメントでの金策レベリング */

/* 不正な設定かを確認する */
#define	FWSETTING_NUM	(BENCHSKIP + YUKARI_TOURNAMENT)	/* 選択されている機能数 */
#define	INVALID_SETTING	(FUNC_ON + FUNC_ON)				/* 2機能選択されている場合 */


#endif /* FWMODE_H */