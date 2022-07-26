#include<stdio.h>
#include"DxLib.h"
#include"Game.h"

int	g_OldKey;				
int	g_NowKey;				
int	g_KeyFlg;			

XINPUT_STATE XNowKey;      
XINPUT_STATE XOldKey;

void InputKey(void) {
	//入力キー取得
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	XOldKey = XNowKey;
	GetJoypadXInputState(DX_INPUT_PAD1, &XNowKey);
}