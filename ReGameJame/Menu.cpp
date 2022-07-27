#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"
#define _USE_MATH_DEFINES
#include <math.h>

static int MenuNo = 0;
static int mImageHandle; //画像ハンドル格納用変数
static int g_GameState = 0;
static int g_Cursor;
static int g_SE1;
static int g_SE2;
static int g_TitleBGM;

//初期化
void Menu_Initialize() {

	//mImageHandle = LoadGraph("images/Scene_Menu.png"); //画像のロード
	mImageHandle = LoadGraph("images/Title.png"); //画像のロード
	g_Cursor = LoadGraph("images/cursor.png"); //画像のロード
	g_SE1 = LoadSoundMem("BGM_SE/カーソル移動1.mp3");	//SEのロード
	g_SE2 = LoadSoundMem("BGM_SE/決定ボタンを押す26.mp3");	//SEのロード
	g_TitleBGM = LoadSoundMem("BGM_SE/Azami.mp3");	//SEのロード
	PlaySoundMem(g_TitleBGM, DX_PLAYTYPE_LOOP, TRUE);
}
//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
	DeleteGraph(g_Cursor); //画像の解放
	DeleteSoundMem(g_TitleBGM);
}
//更新
void Menu_Update() {

	//メニューカーソル移動処理
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
		if (++MenuNo > 3) MenuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		PlaySoundMem(g_SE1, DX_PLAYTYPE_BACK, TRUE);
		if (--MenuNo < 0) MenuNo = 3;
	}

	//Aボタンでメニュー選択
	if (g_KeyFlg & PAD_INPUT_A) {
		PlaySoundMem(g_SE2, DX_PLAYTYPE_BACK, TRUE);
		switch (MenuNo) {
		case 0:
			SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_Credit);//シーンをクレジット画面に変更
			break;
		case 3:
			SceneMgr_ChangeScene(eScene_End);//シーンをエンド画面に変更
			break;
		}
	}
}
//描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	//DrawFormatString(0, 0, GetColor(0, 100, 0), "%d", MenuNo);
	DrawRotaGraph(90, 220 + MenuNo * 60, 1.0f, M_PI, g_Cursor, TRUE, TRUE, TRUE);
	SetFontSize(30);
	DrawString(120, 210, "・スタート", GetColor(0, 0, 0));
	DrawString(120, 270, "・操作説明", GetColor(0, 0, 0));
	DrawString(120, 330, "・クレジット", GetColor(0, 0, 0));
	DrawString(120, 390, "・終了", GetColor(0, 0, 0));
	SetFontSize(18);
}