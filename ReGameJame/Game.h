#pragma once
#include"Question.h"
void Game_Initialize();//初期化
void Game_Finalize();//終了処理
void Game_Update();//更新
void Game_Draw();//描画

const int TIMELIMIT = 30; //制限時間
extern float g_TimeLimit; 