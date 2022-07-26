#include<stdio.h>
#include"DxLib.h"
 int	g_OldKey;				// 前回の入力キー
 int	g_NowKey;				// 今回の入力キー
 int	g_KeyFlg;				// 入力キー情報

 XINPUT_STATE XNowKey;       //コントローラー用今回の入力キー
 XINPUT_STATE XOldKey;       //     ,,         前回の入力キー


void InputKey(void) {
	//入力キー取得
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	XOldKey = XNowKey;
	GetJoypadXInputState(DX_INPUT_PAD1, &XNowKey);
}