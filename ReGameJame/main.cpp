#include "DxLib.h"
#include "SceneMgr.h"
#include"Input.h"

int FontHandle1;
int FontHandle2;

//更新

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); //ウィンドウモード変更
	DxLib_Init(); //DXライブラリ初期化
	SetDrawScreen(DX_SCREEN_BACK); //裏画面設定
	SceneMgr_Initialize(); 

	FontHandle1 = CreateFontToHandle(NULL, 32, 3, DX_FONTTYPE_NORMAL);
	FontHandle2 = CreateFontToHandle(NULL, 55, 3, DX_FONTTYPE_NORMAL);

	while (ProcessMessage() == 0 ) { //画面更新 &メッセージ処理& 画面消去

		double dNextTime = GetNowCount();

		ClearDrawScreen();
		
		InputKey();
		SceneMgr_Update(); //更新
		SceneMgr_Draw(); //描画
		if (dNextTime + 16.66 > GetNowCount()) {
			WaitTimer((int)dNextTime - GetNowCount());
		}
		ScreenFlip();
	}
	SceneMgr_Finalize();
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}