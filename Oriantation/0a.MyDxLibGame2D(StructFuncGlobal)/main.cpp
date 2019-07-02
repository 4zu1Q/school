//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"

// �v���C���[�\����
struct Player
{
	VECTOR	pos;
	int		graph;
};

// �G�l�~�[�\����
struct Enemy
{
	VECTOR	pos;
	int		graph;
	bool	rightMove;	// �G�l�~�[���E�ړ����Ă��邩�ǂ����̃t���O
};

// �V���b�g�\����
struct Shot
{
	int		lifeCounter;	// �V���b�g�̐����Ă��鎞�ԃJ�E���^
	VECTOR	dir;
	int		graph;
	VECTOR	pos;
	bool	isAlive;		// �e����ʏ�ɑ��݂��Ă��邩
};

// �ϐ��Q
Player player;
Enemy enemy;
Shot shot;

// �v���C���[�̏�����
void InitPlayer()
{
	// �v���C���[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	player.graph = LoadGraph("data/texture/player.png");
	player.pos.x = 288;
	player.pos.y = 400;
}

// �v���C���[�̍X�V
void UpdatePlayer()
{
	// ���L�[�������Ă�����v���C���[���ړ�������
	VECTOR direction = VGet(0, 0, 0);	// direction = (0,0,0)
	float playerSpeed = 5.0f;
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		direction = VAdd(direction, VGet(0, -1, 0)); // direction += (0,-1,0) 
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		direction = VAdd(direction, VGet(0, 1, 0)); // direction += (0,1,0) 
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		direction = VAdd(direction, VGet(-1, 0, 0)); // direction += (-1,0,0) 
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		direction = VAdd(direction, VGet(1, 0, 0)); // direction += (1,0,0) 
	}
	if (VSize(direction) > 0)						// �������[�����傫��������
	{
		direction = VNorm(direction);				// direction�̒������P�ɐ��K��
	}

	// �������P�ɂȂ���direction��speed��������
	VECTOR velocity = VScale(direction, playerSpeed);	// velocity = direction * playerSpeed

	player.pos = VAdd(player.pos, velocity); // player.pos = player.pos + velociity

	// �e�̔��ˏ���
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
		if (shot.isAlive == false)
		{
			int Bw, Bh, Sw, Sh;

			// �v���C���[�ƒe�̉摜�̃T�C�Y�𓾂�
			GetGraphSize(player.graph, &Bw, &Bh);
			GetGraphSize(shot.graph, &Sw, &Sh);

			// �ei�̈ʒu���Z�b�g�A�ʒu�̓v���C���[�̒��S�ɂ���
			shot.pos.x = (Bw - Sw) / 2 + player.pos.x;
			shot.pos.y = (Bh - Sh) / 2 + player.pos.y;

			// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ��ɂP��������
			shot.isAlive = true;
			shot.lifeCounter = 0;
		}
	}

	// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (player.pos.x < 0)
	{
		player.pos.x = 0;
	}
	if (player.pos.x > 640 - 64)
	{
		player.pos.x = 640 - 64;
	}
	if (player.pos.y < 0)
	{
		player.pos.y = 0;
	}
	if (player.pos.y > 480 - 64)
	{
		player.pos.y = 480 - 64;
	}

	// �v���C���[��`��
	DrawGraph((int)(player.pos.x), (int)(player.pos.y), player.graph, FALSE);
}

// �G�l�~�[�̏�����
void InitEnemy()
{
	// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	enemy.graph = LoadGraph("data/texture/enemy.png");
	enemy.pos.x = 0;
	enemy.pos.y = 50;

	// �E�ړ����Ă��邩�ǂ����̃t���O��true��
	enemy.rightMove = true;
}

// �G�l�~�[�̍X�V
void UpdateEnemy()
{
	// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
	VECTOR enemyDirection = VGet(0, 0, 0);
	float enemySpeed = 3.0f;
	if (enemy.rightMove == true)
	{
		enemyDirection = VAdd(enemyDirection, VGet(1, 0, 0));
	}
	else
	{
		enemyDirection = VAdd(enemyDirection, VGet(-1, 0, 0));
	}
	if (VSize(enemyDirection) > 0)
	{
		enemyDirection = VNorm(enemyDirection);
	}
	VECTOR enemyVelocity = VScale(enemyDirection, enemySpeed);
	enemy.pos = VAdd(enemy.pos, enemyVelocity);

	// �G�l�~�[����ʒ[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
	if (enemy.pos.x > 576)
	{
		enemy.pos.x = 576;
		enemy.rightMove = false;
	}
	else if (enemy.pos.x < 0)
	{
		enemy.pos.x = 0;
		enemy.rightMove = true;
	}

	// �G�l�~�[��`��
	DrawGraph((int)enemy.pos.x, (int)enemy.pos.y, enemy.graph, FALSE);
}

// �V���b�g�̏�����
void InitShot()
{
	// �V���b�g�̃O���t�B�b�N���������Ƀ��[�h.
	shot.graph = LoadGraph("data/texture/shot.png");

	shot.lifeCounter = 0;		// �V���b�g�̐����Ă��鎞�ԃJ�E���^
	shot.dir = VGet(0, 0, 0);
	shot.isAlive = false;		// �e����ʏ�ɑ��݂��Ă��邩
}

// �V���b�g�̍X�V
void UpdateShot()
{
	// ���@�̒e�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e��true(���݂���)�̏ꍇ�̂ݍs�� )
	if (shot.isAlive == true)
	{
		// �t���[�����ƂɃJ�E���g��������
		++shot.lifeCounter;

		// �ei���P�U�h�b�g��Ɉړ�������
		float shotSpeed = 16.0f;

		// ������Ă���15�t���[���̊Ԃ�shot.dir��G�̕����ɂ���
		if (shot.lifeCounter <= 15)
		{
			shot.dir = VSub(enemy.pos, shot.pos);	// enemy.pos - shot.pos
		}

		if (VSize(shot.dir) > 0)
		{
			shot.dir = VNorm(shot.dir);
		}
		VECTOR shotVelocity = VScale(shot.dir, shotSpeed);
		shot.pos = VAdd(shot.pos, shotVelocity);

		// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
		if (shot.pos.y < -80)
		{
			shot.isAlive = false;
		}

		// ��ʂɒei��`�悷��
		DrawGraph((int)shot.pos.x, (int)shot.pos.y, shot.graph, FALSE);
	}
}

//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------
// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(640, 480, 16);		// �𑜓x��640*480�Acolor��16bit�ɐݒ�.
	ChangeWindowMode(TRUE);			// �E�C���h�E���[�h��.

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);
	
	InitPlayer();	// �v���C���[�̏�����
	InitEnemy();	// �G�l�~�[�̏�����
	InitShot();		// �V���b�g�̏�����

	// �Q�[�����[�v.
	while (1)
	{
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen();

		UpdatePlayer();	// �v���C���[�̍X�V
		UpdateEnemy();	// �G�l�~�[�̍X�V
		UpdateShot();	// �e�̍X�V

		// ����ʂ̓��e��\��ʂɃR�s�[����i�`��̊m��j.
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0)
		{
			break;
		}
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}