#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Config_Initialize() {
	mImageHandle = LoadGraph("images/Help.png");//�摜�̃��[�h
}
//�I������
void Config_Finalize() {
	DeleteGraph(mImageHandle);//�摜�̉��
}
//�X�V
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Config_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	/*DrawString(20, 380, "�ݒ��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(136, 136,
		255));*/
}