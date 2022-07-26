#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
static int g_ResultBGM;
//������
void Result_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Result.png"); //�摜�̃��[�h
	g_ResultBGM = LoadSoundMem("BGM_SE/Sunrise.mp3");	//BGM�̃��[�h
	PlaySoundMem(g_ResultBGM, DX_PLAYTYPE_LOOP, TRUE);
}
//�I������
void Result_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
	DeleteSoundMem(g_ResultBGM); //�����̊J��
}
//�X�V
void Result_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 || XNowKey.Buttons[XINPUT_BUTTON_A]) {//Esc�L�[��������Ă�����orB�{�^����������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Result_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "���U���g��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "SPACE�L�[�������ƃ^�C�g����ʂɐi�݂܂��B", GetColor(136, 136, 255));
}