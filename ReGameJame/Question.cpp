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

	//�S���p�̕ϐ��̏�����
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

	Point_Circle = strchr(Question[QCount][Choices], '��');
	if (Point_Circle != NULL)Point_Circle = &A;

	//���ݏo����Ă�����Ƃ��̖��̃I���W�i�����r����
	/*if (Question[QCount][Choices] && Question_Original[QCount][Choices]) {
		return TRUE;
	}*/

	if(strcmp(Question[QCount][Choices], Question_Original[QCount][Choices])==0)return true;

	return FALSE;

}

void Quest::Question_input() {

	int Count = 0;

	//�S��肩��̃R�s�[
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 10; i++) {
			//�o��p�Ƀ����_���ɑI�΂ꂽ�S���̒��g�i������j���R�s�[����
			strcpy(Question[i][j], All_Quest[RandLog[i]][j]);

			//�����r�p�Ƀ����_���ɑI�΂ꂽ�S���̒��g�i������j���R�s�[����
			strcpy(Question_Original[i][j], All_Quest[RandLog[i]][j]);
			
		}
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 10; i++) {
			Point_A = strchr(Question[i][j], '��');
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