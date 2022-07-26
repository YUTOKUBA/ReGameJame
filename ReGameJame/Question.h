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
		/* 
		 *�y�ŏ��ɕ����𓖂Ă͂߂�^�C�v�̖��z
		 * �S 10 ��
		 * 1 �`  5 ��� 3 ����
		 * 6 �` 10 ��� 4 ����
		 */
		{//1���
			{"������\0\0"},
			{"�߂���\0\0"}
		},
		{//2���
			{"�߂���\0\0"},
			{"������\0\0"} 
		},
		{//3���
			{"������\0\0"},
			{"�߂���\0\0"}
		},
		{//4���
			{"�߂��\0\0"},
			{"�����\0\0"}
		},
		{//5���
			{"�߂���\0\0"},
			{"������\0\0"}
		},
		{//6���
			{"��������"},
			{"���񂢂�"}
		},
		{//7���
			{"���肦"},
			{"���Ƃ肦"}
		},
		{//8���
			{"�����܂�"},
			{"���܂���"}
		},
		{//9���
			{"��������"},
			{"���񂽂�"}
		},
		{//10���
			{"��������"},
			{"��������"}
		},
		/*�y�r���ɕ����𓖂Ă͂߂�^�C�v�̖��z
		 * �S 10 ��
		 * 11 �` 15 ��� 3 ����
		 * 16 �` 20 ��� 4 ����
		 */
		{//11���
			{"������\0\0"},
			{"�ɂ��\0\0"}
		},
		{//12���
			{"������\0\0"},
			{"�݂���\0\0"}
		},
		{//13���
			{"������\0\0"},
			{"���̂�\0\0"}
		},
		{//14���
			{"�悭��\0\0"},
			{"�悠��\0\0"}
		},
		{//15���
			{"�����[\0\0"},
			{"������\0\0"}
		},
		{//16���
			{"��݂���"},
			{"���ɂ�"}
		},
		{//17���
			{"���݂���"},
			{"���݂���"}
		},
		{//18���
			{"���݂���"},
			{"���̂܂�"}
		},
		{//19���
			{"��������"},
			{"��������"}
		},
		{//20���
			{"���񂠂�"},
			{"����͂�"}
		}
		///*�y�Ō�ɕ����𓖂Ă͂߂�^�C�v�̖��z
		// * �S 10 ��
		// * 21 �` 25 ��� 3 ����
		// * 26 �` 30 ��� 4 ����
		// */	
		//{ //21���
		//	{"�낵��\0\0"},
		//	{"���\0\0"}
		//},
		//{//22���
		//	{"������\0\0"},
		//	{"���肠\0\0"}
		//},
		//{//23���
		//	{"������\0\0"},
		//	{"������\0\0"}
		//},
		//{//24���
		//	{"������\0\0"},
		//	{"���肠\0\0"}
		//},
		//{//25���
		//	{"���ɂ�\0\0"},
		//	{"���ɂ�\0\0"}
		//},
		//{//26���
		//	{"�����肠"},
		//	{"�����肤"}
		//},
		//{//27���
		//	{"����Ƃ�"},
		//	{"����ǂ�"}
		//},
		//{//28���
		//	{"����т�"},
		//	{"����҂�"}
		//},
		//{//29���
		//	{"�ς�Ƃ�"},
		//	{"�͂�ǂ�"}
		//},
		//{//30���
		//	{"�����ꂠ"},
		//	{"�����키"}
		//},
		///*�y�����A�s�������ŏ��E�r���E�Ō�A�J�^�J�i�E�Ђ炪�Ȃ�������܂��ɂ����^�C�v�̖��z
		// * �S 16 ��
		// * 31 �` 38 ��� 3 ����
		// * 39 �` 45 ��� 4 ����
		// */
		//{ //31���
		//	{"�V�r��\0\0"},
		//	{"�c�r�A\0\0"}
		//},
		//{//32���
		//	{"�A�[��\0\0"},
		//	{"���j��\0\0"}
		//},
		//{//33���
		//	{"���^��\0\0"},
		//	{"�}����\0\0"}
		//},
		//{//34���
		//	{"�X�r�A\0\0"},
		//	{"�X�s��\0\0"}
		//},
		//{//35���
		//	{"������\0\0"},
		//	{"�����j\0\0"}
		//},
		//{//36���
		//	{"�A�j�X\0\0"},
		//	{"���[��\0\0"}
		//},
		//{//37���
		//	{"���b�v\0\0"},
		//	{"�A�c�v\0\0"}
		//},
		//{//38���
		//	{"���[�A\0\0"},
		//	{"���j��\0\0"}
		//},
		//{//39���
		//	{"���^���"},
		//	{"�}�N���"}
		//},
		//{//40���
		//	{"�c�x����"},
		//	{"�V�x�肠"}
		//},
		//{//41���
		//	{"���j�}��"},
		//	{"���C�g��"}
		//},
		//{//42���
		//	{"����h��"},
		//	{"���C�h��"}
		//},
		//{//43���
		//	{"�T�C���N"},
		//	{"�����A��"}
		//},
		//{//44���
		//	{"�c���y�}"},
		//	{"�����y��"}
		//},
		//{//45���
		//	{"�������"},
		//	{"�������"}
		//},
		//{//46���
		//	{"��������"},
		//	{"��������"}
		//}
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