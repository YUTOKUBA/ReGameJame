#pragma once

//変数の宣言
extern int	g_OldKey;				// 前回の入力キー
extern int	g_NowKey;				// 今回の入力キー
extern int	g_KeyFlg;				// 入力キー情報

//関数の宣言
void InputKey(void);				//パッド入力
