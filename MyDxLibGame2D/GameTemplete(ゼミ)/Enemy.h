// �G�l�~�[
#pragma once

// �v���g�^�C�v�錾
struct GameObject;
struct Player;
struct Shot;

// �萔
#define ENEMY_SPEED			3		// �G�̃X�s�[�h.
#define ENEMY_LIFE			10		// �G�̃��C�t.

#define ENEMY_SHOT			3		// �G�V���b�g�̍ő吔.
#define ENEMY_SHOT_POWER	1		// �G�V���b�g�̈З�.
#define ENEMY_SHOT_SPEED	5		// �G�V���b�g�̃X�s�[�h.
#define ENEMY_SHOT_INTERVAL	10		// �G�V���b�g�̔��˃C���^�[�o��.

// �G�l�~�[.
struct Enemy
{
	GameObject	obj;
	bool	damageFlag = false;
	int		damageCounter = 0;
	int		damageGraph = -1;
	int		life = 0;

	Shot	shot[ENEMY_SHOT];

	// �G�V���b�g�̃C���^�[�o����ݒ肷��J�E���^�[
	int shotIntervalCount = 0;

	// �E�ړ����Ă��邩�ǂ����̃t���O�����Z�b�g
	bool rightMove = true;
};

// ������.
void InitEnemy(Enemy& enemy);

// �A�b�v�f�[�g.
void UpdateEnemy(Enemy& enemy, Player& player);

// �`��.
void DrawEnemy(Enemy& enemy);