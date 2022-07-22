#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Menu_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Menu.png"); //�摜�̃��[�h
}
//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {//C�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
}
//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "���j���[��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(136, 136, 255));
	DrawString(20, 420, "C�L�[�������� �ݒ��ʂɐi�݂܂��B", GetColor(136, 136, 255));
}