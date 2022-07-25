#include "Result.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //画像ハンドル格納用変数
//初期化
void Result_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Result.png"); //画像のロード
}
//終了処理
void Result_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void Result_Update() {
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをゲーム画面に変更
	}
}
//描画
void Result_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "リザルト画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "SPACEキーを押すとタイトル画面に進みます。", GetColor(136, 136, 255));
}