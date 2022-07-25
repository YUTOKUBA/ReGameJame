#include "Result.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Result_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Result.png"); //�摜�̃��[�h
}
//�I������
void Result_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Result_Update() {
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
	}
}
//�`��
void Result_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "���U���g��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "SPACE�L�[�������ƃ^�C�g����ʂɐi�݂܂��B", GetColor(136, 136, 255));
}