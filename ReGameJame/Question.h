#pragma once
#pragma warning(disable : 4996)
#include<string.h>

#define HARF_WITHD 240;
#define WORD_COUNT 5;			//���̑I�����̕�����
#define QUESTION_TWO_CHOICES 2;			//���
#define PROPOSING_A_QUESTION 10;		//�o�萔
#define ALL_QUESTION 20;				//�S��萔
//#define RAND_MAX 9			//�����ێ��̑��䐔�i�S��肩��I�o���郉���_���Ȉ����j

class Quest {
private:

	char Question[10][2][9];				//�o�肷����̔z��
	char Question_Original[10][2][9];		//�����r�p�̖��z��
	char All_Quest[20][2][9] =				//�S���
	{
		{//1���
			{"������\0\0"},
			{"������\0\0"}
		},
		{//2���
			{"��������"},
			{"���񂽂�"} 
		},
		{//3���
			{},
			{}
		}
	};

	int QCount;			//���ݖ�萔�̃J�E���g
	int RandLog[10];	//�����i�[�z��@�@

	char A = '��';		//'��'��������悤�̕ϐ�
	char Circle = '�O';		//'��'��������悤�̕ϐ�

	char* Point_A = NULL;		//'��'�܂���'�A'�̃|�C���^���i�[����ϐ�
	char* Point_Rand = NULL;		//������̃����_���ȃ|�C���^���i�[����ϐ�
	char* Point_Circle = NULL;		//'��'�̃|�C���^���i�[����ϐ�

public:
	Quest();

	~Quest();

	void Init();

	bool Answer_judge();		//���딻��
	void Question_input();		//�S��肩��o�肷����̔z��ɖ����i�[����
	void Question_select();		//�����őS��肩��o�肷����Ɋi�[����z��̓Y�����𒊑I����
	void DrawQuestion();		//���`��

	int GetRandLog(int i) {
		return RandLog[i];
	}

	void Question_Onceinput() {
		/**Question[0][0] = **/strcpy(Question[0][0], All_Quest[0][0]);
		/**Question[0][0] = **/strcpy(Question[0][1], All_Quest[0][1]);
	}

	//void ChangeChar()

	};

	extern Quest QUESTION;