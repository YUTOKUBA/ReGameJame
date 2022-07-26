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

	//右だったらA、左だったらB
	/*if () {//右
		Choices = 0;
	}
	else if () == 1) {//左
		Choices = 1;
	}*/

	Point_Circle = strchr(Question[QCount][Choices], '_');
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
	char* P=0;

	//全問題からのコピー
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 10; i++) {
			//出題用にランダムに選ばれた全問題の中身（文字列）をコピーする
			strcpy(Question[0][j], All_Quest[0/*RandLog[0]*/][j]);

			//正誤比較用にランダムに選ばれた全問題の中身（文字列）をコピーする
			strcpy(Question_Original[0][j], All_Quest[0/*RandLog[0]*/][j]);
			
		}
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 1; i++) {
			//'あ'の場所のアドレスを取る
			Point_A = strchr(Question[0][j], 'あ');
			//NULLだったら'あ'がない,NULL以外だったら'あ'がある
			if (Point_A != NULL) {
				//'あ'の場所に代入する

				*(Point_A-1) = '_';
				*(Point_A) = '_';

			}
			else {
				//'あ'がなかったら、ランダムな位置の文字を''を代入する
				int StrNumber = GetRand(3);
				Question[0][j][(StrNumber * 2)]= '_';
				Question[0][j][(StrNumber * 2+1)]= '_';
				
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
	DrawFormatString(500, 200, 0x000000, "%5s", Question[QCount][1]);

}