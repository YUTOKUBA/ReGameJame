#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"

int GameOverWaitTime;
static int GameOverSound;
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void GameOver_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GaneOver.png"); //�摜�̃��[�h
	GameOverWaitTime = 60 * 5;
	GameOverSound = LoadSoundMem("BGM_SE/faild-comical.mp3");	//SE�̓ǂݍ���
	PlaySoundMem(GameOverSound, DX_PLAYTYPE_BACK, TRUE);

}
//�I������
void GameOver_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void GameOver_Update() {
	if (GameOverWaitTime--< 3 ||CheckHitKey(KEY_INPUT_J) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Result);//�V�[�������U���g��ʂɕύX
	}
}
//�`��
void GameOver_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "�Q�[���I�[�o�[��ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, "J�L�[�������ƃ��U���g��ʂɐi�݂܂��B", GetColor(136, 136, 255));
}