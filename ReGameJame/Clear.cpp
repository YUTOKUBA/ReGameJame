#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

float Time;

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Clear_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GaneClear.png"); //�摜�̃��[�h
	Time = 60 * 5;
}
//�I������
void Clear_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Clear_Update() {
	if (Time-- < 3 ||CheckHitKey(KEY_INPUT_C)) {		//3�b���������C�L�[����������ɃV�[�������U���g�ɕύX
		SceneMgr_ChangeScene(eScene_Result);
	}
}
//�`��
void Clear_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "�N���A��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "3�b�҂A��������C�L�[�������ƃ��U���g��ʂɐi�݂܂��B", GetColor(136, 136, 255));
}