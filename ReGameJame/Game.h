#pragma once
#include"Question.h"
void Game_Initialize();//������
void Game_Finalize();//�I������
void Game_Update();//�X�V
void Game_Draw();//�`��

static int Choices;
static int Ans_State = 0; //�����F�P�A�s�����F�Q

const int TIMELIMIT = 30; //��������
extern float g_TimeLimit;

extern int seikai;
extern int sippai;