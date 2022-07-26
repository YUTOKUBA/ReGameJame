#include"End.h"
#include"SceneMgr.h"
#include"DxLib.h"

static int mImageBackGround;	//�摜�n���h���i�[�p�ϐ�
static int mImageBall;	//�摜�n���h���i�[�p�ϐ�
static int StopTime;

//������
void End_Initialize() {
	mImageBackGround = LoadGraph("images/End_BackGround.png");	//�摜�̃��[�h
	mImageBall = LoadGraph("images/End_Ball.png");	//�摜�̃��[�h
	StopTime = 0;
}

//�I������
void End_Finalize() {
	DeleteGraph(mImageBackGround);//�摜�̉��
	DeleteGraph(mImageBall);//�摜�̉��
}

//�X�V

//�`��
void End_Draw() {

	DrawGraph(0, 0, mImageBackGround, FALSE);
	//DrawGraph(0, 0, mImageBall, TRUE);
	DrawRotaGraph(90, 300, 0.2f, 0, mImageBall, TRUE);

	SetFontSize(50);
	DrawString(40, 180, "Thank you for Playing", 0xffffff, 0);

	//�^�C���̉ΎR�������I���i3�b��j
	if (++StopTime > 180) {
		DxLib_End();
	}
}