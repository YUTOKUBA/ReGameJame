#pragma once
#define HARF_WITHD 240;
#define WORD_COUNT 5;			//���̑I�����̕�����
#define QUESTION_TWO_CHOICES 2;			//���
#define PROPOSING_A_QUESTION 10;		//�o�萔
#define ALL_QUESTION 20;				//�S��萔

class Quest {
private:

	char Question[10][2][5];				//�o�肷����̔z��
	char Question_Original[10][2][5];		//�����r�p�̖��z��
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
	int RandLog[10];	//�����i�[�z��@�@���I�񂾖����܂��I�΂Ȃ��悤��

public:
	Quest();

	~Quest();

	void Init();

	bool Answer_judge();		//���딻��
	void Question_input();		//�S��肩��o�肷����̔z��ɖ����i�[����
	void Question_select();		//�����őS��肩��o�肷����Ɋi�[����z��̓Y�����𒊑I����
	void DrawQuestion();		//���`��


	};

	extern Quest QUESTION;