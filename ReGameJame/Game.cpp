#include "Game.h"
#include "Result.h"
#include "SceneMgr.h"
#include"Input.h"
#include "DxLib.h"
#include "Question.h"

static int mImageHandle; //画像ハンドル格納用変数
float g_TimeLimit;
int a;
int seikai;
int sippai;

//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GameMain.png"); //画像のロード
	g_TimeLimit = 60 * (TIMELIMIT); //制限時間をセット
	QUESTION.Init();
	QUESTION.Question_select();
	QUESTION.Question_input();
	a = 0;
	seikai = 0;
	sippai = 0;
}

//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}

//更新
void Game_Update() {
	 
	//計測時間を過ぎたらゲームオーバー
	if (g_TimeLimit-- <= 1 || CheckHitKey(KEY_INPUT_H) != 0) {
		TimeResult = g_TimeLimit;
		SceneMgr_ChangeScene(eScene_GameOver);//シーンをメニューに変更
	}

	if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_A]) {
		Choices = 0;
		if (QUESTION.Answer_judge(Choices) == TRUE) {
			Ans_State = 1;	//正解
			seikai++;
			QUESTION.SetQCount();
		}
		else
		{
			Ans_State = 2;	//不正解
			sippai++;
			QUESTION.SetQCount();
		}
	}
	else if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B]) {
		Choices = 1;
		if (QUESTION.Answer_judge(Choices) == TRUE) {
			Ans_State = 1;	//正解
			seikai++;
			QUESTION.SetQCount();
		}
		else
		{
			Ans_State = 2;//不正解
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

//描画
void Game_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);
	QUESTION.DrawQuestion();
	SetFontSize(18);
	DrawString(20, 380, "ゲーム画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("Fキーを押すとゲームクリア画面に行きます。"), GetColor(136, 136, 255));
	DrawString(20, 420, TEXT("Hキーを押すとゲームオーバー画面に行きます。"), GetColor(136, 136, 255));

	DrawFormatStringToHandle(280, 15, 0x000000, FontHandle1, "%2.2f", g_TimeLimit / 60); //制限時間の描画
	DrawFormatString(10, 100, 0x000000, "%d", Ans_State); //制限時間の描画

}