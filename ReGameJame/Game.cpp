#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png"); //�摜�̃��[�h
}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "�Q�[����ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B"), GetColor(136,136, 255));
}