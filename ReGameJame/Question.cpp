#pragma warning(disable : 4996)
#include"DxLib.h"
#include"Question.h"

Quest QUESTION;

//int RandCheck(int i) {
//
//	for (int j = 0; j < RAND_MAX; j++) {
//		if (QUESTION.GetRandLog(j) == i) RandCheck(GetRand(19));
//	}
//
//	return i;
//
//}

Quest::Quest() {

	Question[9][1][4] = {};
	Question_Original[9][1][4] = {};

	//全問題用の変数の初期化
	//All_Quest[19][1][4] = {};

	QCount = 0;
	RandLog[9] = {};
}

Quest::~Quest() {

}

void Quest::Init() {

	Question[9][1][4] = {};
	Question_Original[9][1][4] = {};

	QCount = 0;
	for (int i = 0; i < 10; i++) {
		RandLog[i] = 0;
	}

}

bool Quest::Answer_judge() {

	int Choices = 0;

	/*if (GetJoypadInputState(PAD_INPUT_4) == 1) {
		Choices = 0;
	}
	else if (GetJoypadInputState(PAD_INPUT_5) == 1) {
		Choices = 1;
	}*/

	Point_Circle = strchr(Question[QCount][Choices], '○');
	if (Point_Circle != NULL)Point_Circle = &A;

	//現在出されている問題とその問題のオリジナルを比較する
	/*if (Question[QCount][Choices] && Question_Original[QCount][Choices]) {
		return TRUE;
	}*/

	if(strcmp(Question[QCount][Choices], Question_Original[QCount][Choices])==0)return true;

	return FALSE;

}

void Quest::Question_input() {

	int Count = 0;

	//全問題からのコピー
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 10; i++) {
			//出題用にランダムに選ばれた全問題の中身（文字列）をコピーする
			strcpy(Question[i][j], All_Quest[RandLog[i]][j]);

			//正誤比較用にランダムに選ばれた全問題の中身（文字列）をコピーする
			strcpy(Question_Original[i][j], All_Quest[RandLog[i]][j]);
			
		}
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 10; i++) {
			Point_A = strchr(Question[i][j], 'あ');
			if (Point_A != NULL) {
				Point_A = &Circle;
			}
			else {
				int StrNumber = GetRand(2);
				Question[i][j][(StrNumber * 2) + 1] = Circle;
			}
		}
	}

}

void Quest::Question_select() {

	for (int i = 0; i < 10; i++) {
		RandLog[i] = GetRand(19);
	}


}

void Quest::DrawQuestion() {
	SetFontSize(20);
	DrawFormatString(100, 200, 0x000000, "%5s", Question[QCount][0]);
	//DrawFormatString(500, 200, 0x000000, "%5s", Question[QCount][1]);

}