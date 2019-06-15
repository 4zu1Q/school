//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"

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

	// �v���C���[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	VECTOR playerPos;
	int playerGraph;
	playerGraph = LoadGraph("data/texture/player.png");
	playerPos.x = 288; 
	playerPos.y = 400;

	// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	VECTOR enemyPos;
	int enemyGraph;
	enemyGraph = LoadGraph("data/texture/enemy.png");
	enemyPos.x = 0; 
	enemyPos.y = 50;

	// �G�l�~�[���E�ړ����Ă��邩�ǂ����̃t���O�����Z�b�g
	bool enemyRightMove = true;

	// �V���b�g�̃O���t�B�b�N���������Ƀ��[�h.
	int shotGraph;
	shotGraph = LoadGraph("data/texture/shot.png");

	// �V���b�g�̐����Ă��鎞�ԃJ�E���^
	int shotLifeCounter = 0;
	VECTOR shotDir = VGet(0,0,0);

	// �ʒu��������.
	VECTOR shotPos;

	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
	bool shotFlag = false;

	// �Q�[�����[�v.
	while (1)
	{
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen();

		//------------------------------//
		// �v���C���[�̑��샋�[�`��
		//------------------------------//
		{
			// ���L�[�������Ă�����v���C���[���ړ�������
			VECTOR direction = VGet(0, 0, 0);	// direction = (0,0,0)
			float playerSpeed = 5.0f;
;			if (CheckHitKey(KEY_INPUT_UP) == 1)
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

			playerPos = VAdd(playerPos, velocity); // playerPos = playerPos + velociity

			// �e�̔��ˏ���
			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
				if (shotFlag == false)
				{
					int Bw, Bh, Sw, Sh;

					// �v���C���[�ƒe�̉摜�̃T�C�Y�𓾂�
					GetGraphSize(playerGraph, &Bw, &Bh);
					GetGraphSize(shotGraph, &Sw, &Sh);

					// �ei�̈ʒu���Z�b�g�A�ʒu�̓v���C���[�̒��S�ɂ���
					shotPos.x = (Bw - Sw) / 2 + playerPos.x;
					shotPos.y = (Bh - Sh) / 2 + playerPos.y;

					// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ��ɂP��������
					shotFlag = true;
					shotLifeCounter = 0;
				}
			}

			// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if (playerPos.x < 0)
			{
				playerPos.x = 0;
			}
			if (playerPos.x > 640 - 64)
			{
				playerPos.x = 640 - 64;
			}
			if (playerPos.y < 0)
			{
				playerPos.y = 0;
			}
			if (playerPos.y > 480 - 64)
			{
				playerPos.y = 480 - 64;
			}

			// �v���C���[��`��
			DrawGraph(playerPos.x, playerPos.y, playerGraph, FALSE);
		}


		//------------------------------//
		// �G�l�~�[�̈ړ����[�`��
		//------------------------------//
		{
			// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
			VECTOR enemyDirection = VGet(0,0,0);
			float enemySpeed = 3.0f;
			if (enemyRightMove == true)
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
			enemyPos = VAdd(enemyPos, enemyVelocity);

			// �G�l�~�[����ʒ[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
			if (enemyPos.x > 576)
			{
				enemyPos.x = 576;
				enemyRightMove = false;
			}
			else if (enemyPos.x < 0)
			{
				enemyPos.x = 0;
				enemyRightMove = true;
			}

			// �G�l�~�[��`��
			DrawGraph(enemyPos.x, enemyPos.y, enemyGraph, FALSE);
		}

		//------------------------------//
		// �e�̈ړ����[�`��
		//------------------------------//
		// ���@�̒e�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e��true(���݂���)�̏ꍇ�̂ݍs�� )
		if (shotFlag == true)
		{
			// �t���[�����ƂɃJ�E���g��������
			++shotLifeCounter;

			// �ei���P�U�h�b�g��Ɉړ�������
			float shotSpeed = 16.0f;
			
			// ������Ă���15�t���[���̊Ԃ�shotDir��G�̕����ɂ���
			if (shotLifeCounter <= 15)
			{
				shotDir = VSub(enemyPos, shotPos);	// enemyPos - shotPos
			}

			if (VSize(shotDir) > 0)
			{
				shotDir = VNorm(shotDir);
			}
			VECTOR shotVelocity = VScale(shotDir, shotSpeed);
			shotPos = VAdd(shotPos, shotVelocity);

			// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
			if (shotPos.y < -80)
			{
				shotFlag = false;
			}

			// ��ʂɒei��`�悷��
			DrawGraph(shotPos.x, shotPos.y, shotGraph, FALSE);
		}

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