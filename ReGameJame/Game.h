#pragma once
#include"Question.h"
void Game_Initialize();//������
void Game_Finalize();//�I������
void Game_Update();//�X�V
void Game_Draw();//�`��

static int Choices;
static bool Ans_State;

const int TIMELIMIT = 30; //��������
extern float g_TimeLimit; 