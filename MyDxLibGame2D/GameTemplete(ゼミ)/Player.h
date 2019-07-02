// �v���C���[
#pragma once

// �v���g�^�C�v�錾
struct GameObject;
struct Enemy;
struct Shot;

// �萔
#define PLAYER_SPEED			3		// �v���C���[�̃X�s�[�h.
#define PLAYER_LIFE				10		// �v���C���[�̃��C�t.

#define PLAYER_SHOT				3		// �V���b�g�̍ő吔.
#define PLAYER_SHOT_POWER		1		// �V���b�g�̈З�.
#define PLAYER_SHOT_SPEED		5		// �ʏ�V���b�g�̃X�s�[�h.
#define PLAYER_SHOT_INTERVAL	10		// �ʏ�V���b�g�̔��˃C���^�[�o��.

// �v���C���[.
struct Player
{
	GameObject	obj;
	int		life = 0;
	bool	damageFlag = false;
	int		damageCounter = 0;

	Shot	shot[PLAYER_SHOT];

	// �V���b�g�̃C���^�[�o����ݒ肷��J�E���^�[
	int shotIntervalCount = 0;
};

// ������.
void InitPlayer(Player& player);

// �A�b�v�f�[�g.
void UpdatePlayer(Player& player, Enemy& enemy);

// �`��.
void DrawPlayer(Player& player);
