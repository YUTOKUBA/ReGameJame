#pragma warning(disable : 4996)
#include"DxLib.h"
#include"Question.h"
#include <string.h>

Quest QUESTION;

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

//正誤判定関数
bool Quest::Answer_judge(int Choices) {

	int i;

	Point_Circle = strchr(Question[QCount][Choices], '_');
	if (Point_Circle != NULL) {
		strncpy(Point_Circle, A, 2);
	}

	//現在出されている問題とその問題のオリジナルを比較する
	/*if (Question[QCount][Choices] && Question_Original[QCount][Choices]) {
		return TRUE;
	}*/

	i = strcmp(Question[QCount][Choices], Question_Original[QCount][Choices]);
	
	if (strcmp(Question[QCount][Choices], Question_Original[QCount][Choices]) == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}




}

void Quest::Question_input() {

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
			//'あ'の場所のアドレスを取る
			Point_A = strchr(Question[i][j], 'あ');
			//NULLだったら'あ'がない,NULL以外だったら'あ'がある
			if (Point_A != NULL) {
				//'あ'の場所に代入する

				*(Point_A - 1) = '_';
				*(Point_A) = '_';

			}
			else {
				//'あ'がなかったら、ランダムな位置の文字を''を代入する
				int StrNumber = GetRand(3);
				Question[i][j][(StrNumber * 2)] = '_';
				Question[i][j][(StrNumber * 2 + 1)] = '_';

			}
		}
	}

}

void Quest::Question_select() {

	for (int i = 0; i < 10; i++) {
		RandLog[i] = GetRand(45);
	}


}

void Quest::DrawQuestion() {
	SetFontSize(20);
	DrawFormatString(130, 200, 0x000000, "%5s", Question[QCount][0]);
	DrawFormatString(430, 200, 0x000000, "%5s", Question[QCount][1]);

}
