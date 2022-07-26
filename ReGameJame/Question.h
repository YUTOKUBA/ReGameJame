#pragma once
#pragma warning(disable : 4996)
#include<string.h>

#define HARF_WITHD 240;
#define WORD_COUNT 5;			//一問の選択肢の文字数
#define QUESTION_TWO_CHOICES 2;			//二択
#define PROPOSING_A_QUESTION 10;		//出題数
#define ALL_QUESTION 20;				//全問題数
//#define RAND_MAX 9			//乱数保持の足台数（全問題から選出するランダムな引数）

class Quest {
private:

	char Question[10][2][9];				//出題する問題の配列
	char Question_Original[10][2][9];		//正誤比較用の問題配列
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
	int RandLog[10];	//乱数格納配列　　

	char A = 'あ';		//'あ'を代入するようの変数
	char Circle = '０';		//'○'を代入するようの変数

	char* Point_A = NULL;		//'あ'または'ア'のポインタを格納する変数
	char* Point_Rand = NULL;		//文字列のランダムなポインタを格納する変数
	char* Point_Circle = NULL;		//'○'のポインタを格納する変数

public:
	Quest();

	~Quest();

	void Init();

	bool Answer_judge();		//正誤判定
	void Question_input();		//全問題から出題する問題の配列に問題を格納する
	void Question_select();		//乱数で全問題から出題する問題に格納する配列の添え字を抽選する
	void DrawQuestion();		//問題描画

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