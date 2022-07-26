#include "SceneMgr.h"
#include "Result.h"
#include "DxLib.h"
#include "Input.h"

static int mImageHandle; //画像ハンドル格納用変数
static int g_ResultBGM;
float TimeResult;

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

	SetFontSize(25);
	DrawFormatString(120, 160, 0xffffff, "のこりじかん");
	DrawFormatStringToHandle(240, 190, 0xffffff, FontHandle2, "%2.2f", TimeResult / 60);
	DrawFormatString(400, 212, 0xffffff, "びょう");
	DrawFormatString(120, 250, 0xffffff, "せいかいしたかず");

	DrawFormatStringToHandle(240, 280, 0xffffff, FontHandle2, "？/10");
	DrawFormatString(400, 302, 0xffffff, "問");

	SetFontSize(16);
	DrawString(20, 380, "リザルト画面です。", GetColor(136, 136, 255));
	DrawString(20, 400, "SPACEキーを押すとタイトル画面に進みます。", GetColor(136, 136, 255));
}