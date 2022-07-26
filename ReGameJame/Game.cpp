#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //画像ハンドル格納用変数
float g_TimeLimit; 
//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png"); //画像のロード
	g_TimeLimit = 60 * (TIMELIMIT + 1); //制限時間をセット
	QUESTION.Init();
	QUESTION.Question_select();
	//QUESTION.Question_Onceinput();
	QUESTION.Question_input();
}
//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_F) != 0) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Clear);//シーンをメニューに変更
	}
	//if (CheckHitKey(KEY_INPUT_H) != 0) { //Escキーが押されていたら
	//	SceneMgr_ChangeScene(eScene_GameOver);//シーンをメニューに変更
	//}
	
	//計測時間を過ぎたらゲームオーバー
	if (g_TimeLimit-- <= 60 || CheckHitKey(KEY_INPUT_H) != 0) {
		SceneMgr_ChangeScene(eScene_GameOver);//シーンをメニューに変更
	}

	QUESTION.Answer_judge();

}
//描画
void Game_Draw() {
	
	DrawGraph(0, 0, mImageHandle, FALSE);
	QUESTION.DrawQuestion();
	SetFontSize(18);
	DrawString(20, 380, "ゲーム画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("Fキーを押すとゲームクリア画面に行きます。"), GetColor(136,136, 255));
	DrawString(20, 420, TEXT("Hキーを押すとゲームオーバー画面に行きます。"), GetColor(136,136, 255));

	DrawFormatString(320, 50, 0x000000, "%2.2f", g_TimeLimit / 60); //制限時間の描画
}