#include "Credit.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"


static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Credit_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GaneCredit.png"); //�摜�̃��[�h
}
//�I������
void Credit_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Credit_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 || XNowKey.Buttons[XINPUT_BUTTON_A]) {//Esc�L�[��������Ă�����orB�{�^����������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Credit_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "credit��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "B�{�^����������Menu��ʂɐi�݂܂��B", GetColor(136, 136, 255));
}