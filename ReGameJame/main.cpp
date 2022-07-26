#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

//更新

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); //ウィンドウモード変更
	DxLib_Init(); //DXライブラリ初期化
	SetDrawScreen(DX_SCREEN_BACK); //裏画面設定
	SceneMgr_Initialize(); //
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) { //画面更新 &メッセージ処理& 画面消去
		InputKey();
			SceneMgr_Update(); //更新
		SceneMgr_Draw(); //描画
	}
	SceneMgr_Finalize();
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}