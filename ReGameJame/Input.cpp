#include<stdio.h>
#include"DxLib.h"
 int	g_OldKey;				// �O��̓��̓L�[
 int	g_NowKey;				// ����̓��̓L�[
 int	g_KeyFlg;				// ���̓L�[���

 XINPUT_STATE XNowKey;       //�R���g���[���[�p����̓��̓L�[
 XINPUT_STATE XOldKey;       //     ,,         �O��̓��̓L�[


void InputKey(void) {
	//���̓L�[�擾
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;

	XOldKey = XNowKey;
	GetJoypadXInputState(DX_INPUT_PAD1, &XNowKey);
}