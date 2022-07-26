#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle; //画像ハンドル格納用変数
static int g_ResultBGM;
//初期化
void Result_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Result.png"); //画像のロード
	g_ResultBGM = LoadSoundMem("BGM_SE/Sunrise.mp3");	//BGMのロード
	PlaySoundMem(g_ResultBGM, DX_PLAYTYPE_LOOP, TRUE);
}
//終了処理
void Result_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
	DeleteSoundMem(g_ResultBGM); //音源の開放
}
//更新
void Result_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0 || XNowKey.Buttons[XINPUT_BUTTON_A]) {//Escキーが押されていたらorBボタンが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}
//描画
void Result_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 380, "リザルト画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "SPACEキーを押すとタイトル画面に進みます。", GetColor(136, 136, 255));
}