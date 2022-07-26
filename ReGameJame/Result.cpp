#include "SceneMgr.h"
#include "Result.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
static int g_ResultBGM;
float TimeResult;

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

	SetFontSize(25);
	DrawFormatString(120, 160, 0xffffff, "�̂��肶����");
	DrawFormatStringToHandle(240, 190, 0xffffff, FontHandle2, "%2.2f", TimeResult / 60);
	DrawFormatString(400, 212, 0xffffff, "�т傤");
	DrawFormatString(120, 250, 0xffffff, "����������������");

	DrawFormatStringToHandle(240, 280, 0xffffff, FontHandle2, "�H/10");
	DrawFormatString(400, 302, 0xffffff, "��");

	SetFontSize(16);
	DrawString(20, 380, "���U���g��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "SPACE�L�[�������ƃ^�C�g����ʂɐi�݂܂��B", GetColor(136, 136, 255));
}