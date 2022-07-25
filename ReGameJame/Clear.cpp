#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //画像ハンドル格納用変数
//初期化
void Clear_Initialize() {
}
//終了処理
void Clear_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void Clear_Update() {
	if (CheckHitKey(KEY_INPUT_C) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Result);//シーンをゲーム画面に変更
	}
}
//描画
void Clear_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "クリア画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "Cキーを押すとリザルト画面に進みます。", GetColor(136, 136, 255));
}