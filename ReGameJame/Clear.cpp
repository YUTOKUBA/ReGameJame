#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Clear_Initialize() {
}
//�I������
void Clear_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Clear_Update() {
	if (CheckHitKey(KEY_INPUT_C) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Result);//�V�[�����Q�[����ʂɕύX
	}
}
//�`��
void Clear_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "�N���A��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "C�L�[�������ƃ��U���g��ʂɐi�݂܂��B", GetColor(136, 136, 255));
}