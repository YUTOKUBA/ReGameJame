#include "Game.h"
#include "Result.h"
#include "SceneMgr.h"
#include"Input.h"
#include "DxLib.h"
#include "Question.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
static int keeperHandle;
static int Ball;
static int SE_Atari;
static int SE_Hazure;
float g_TimeLimit;
//bool g_TimeStop;

int a;
int seikai;
int sippai;

int ball_X = 320;
int ball_Y = 420;

//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GameMain.png"); //�摜�̃��[�h
	keeperHandle = LoadGraph("images/keeper.png");
	Ball = LoadGraph("images/A_Ball.png");
	SE_Atari = LoadSoundMem("BGM_SE/Seikai.mp3");	//SE�̃��[�h
	SE_Hazure = LoadSoundMem("BGM_SE/Huseikai.mp3");	//SE�̃��[�h
	g_TimeLimit = 60 * (TIMELIMIT); //�������Ԃ��Z�b�g
	//g_TimeStop = false;
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
			//ball_X = 160;
			//ball_Y = 260;
			Ans_State = 1;	//����
			seikai++;
			QUESTION.SetQCount();
			PlaySoundMem(SE_Atari, DX_PLAYTYPE_BACK, TRUE);
			WaitTimer(1000);
		}
		else
		{
			Ans_State = 2;	//�s����
			sippai++;
			QUESTION.SetQCount();
			PlaySoundMem(SE_Hazure, DX_PLAYTYPE_BACK, TRUE);
			WaitTimer(1000);
		}
	}
	else if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B]) {
		Choices = 1;
		if (QUESTION.Answer_judge(Choices) == TRUE) {
			Ans_State = 1;	//����
			seikai++;
			QUESTION.SetQCount();
			PlaySoundMem(SE_Atari, DX_PLAYTYPE_BACK, TRUE);
			WaitTimer(1000);
		}
		else
		{
			Ans_State = 2;//�s����
			sippai++;
			QUESTION.SetQCount();
			PlaySoundMem(SE_Hazure, DX_PLAYTYPE_BACK, TRUE);
			WaitTimer(1000);
		}
	}

	if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B] || g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_A]) {
		a++;
		if (a >= 10) {
			if (seikai >= 6) {
				TimeResult = g_TimeLimit;
				SceneMgr_ChangeScene(eScene_Clear);	//Clear�V�[���ɑJ�ڂ���
			}
			else {
				TimeResult = g_TimeLimit;
				SceneMgr_ChangeScene(eScene_GameOver);	//Clear�V�[���ɑJ�ڂ���
			}
		}
	}

}

//�`��
void Game_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);

	DrawRotaGraph(320, 260, 0.8, 0, keeperHandle, TRUE);
	DrawRotaGraph(ball_X, ball_Y, 0.15, 0, Ball, TRUE);

	QUESTION.DrawQuestion();

	DrawFormatStringToHandle(280, 15, 0x000000, FontHandle1, "%2.2f", g_TimeLimit / 60); //�������Ԃ̕`��
	DrawFormatString(10, 100, 0x000000, "%d", Ans_State); //�������Ԃ̕`��

}