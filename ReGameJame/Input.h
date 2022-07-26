#pragma once
#include "DxLib.h"


int	g_OldKey;
int	g_NowKey;
int	g_KeyFlg;
extern int	g_OldKey;
extern int	g_NowKey;
extern int	g_KeyFlg;

extern XINPUT_STATE XNowKey;
extern XINPUT_STATE XOldKey;


void InputKey(void);