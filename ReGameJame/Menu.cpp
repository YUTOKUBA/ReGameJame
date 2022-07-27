#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"
#define _USE_MATH_DEFINES
#include <math.h>

static int MenuNo = 0;
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
static int g_GameState = 0;
static int g_Cursor;
static int g_SE1;
static int g_SE2;
static int g_TitleBGM;

//������
void Menu_Initialize() {

	//mImageHandle = LoadGraph("images/Scene_Menu.png"); //�摜�̃��[�h
	mImageHandle = LoadGraph("images/Title.png"); //�摜�̃��[�h
	g_Cursor = LoadGraph("images/cursor.png"); //�摜�̃��[�h
	g_SE1 = LoadSoundMem("BGM_SE/�J�[�\���ړ�1.mp3");	//SE�̃��[�h
	g_SE2 = LoadSoundMem("BGM_SE/����{�^��������26.mp3");	//SE�̃��[�h
	g_TitleBGM = LoadSoundMem("BGM_SE/Azami.mp3");	//SE�̃��[�h
	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_LOOP, TRUE);
}
//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
	DeleteGraph(g_Cursor); //�摜�̉��
	DeleteSoundMem(g_TitleBGM);
}
//�X�V
void Menu_Update() {

	//���j���[�J�[�\���ړ�����
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
		if (++MenuNo > 3) MenuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
		if (--MenuNo < 0) MenuNo = 3;
	}

	//A�{�^���Ń��j���[�I��
	if (g_KeyFlg & PAD_INPUT_A) {
		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
		switch (MenuNo) {
		case 0:
			SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_Credit);//�V�[�����N���W�b�g��ʂɕύX
			break;
		case 3:
			SceneMgr_ChangeScene(eScene_End);//�V�[�����G���h��ʂɕύX
			break;
		}
	}
}
//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	//DrawFormatString(0, 0, GetColor(0, 100, 0), "%d", MenuNo);
	DrawRotaGraph(90, 220 + MenuNo * 60, 1.0f, M_PI, g_Cursor, TRUE, TRUE, TRUE);
	SetFontSize(30);
	DrawString(120, 210, "�E�X�^�[�g", GetColor(0, 0, 0));
	DrawString(120, 270, "�E�������", GetColor(0, 0, 0));
	DrawString(120, 330, "�E�N���W�b�g", GetColor(0, 0, 0));
	DrawString(120, 390, "�E�I��", GetColor(0, 0, 0));
	SetFontSize(18);
}