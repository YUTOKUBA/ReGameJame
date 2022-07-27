#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle; //画像ハンドル格納用変数h
static int BackSE;
//初期化
void Config_Initialize() {
	mImageHandle = LoadGraph("images/Help.png");//画像のロード
	BackSE = LoadSoundMem("BGM_SE/cancel-1.mp3");
}
//終了処理
void Config_Finalize() {
	DeleteGraph(mImageHandle);//画像の解放
}
//更新
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 || XNowKey.Buttons[XINPUT_BUTTON_B]) {//Escキーが押されていたらorBボタンが押されていたら
		PlaySoundMem(BackSE, DX_PLAYTYPE_BACK, TRUE);
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}
//描画
void Config_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
}