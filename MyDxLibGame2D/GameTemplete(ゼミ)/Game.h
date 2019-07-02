#pragma once

#define	BG_NUM				3		// �w�i�̌�.

// �v���g�^�C�v�錾
enum STATE;
struct Player;
struct Enemy;
struct BG;
struct UI;

// �Q�[���\����
struct Game
{
	Player	player;
	Enemy	enemy;
	BG		bg[BG_NUM];
	UI		ui;

	int gameStartTime = 0;
	STATE state;
	int prevKeyInput = 0;
	bool keyOn = false;
	bool prevKeyOn = false;
	bool keyRelease = false;
};

//----------------------------//
// �Q�[�����̂��̂̊֐��Q.
//----------------------------//
// ������.
void InitGame(Game& game);

// �Q�[���X�^�[�g���̏�����
void InitGameStart(Game& game);

// �X�e�[�g�؂�ւ�.
void ChangeGameState(STATE state, Game& game);

// �A�b�v�f�[�g.
void UpdateGame(Game& game);

// �Q�[���`��
void DrawGame(Game& game);