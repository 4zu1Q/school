//----------------------------//
// ���[�e�B���e�B�i�֗��j�֐��Q
//----------------------------//

#pragma once

// ��
#define PI    3.1415926535897932384626433832795f

// �X�N���[���T�C�Y.
#define SCREEN_W 640
#define SCREEN_H 480

#define LIMIT_TIME_COUNT	30		// �Q�[���̐�������.
#define STATE_CHANGE_WAIT	500		// �X�e�[�g�؂�ւ��E�F�C�g(�~���b).

// ���.
enum STATE
{
	STATE_TITLE,		// �^�C�g��.
	STATE_GAME,			// �Q�[����.
	STATE_CLEAR,		// �N���A.
	STATE_GAMEOVER,		// �Q�[���I�[�o�[.
	STATE_NUM			// �ԕ�.
};

// �w�肳�ꂽ�S������̕����擾.
int GetDrawStringWidthFull(char* str);

// �f�B�O���[�����W�A���ɕϊ�
float GetRadian(float degree);
