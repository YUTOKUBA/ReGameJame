//#include"DxLib.h"
//#include"Question.h"
//
//Quest QUESTION;
//
//int RandCheck(int i) {
//
//
//
//}
//
//Quest::Quest() {
//
//	Question[9][1][4] = {};
//	Question_Original[9][1][4] = {};
//
//	//全問題用の変数の初期化
//	//All_Quest[19][1][4] = {};
//
//	QCount = 0;
//	RandLog[9] = {};
//}
//
//Quest::~Quest() {
//
//}
//
//void Quest::Init() {
//
//	Question[9][1][4] = {};
//	Question_Original[9][1][4] = {};
//
//	QCount = 0;
//	for (int i = 0; i < 10; i++) {
//		RandLog[i] = 20;
//	}
//
//}
//
//bool Quest::Answer_judge() {
//
//	int Choices = 0;
//
//	if (GetJoypadInputState(PAD_INPUT_4) == 1) {
//		Choices = 0;
//	}
//	else if (GetJoypadInputState(PAD_INPUT_5) == 1) {
//		Choices = 1;
//	}
//
//	for (int i = 0; Question[QCount][Choices][i] == '○'; i++) {
//		Question[QCount][Choices][i] = 'あ';
//	}
//
//	//現在出されている問題とその問題のオリジナルを比較する
//	if (Question[QCount][Choices] && Question_Original[QCount][Choices]) {
//		return TRUE;
//	}
//
//	return FALSE;
//
//}
//
//void Quest::Question_input() {
//
//
//
//}
//
//void Quest::Question_select() {
//
//	for (int i = 0; i < 10; i++){
//		RandLog[i] = RandCheck(GetRand(19));
//	}
//
//
//}
//
//void Quest::DrawQuestion() {
//	SetFontSize(20);
//	DrawFormatString(100, 200, 0x000000, "%5s", All_Quest[QCount][0]);
//	DrawFormatString(500, 200, 0x000000, "%5s", All_Quest[QCount][1]);
//
//}