#include "DxLib.h"
#include "SceneMgr.h"
#include"Input.h"

int FontHandle1;
int FontHandle2;

//�X�V

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�ύX
	DxLib_Init(); //DX���C�u����������
	SetDrawScreen(DX_SCREEN_BACK); //����ʐݒ�
	SceneMgr_Initialize(); 

	FontHandle1 = CreateFontToHandle(NULL, 32, 3, DX_FONTTYPE_NORMAL);
	FontHandle2 = CreateFontToHandle(NULL, 55, 3, DX_FONTTYPE_NORMAL);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) { //��ʍX�V &���b�Z�[�W����& ��ʏ���
		InputKey();
		SceneMgr_Update(); //�X�V
		SceneMgr_Draw(); //�`��
	}
	SceneMgr_Finalize();
	DxLib_End(); // DX���C�u�����I������
	return 0;
}