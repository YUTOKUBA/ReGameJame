#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

int ClearWaitTime;

static int ClearSound;

static int mImageHandle; //画像ハンドル格納用変数
//初期化
void Clear_Initialize() {
	mImageHandle = LoadGraph("images/Scene_GaneClear.png"); //画像のロード
	ClearWaitTime = 60 * 3;
	ClearSound = LoadSoundMem("BGM_SE/success.mp3");	//SEの読み込み
	PlaySoundMem(ClearSound, DX_PLAYTYPE_BACK, TRUE);
}
//終了処理
void Clear_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void Clear_Update() {
	if (ClearWaitTime-- < 3 ||CheckHitKey(KEY_INPUT_C)) {		//3秒後もしくはCキーを押したらにシーンをリザルトに変更
		SceneMgr_ChangeScene(eScene_Result);
	}
}
//描画
void Clear_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	//DrawString(20, 380, "クリア画面です。", GetColor(136, 136, 255));
	//DrawString(20, 400, "3秒待つか、Cキーを押すとリザルト画面に進みます。", GetColor(136, 136, 255));
}