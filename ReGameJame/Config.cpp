#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�h
static int BackSE;
//������
void Config_Initialize() {
	mImageHandle = LoadGraph("images/Help.png");//�摜�̃��[�h
	BackSE = LoadSoundMem("BGM_SE/cancel-1.mp3");
}
//�I������
void Config_Finalize() {
	DeleteGraph(mImageHandle);//�摜�̉��
}
//�X�V
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 || XNowKey.Buttons[XINPUT_BUTTON_B]) {//Esc�L�[��������Ă�����orB�{�^����������Ă�����
		PlaySoundMem(BackSE, DX_PLAYTYPE_BACK, TRUE);
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Config_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
}