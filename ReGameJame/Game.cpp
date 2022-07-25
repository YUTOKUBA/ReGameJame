#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
float g_TimeLimit; 
//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png"); //�摜�̃��[�h
	g_TimeLimit = 60 * (TIMELIMIT + 1); //�������Ԃ��Z�b�g
}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_F) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Clear);//�V�[�������j���[�ɕύX
	}
	//if (CheckHitKey(KEY_INPUT_H) != 0) { //Esc�L�[��������Ă�����
	//	SceneMgr_ChangeScene(eScene_GameOver);//�V�[�������j���[�ɕύX
	//}
	
	//�v�����Ԃ��߂�����Q�[���I�[�o�[
	if (g_TimeLimit-- <= 60 || CheckHitKey(KEY_INPUT_H) != 0) {
		SceneMgr_ChangeScene(eScene_GameOver);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "�Q�[����ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("F�L�[�������ƃQ�[���N���A��ʂɍs���܂��B"), GetColor(136,136, 255));
	DrawString(20, 420, TEXT("H�L�[�������ƃQ�[���I�[�o�[��ʂɍs���܂��B"), GetColor(136,136, 255));

	DrawFormatString(320, 50, 0x000000, "%2.2f", g_TimeLimit / 60); //�������Ԃ̕`��
}