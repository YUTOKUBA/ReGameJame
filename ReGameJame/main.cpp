#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

//�X�V

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�ύX
	DxLib_Init(); //DX���C�u����������
	SetDrawScreen(DX_SCREEN_BACK); //����ʐݒ�
	SceneMgr_Initialize(); //
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) { //��ʍX�V &���b�Z�[�W����& ��ʏ���
		InputKey();
			SceneMgr_Update(); //�X�V
		SceneMgr_Draw(); //�`��
	}
	SceneMgr_Finalize();
	DxLib_End(); // DX���C�u�����I������
	return 0;
}