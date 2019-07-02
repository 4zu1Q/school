// �v���C���[
#include "GameObject.h"
#include "Shot.h"
#include "Enemy.h"
#include "Player.h"
#include "Utility.h"
#include "DxLib.h"

//----------------------------//
// �v���C���[�֐��Q.
//----------------------------//
// ������.
void InitPlayer(Player& player)
{
	// �v���C���[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	if (player.obj.graph < 0)
	{
		player.obj.graph = LoadGraph("data/texture/EpicPlayer.png");
	}
	player.obj.pos.x = SCREEN_W / 2;			// ��ʂ̔����i�����j
	player.obj.pos.y = SCREEN_H - 100;		// ��ʉ�-100�̈ʒu
	player.obj.pos.z = 0;
	player.obj.speed = 0.0f;
	player.life = PLAYER_LIFE;

	// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
	player.damageFlag = false;

	// �v���C���[�̉摜�̃T�C�Y�𓾂�
	GetGraphSize(player.obj.graph, &player.obj.w, &player.obj.h);

	// �V���b�g��������
	int shotGraph = player.shot[0].obj.graph;
	int shotW = player.shot[0].obj.w;
	int shotH = player.shot[0].obj.h;
	if (shotGraph < 0)
	{
		shotGraph = LoadGraph("data/texture/SuperShot.png");
		GetGraphSize(shotGraph, &player.obj.w, &player.obj.h);
	}
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		InitShot(player.shot[i], shotGraph, shotW, shotH, 0, PLAYER_SHOT_SPEED, PLAYER_SHOT_POWER);
	}
}

// �A�b�v�f�[�g.
void UpdatePlayer(Player& player, Enemy& enemy)
{
	// ���L�[�������Ă�����v���C���[���ړ�������
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		player.obj.dir = VGet(-1, 0, 0);
		player.obj.speed = PLAYER_SPEED;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		player.obj.dir = VGet(1, 0, 0);
		player.obj.speed = PLAYER_SPEED;
	}
	else
	{
		player.obj.speed = 0.0f;
	}
	MoveGameObject(player.obj);

	// �e�̔��ˏ���
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		// �V���b�g�̔��˃C���^�[�o�����Ȃ��Ȃ��Ă����猂�Ă�
		if (player.shotIntervalCount == 0)
		{
			// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
			for (int i = 0; i < PLAYER_SHOT; i++)
			{
				// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
				if (player.shot[i].visibleFlag == false)
				{
					// �ei�̈ʒu���Z�b�g�A�ʒu�̓v���C���[�̒��S�ɂ���
					player.shot[i].obj.pos.x = (player.obj.w - player.shot[i].obj.w) / 2 + player.obj.pos.x;
					player.shot[i].obj.pos.y = (player.obj.h - player.shot[i].obj.h) / 2 + player.obj.pos.y;

					// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
					player.shot[i].visibleFlag = true;

					// ������ݒ�
					player.shot[i].obj.dir = VGet(0, -1, 0);

					// ��e���o�����̂Œe���o�����[�v���甲���܂�
					break;
				}
			}

			// �C���^�[�o���p�̃J�E���^�[��ݒ�.
			player.shotIntervalCount = PLAYER_SHOT_INTERVAL;
		}
	}

	// �V���b�g�֘A
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// �V���b�g�ړ�
		MoveShot(player.shot[i]);

		// �v���C���[�̃V���b�g�ƓG�̓����蔻��
		if (IsHitShot(player.shot[i], enemy.obj))
		{
			// �������Ă���V���b�g�p���[���_���[�W��^����
			enemy.life -= player.shot[i].power;

			enemy.damageCounter = 0;
			enemy.damageFlag = true;

			// �A���œ�����Ȃ��悤�ɔ�����
			break;
		}
	}

	if (player.shotIntervalCount != 0)
	{
		--player.shotIntervalCount;
	}

	// �v���C���[����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (player.obj.pos.x < player.obj.w * 0.5f)
	{
		player.obj.pos.x = player.obj.w * 0.5f;
	}
	if (player.obj.pos.x > SCREEN_W - player.obj.w * 0.5f)
	{
		player.obj.pos.x = (float)(SCREEN_W - player.obj.w * 0.5f);
	}
	if (player.obj.pos.y < 0)
	{
		player.obj.pos.y = 0;
	}
	if (player.obj.pos.y > SCREEN_H - player.obj.w * 0.5f)
	{
		player.obj.pos.y = (float)(SCREEN_H - player.obj.h * 0.5f);
	}

	// �_���[�W���󂯂Ă��邩�ǂ����ŏ����𕪊�
	if (player.damageFlag == true)
	{
		player.damageCounter++;

		if (player.damageCounter == 5)
		{
			// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
			player.damageFlag = false;
		}
	}
}

// �`��.
void DrawPlayer(Player& player)
{
	if (player.damageFlag == true)
	{
		// �_���[�W���󂯂Ă���ꍇ�͓������\�����Ȃ�
	}
	else
	{
		DrawGameObject(player.obj, player.obj.graph);
	}

	// �V���b�g���\��
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		DrawShot(player.shot[i]);
	}
}
