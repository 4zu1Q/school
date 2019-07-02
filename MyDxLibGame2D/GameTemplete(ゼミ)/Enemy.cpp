// �G�l�~�[
#include "GameObject.h"
#include "Shot.h"
#include "Enemy.h"
#include "Utility.h"
#include "DxLib.h"
#include "Player.h"

//----------------------------//
// �G�l�~�[�֐��Q.
//----------------------------//
// ������.
void InitEnemy(Enemy& enemy)
{
	// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	char* enemyGlaphStr = "data/texture/EpicEnemy.png";
	if (enemy.obj.graph < 0)
	{
		enemy.obj.graph = LoadGraph(enemyGlaphStr);
	}
	if (enemy.damageGraph < 0)
	{
		enemy.damageGraph = LoadGraph(enemyGlaphStr);
	}
	GraphFilter(enemy.damageGraph, DX_GRAPH_FILTER_HSB, 0, 0, 0, 256);
	enemy.obj.pos.x = 0;
	enemy.obj.pos.y = 50;
	enemy.obj.pos.z = 0;
	enemy.obj.speed = 0;
	enemy.obj.angle = GetRadian(180.0f);
	enemy.life = ENEMY_LIFE;

	// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
	enemy.damageFlag = false;

	// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// �V���b�g��������
	int shotGraph = enemy.shot[0].obj.graph;
	int shotW = enemy.shot[0].obj.w;
	int shotH = enemy.shot[0].obj.h;
	if (shotGraph < 0)
	{
		shotGraph = LoadGraph("data/texture/SuperEnemyShot.png");
		GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	}
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}

// �A�b�v�f�[�g.
void UpdateEnemy(Enemy& enemy, Player& player)
{
	// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
	if (enemy.rightMove == true)
	{
		enemy.obj.dir = VGet(1, 0, 0);
	}
	else
	{
		enemy.obj.dir = VGet(-1, 0, 0);
	}
	enemy.obj.speed = ENEMY_SPEED;
	MoveGameObject(enemy.obj);

	// �G�l�~�[����ʒ[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
	if (enemy.obj.pos.x > SCREEN_W - enemy.obj.w)
	{
		enemy.obj.pos.x = (float)(SCREEN_W - enemy.obj.w);
		enemy.rightMove = false;
	}
	else if (enemy.obj.pos.x < 0)
	{
		enemy.obj.pos.x = 0;
		enemy.rightMove = true;
	}

	// �G�̒e�̔��ˏ���
	// �V���b�g�̔��˃C���^�[�o�����Ȃ��Ȃ��Ă����猂��
	if (enemy.shotIntervalCount == 0)
	{
		// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
		for (int i = 0; i < ENEMY_SHOT; i++)
		{
			// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
			if (enemy.shot[i].visibleFlag == false)
			{
				// �ei�̈ʒu���Z�b�g�A�ʒu�͓G�̒��S�ɂ���
				enemy.shot[i].obj.pos.x = enemy.obj.pos.x;
				enemy.shot[i].obj.pos.y = enemy.obj.pos.y;

				// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
				enemy.shot[i].visibleFlag = true;

				// ������ݒ�
				enemy.shot[i].obj.dir = VGet(0, 1, 0);

				// ��e���o�����̂Œe���o�����[�v���甲���܂�
				break;
			}
		}

		// �C���^�[�o���p�̃J�E���^�[��ݒ�.
		enemy.shotIntervalCount = ENEMY_SHOT_INTERVAL;
	}

	if (enemy.shotIntervalCount != 0)
	{
		--enemy.shotIntervalCount;
	}

	// �V���b�g����
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		// �V���b�g�ړ�
		MoveShot(enemy.shot[i]);

		// �G�l�~�[�̃V���b�g�ƃv���C���[�̓����蔻��
		if (IsHitShot(enemy.shot[i], player.obj))
		{
			// �������Ă���V���b�g�p���[���_���[�W��^����
			player.life -= enemy.shot[i].power;

			player.damageCounter = 0;
			player.damageFlag = true;

			// �A���œ�����Ȃ��悤�ɔ�����
			break;
		}
	}

	// �_���[�W���󂯂Ă��邩�ǂ����ŏ����𕪊�
	if (enemy.damageFlag == true)
	{
		enemy.damageCounter++;

		if (enemy.damageCounter == 5)
		{
			// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
			enemy.damageFlag = false;
		}
	}
}
// �`��.
void DrawEnemy(Enemy& enemy)
{
	if (enemy.life > 0)
	{
		// �_���[�W���󂯂Ă���ꍇ�̓_���[�W���̃O���t�B�b�N��`�悷��
		if (enemy.damageFlag == true)
		{
			DrawGameObject(enemy.obj, enemy.damageGraph);
		}
		else
		{
			DrawGameObject(enemy.obj, enemy.obj.graph);
		}
	}

	// �V���b�g���\��
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		DrawShot(enemy.shot[i]);
	}
}
