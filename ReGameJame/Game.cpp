#include "Game.h"
#include "SceneMgr.h"
#include"Input.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
float g_TimeLimit; 

//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png"); //�摜�̃��[�h
	g_TimeLimit = 60 * (TIMELIMIT + 1); //�������Ԃ��Z�b�g
	QUESTION.Init();
	QUESTION.Question_select();
	QUESTION.Question_input();

}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_F) != 0) { //F�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Clear);//�V�[�����N���A�ɕύX
	}
	//if (CheckHitKey(KEY_INPUT_H) != 0) { //Esc�L�[��������Ă�����
	//	SceneMgr_ChangeScene(eScene_GameOver);//�V�[�������j���[�ɕύX
	//}
	
	//�v�����Ԃ��߂�����Q�[���I�[�o�[
	if (g_TimeLimit-- <= 1 || CheckHitKey(KEY_INPUT_H) != 0) {
		SceneMgr_ChangeScene(eScene_GameOver);//�V�[�������j���[�ɕύX
	}

	if (g_KeyFlg & PAD_INPUT_A) {
		Choices = 0;
		if (QUESTION.Answer_judge(Choices) == TRUE) { 
			Ans_State = 1; 
		}
		else { 
			Ans_State == 2; 
		};
	}
	else if (g_KeyFlg & PAD_INPUT_B) {
		Choices = 1;
		if (QUESTION.Answer_judge(Choices) == TRUE)Ans_State = 1;
		else Ans_State == 2;
	}

	//QUESTION.Answer_judge();

}
//�`��
void Game_Draw() {
	
	DrawGraph(0, 0, mImageHandle, FALSE);
	QUESTION.DrawQuestion();
	if (Ans_State == 1) {
		DrawString(50, 50, "����", 0x000000);
		Ans_State = 0;
	}
	else if(Ans_State==2){
		DrawString(50, 50, "�s����", 0x000000);
		Ans_State = 0;
	}
	SetFontSize(18);
	DrawString(20, 380, "�Q�[����ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("F�L�[�������ƃQ�[���N���A��ʂɍs���܂��B"), GetColor(136,136, 255));
	DrawString(20, 420, TEXT("H�L�[�������ƃQ�[���I�[�o�[��ʂɍs���܂��B"), GetColor(136,136, 255));

	DrawFormatString(320, 50, 0x000000, "%2.2f", g_TimeLimit / 60); //�������Ԃ̕`��
}