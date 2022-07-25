#include<stdio.h>
#include"Input.h"
#include"DxLib.h"

void InputKey(void) {
	//“ü—ÍƒL[æ“¾
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;
}