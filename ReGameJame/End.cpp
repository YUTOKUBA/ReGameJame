#include"End.h"
#include"SceneMgr.h"
#include"DxLib.h"

static int mImageBackGround;	//画像ハンドル格納用変数
static int mImageBall;	//画像ハンドル格納用変数
static int FontHandleEnd;
static int StopTime;

//初期化
void End_Initialize() {
	mImageBackGround = LoadGraph("images/End_BackGround.png");	//画像のロード
	mImageBall = LoadGraph("images/End_Ball.png");	//画像のロード
	FontHandleEnd = CreateFontToHandle("ＭＳ 明朝", 50, 10, DX_FONTTYPE_NORMAL);
	StopTime = 0;
}

//終了処理
void End_Finalize() {
	DeleteGraph(mImageBackGround);//画像の解放
	DeleteGraph(mImageBall);//画像の解放
}

//更新

//描画
void End_Draw() {

	DrawGraph(0, 0, mImageBackGround, FALSE);
	//DrawGraph(0, 0, mImageBall, TRUE);
	DrawRotaGraph(90, 300, 0.2f, 0, mImageBall, TRUE);

	//SetFontSize(50);
	//DrawString(40, 180, "Thank you for Playing", 0xffffff, 0);
	DrawFormatStringToHandle(35, 170, GetColor(255, 255, 255), FontHandleEnd, "Thank you for Playing!");

	//タイムの火山処理＆終了（3秒後）
	if (++StopTime > 180) {
		DxLib_End();
	}
}