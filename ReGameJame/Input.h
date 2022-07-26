#pragma once
#include "DxLib.h"


extern int	g_OldKey;
extern int	g_NowKey;
extern int	g_KeyFlg;

extern XINPUT_STATE XNowKey;
extern XINPUT_STATE XOldKey;


void InputKey(void);