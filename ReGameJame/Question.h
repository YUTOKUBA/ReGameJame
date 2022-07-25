#pragma once
#define HARF_WITHD 240;
#define WORD_COUNT 5;			//一問の選択肢の文字数
#define QUESTION_TWO_CHOICES 2;			//二択
#define PROPOSING_A_QUESTION 10;		//出題数
#define ALL_QUESTION 20;				//全問題数

class Quest {
private:

	char Question[10][2][5];				//出題する問題の配列
	char Question_Original[10][2][5];		//正誤比較用の問題配列
	char All_Quest[20][2][9] =				//全問題
	{
		{//1問目
			{"あいす\0\0"},
			{"うすい\0\0"}
		},
		{//2問目
			{"そうたい"},
			{"あんたい"} 
		},
		{//3問目
			{},
			{}
		}
	};

	int QCount;			//現在問題数のカウント
	int RandLog[10];	//乱数格納配列　　一回選んだ問題をまた選ばないように

public:
	Quest();

	~Quest();

	void Init();

	bool Answer_judge();		//正誤判定
	void Question_input();		//全問題から出題する問題の配列に問題を格納する
	void Question_select();		//乱数で全問題から出題する問題に格納する配列の添え字を抽選する
	void DrawQuestion();		//問題描画


	};

	extern Quest QUESTION;