#pragma once
#include "DxLib.h"

//変数の宣言
extern int	g_OldKey;				// 前回の入力キー
extern int	g_NowKey;				// 今回の入力キー
extern int	g_KeyFlg;				// 入力キー情報

extern XINPUT_STATE XNowKey;       //コントローラー用今回の入力キー
extern XINPUT_STATE XOldKey;       //     ,,         前回の入力キー

//関数の宣言
void InputKey(void);				//パッド入力
