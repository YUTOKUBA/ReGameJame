#pragma once
#include "DxLib.h"

//�ϐ��̐錾
extern int	g_OldKey;				// �O��̓��̓L�[
extern int	g_NowKey;				// ����̓��̓L�[
extern int	g_KeyFlg;				// ���̓L�[���

extern XINPUT_STATE XNowKey;       //�R���g���[���[�p����̓��̓L�[
extern XINPUT_STATE XOldKey;       //     ,,         �O��̓��̓L�[

//�֐��̐錾
void InputKey(void);				//�p�b�h����
