#pragma warning(disable : 4996)
#include"DxLib.h"
#include"Question.h"
#include <string.h>

Quest QUESTION;

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

//���딻��֐�
bool Quest::Answer_judge(int Choices) {

	int i;

	Point_Circle = strchr(Question[QCount][Choices], '_');
	if (Point_Circle != NULL) {
		strncpy(Point_Circle, A, 2);
	}

	//���ݏo����Ă�����Ƃ��̖��̃I���W�i�����r����
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
			//'��'�̏ꏊ�̃A�h���X�����
			Point_A = strchr(Question[i][j], '��');
			//NULL��������'��'���Ȃ�,NULL�ȊO��������'��'������
			if (Point_A != NULL) {
				//'��'�̏ꏊ�ɑ������

				*(Point_A - 1) = '_';
				*(Point_A) = '_';

			}
			else {
				//'��'���Ȃ�������A�����_���Ȉʒu�̕�����''��������
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
