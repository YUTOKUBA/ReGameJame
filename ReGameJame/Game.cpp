#include "Game.h"
#include "Result.h"
#include "SceneMgr.h"
#include"Input.h"
#include "DxLib.h"
#include "Question.h"

static int mImageHandle; //画像ハンドル格納用変数
static int keeperHandle; //画像ハンドル格納用変数
static int Ball;		 //画像ハンドル格納用変数
static int BallCatch;	 //画像ハンドル格納用変数
static int SE_Atari;
static int SE_Hazure;
static int g_GameBGM;
float g_TimeLimit;

bool g_TimeStop;	// 答えを選択した時に操作を受け付けないようにするためのフラグ
bool keeper;		// 飛んだキーパーを反転させる用のフラグ
bool left;			// キーパーを左に向かせるようフラグ
bool right;			// キーパーを右に向かせるようフラグ

int g_count;		// １秒間操作をさせないための変数
int g_count_old;	// g_count の前の時間を入れる用変数

int a;
int seikai;
int sippai;

int ball_X = 320;
int ball_Y = 420;

//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GameMain.png"); //画像のロード
	keeperHandle = LoadGraph("images/keeper.png");
	Ball = LoadGraph("images/A_Ball.png");
	BallCatch = LoadGraph("images/soccer_catch.png");
	SE_Atari = LoadSoundMem("BGM_SE/Seikai.mp3");	//SEのロード
	SE_Hazure = LoadSoundMem("BGM_SE/Huseikai.mp3");	//SEのロード
	g_GameBGM = LoadSoundMem("BGM_SE/Flash_Light.mp3");	//BGMのロード
	PlaySoundMem(g_GameBGM, DX_PLAYTYPE_LOOP, TRUE);
	g_TimeLimit = 60 * (TIMELIMIT); //制限時間をセット
	g_TimeStop = false;
	keeper = false;
	left = false;
	right = false;
	g_count = 0;
	g_count_old = 0;
	ball_X = 320;
	ball_Y = 420;
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
	DeleteSoundMem(g_GameBGM);
}

//更新
void Game_Update() {


	//計測時間を過ぎたらゲームオーバー
	if (g_TimeLimit <= 1 || CheckHitKey(KEY_INPUT_H) != 0) {
		TimeResult = g_TimeLimit;
		SceneMgr_ChangeScene(eScene_GameOver);//シーンをメニューに変更
	}

	// 答えを選択したら1秒止める
	if (g_TimeStop == false) {

		g_TimeLimit--;			// 答えを選択するまで制限時間が減っていく
		g_count++;				// 答えを選択するまでの時間を取る
		g_count_old = g_count;	// 答えを選択した瞬間の時間を取る

		if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_A]) {
			Choices = 0;
			if (QUESTION.Answer_judge(Choices) == TRUE) {
				ball_X = 171;
				ball_Y = 195;
				Ans_State = 1;	//正解
				seikai++;
				QUESTION.SetQCount();
				PlaySoundMem(SE_Atari, DX_PLAYTYPE_BACK, TRUE);
				g_TimeStop = true;
				left = false;
				right = false;
				//WaitTimer(1000);
			}
			else
			{
				ball_X = 171;
				ball_Y = 195;
				Ans_State = 2;	//不正解
				sippai++;
				QUESTION.SetQCount();
				PlaySoundMem(SE_Hazure, DX_PLAYTYPE_BACK, TRUE);
				//WaitTimer(1000);
				g_TimeStop = true;
				right = false;
				left = true;
			}
		}
		else if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B]) {
			Choices = 1;
			if (QUESTION.Answer_judge(Choices) == TRUE) {
				ball_X = 468;
				ball_Y = 195;
				Ans_State = 1;	//正解
				seikai++;
				QUESTION.SetQCount();
				PlaySoundMem(SE_Atari, DX_PLAYTYPE_BACK, TRUE);
				//WaitTimer(1000);
				g_TimeStop = true;
				right = false;
				left = false;
			}
			else
			{
				ball_X = 468;
				ball_Y = 195;
				Ans_State = 2;//不正解
				sippai++;
				QUESTION.SetQCount();
				PlaySoundMem(SE_Hazure, DX_PLAYTYPE_BACK, TRUE);
				//WaitTimer(1000);
				g_TimeStop = true;
				left = false;
				right = true;
			}
		}

		if (g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_B] || g_KeyFlg && XNowKey.Buttons[XINPUT_BUTTON_A]) {
			a++;
			if (a >= 10) {
				if (seikai >= 6) {
					TimeResult = g_TimeLimit;
					SceneMgr_ChangeScene(eScene_Clear);	//Clearシーンに遷移する
				}
				else {
					TimeResult = g_TimeLimit;
					SceneMgr_ChangeScene(eScene_GameOver);	//Clearシーンに遷移する
				}
			}
		}
	}
	else {
		// １秒待つまで操作を受け付けなくする
		if (++g_count > g_count_old + 60) {
			g_TimeStop = false;
			ball_X = 320;
			ball_Y = 420;
		}
	}

}

//描画
void Game_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);

	// 答えを選択するまでは普通のキーパー
	if (g_TimeStop == false) {
		DrawRotaGraph(320, 260, 0.8, 0, keeperHandle, TRUE);
	}
	else {
		// A が間違ったら左に飛ぶ
		if (left == true) {
			keeper = true;
			DrawRotaGraph(240, 260, 0.6, 0, BallCatch, TRUE, keeper);
		}
		// B が間違ったら右に飛ぶ
		else if(right == true){
			keeper = false;
			DrawRotaGraph(400, 260, 0.6, 0, BallCatch, TRUE, keeper);
		}
		else {
			DrawRotaGraph(320, 260, 0.8, 0, keeperHandle, TRUE);
		}
	}
	DrawRotaGraph(ball_X, ball_Y, 0.15, 0, Ball, TRUE);
	if (g_TimeStop == false) {
		QUESTION.DrawQuestion();
	}
	DrawFormatStringToHandle(280, 15, 0x000000, FontHandle1, "%2.2f", g_TimeLimit / 60); //制限時間の描画
	//DrawFormatString(10, 100, 0x000000, "%d", Ans_State); //正解かどうか

}