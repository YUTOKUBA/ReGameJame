#include "Credit.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"


static int mImageHandle; //画像ハンドル格納用変数
//初期化
void Credit_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GaneCredit.png"); //画像のロード
}
//終了処理
void Credit_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void Credit_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 || XNowKey.Buttons[XINPUT_BUTTON_A]) {//Escキーが押されていたらorBボタンが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}
//描画
void Credit_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "credit画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "Bボタンを押すとMenu画面に進みます。", GetColor(136, 136, 255));
}