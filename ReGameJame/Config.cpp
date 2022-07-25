#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //画像ハンドル格納用変数
//初期化
void Config_Initialize() {
	mImageHandle = LoadGraph("images/Help.png");//画像のロード
}
//終了処理
void Config_Finalize() {
	DeleteGraph(mImageHandle);//画像の解放
}
//更新
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}
//描画
void Config_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	/*DrawString(20, 380, "設定画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "Escキーを押すとメニュー画面に戻ります。", GetColor(136, 136,
		255));*/
}