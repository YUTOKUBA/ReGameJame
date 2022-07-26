#include "Game.h"
#include "Result.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
float g_TimeLimit; 

//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GameMain.png"); //�摜�̃��[�h
	g_TimeLimit = 60 * (TIMELIMIT); //�������Ԃ��Z�b�g
	//QUESTION.Init();
}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_F) != 0) { //Esc�L�[��������Ă�����
		TimeResult = g_TimeLimit;
		SceneMgr_ChangeScene(eScene_Clear);//�V�[�������j���[�ɕύX
	}
	
	//�v�����Ԃ��߂�����Q�[���I�[�o�[
	if (g_TimeLimit-- <= 1 || CheckHitKey(KEY_INPUT_H) != 0) {
		SceneMgr_ChangeScene(eScene_GameOver);//�V�[�������j���[�ɕύX
	}
}
//�`��
void Game_Draw() {
	
	DrawGraph(0, 0, mImageHandle, FALSE);
	//QUESTION.DrawQuestion();
	SetFontSize(18);
	DrawString(20, 380, "�Q�[����ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("F�L�[�������ƃQ�[���N���A��ʂɍs���܂��B"), GetColor(136,136, 255));
	DrawString(20, 420, TEXT("H�L�[�������ƃQ�[���I�[�o�[��ʂɍs���܂��B"), GetColor(136,136, 255));

	DrawFormatStringToHandle(280, 15, 0x000000, FontHandle1, "%2.2f", g_TimeLimit / 60); //�������Ԃ̕`��
}