#pragma once
#include"Question.h"
void Game_Initialize();//‰Šú‰»
void Game_Finalize();//I—¹ˆ—
void Game_Update();//XV
void Game_Draw();//•`‰æ

static int Choices;
static bool Ans_State;

const int TIMELIMIT = 30; //§ŒÀŠÔ
extern float g_TimeLimit; 