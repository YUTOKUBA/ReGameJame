#include "Game.h"
#include "Result.h"
#include "SceneMgr.h"
#include"Input.h"
#include "DxLib.h"
#include "Question.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
float g_TimeLimit;
int a;
int seikai;
int sippai;

//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GameMain.png"); //�摜�̃��[�h
	g_TimeLimit = 60 * (TIMELIMIT); //�������Ԃ��Z�b�g
	QUESTION.Init();
	QUESTION.Question_select();
	QUESTION.Question_input();
	a = 0;
	seikai = 0;
	sippai = 0;
}

//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}

//�X�V
void Game_Update() {
	 
	//�v�����Ԃ��߂�����Q�[���I�[�o�[
	if (g_TimeLimit-- <= 1 || CheckHitKey(KEY_INPUT_H) != 0) {
		TimeResult = g_TimeLimit;
		SceneMgr_ChangeScene(eScene_GameOver);//�V�[�������j���[�ɕύX
	}

	if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_A]) {
		Choices = 0;
		if (QUESTION.Answer_judge(Choices) == TRUE) {
			Ans_State = 1;	//����
			seikai++;
			QUESTION.SetQCount();
		}
		else
		{
			Ans_State = 2;	//�s����
			sippai++;
			QUESTION.SetQCount();
		}
	}
	else if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B]) {
		Choices = 1;
		if (QUESTION.Answer_judge(Choices) == TRUE) {
			Ans_State = 1;	//����
			seikai++;
			QUESTION.SetQCount();
		}
		else
		{
			Ans_State = 2;//�s����
			sippai++;
			QUESTION.SetQCount();
		}
	}
	if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B]|| g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_A]) {
		a++;
		if (a >= 10) {
			TimeResult = g_TimeLimit;
			SceneMgr_ChangeScene(eScene_Clear);
		}
	}

}

//�`��
void Game_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);
	QUESTION.DrawQuestion();
	SetFontSize(18);
	DrawString(20, 380, "�Q�[����ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("F�L�[�������ƃQ�[���N���A��ʂɍs���܂��B"), GetColor(136, 136, 255));
	DrawString(20, 420, TEXT("H�L�[�������ƃQ�[���I�[�o�[��ʂɍs���܂��B"), GetColor(136, 136, 255));

	DrawFormatStringToHandle(280, 15, 0x000000, FontHandle1, "%2.2f", g_TimeLimit / 60); //�������Ԃ̕`��
	DrawFormatString(10, 100, 0x000000, "%d", Ans_State); //�������Ԃ̕`��

}