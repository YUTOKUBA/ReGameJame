#include "GameOver.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //画像ハンドル格納用変数
//初期化
void GameOver_Initialize() {
}
//終了処理
void GameOver_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void GameOver_Update() {
	if (CheckHitKey(KEY_INPUT_J) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Result);//シーンをリザルト画面に変更
	}
}
//描画
void GameOver_Draw() {
	DrawString(20, 380, "ゲームオーバー画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "Jキーを押すとリザルト画面に進みます。", GetColor(136, 136, 255));
}