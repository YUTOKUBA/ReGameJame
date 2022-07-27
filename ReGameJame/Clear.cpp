#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

int ClearWaitTime;

static int ClearSound;

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Clear_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GaneClear.png"); //�摜�̃��[�h
	ClearWaitTime = 60 * 3;
	ClearSound = LoadSoundMem("BGM_SE/success.mp3");	//SE�̓ǂݍ���
	PlaySoundMem(ClearSound, DX_PLAYTYPE_BACK, TRUE);
}
//�I������
void Clear_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Clear_Update() {
	if (ClearWaitTime-- < 3 ||CheckHitKey(KEY_INPUT_C)) {		//3�b���������C�L�[����������ɃV�[�������U���g�ɕύX
		SceneMgr_ChangeScene(eScene_Result);
	}
}
//�`��
void Clear_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	//DrawString(20, 380, "�N���A��ʂł��B", GetColor(136, 136, 255));
	//DrawString(20, 400, "3�b�҂��AC�L�[�������ƃ��U���g��ʂɐi�݂܂��B", GetColor(136, 136, 255));
}