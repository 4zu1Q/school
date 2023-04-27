// 2023 Takeru Yui All Rights Reserved.
#include "DxLib.h"
#include "EnemyBase.h"
#include "Common.h"

/// <summary>
/// ������
/// </summary>
void EnemyBase::Init(const Data& srcData)
{
	data = &srcData;

	x = data->firstX;
	y = data->firstY;
	life = data->life;
	speed = data->speed;
	damageFlag	= false;			// �G�l�~�[�����c�߂Ă��邩�ǂ����̕ϐ��Ɂw�c�߂Ă��Ȃ��x��\��FALSE����
	rightMove	= true;

	// ���[�h
	graph		= LoadGraph(data->graphPath);
	damageGraph = LoadGraph(data->graphPath);
	
	GetGraphSize(graph, &w, &h);	// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�

	// �_���[�W���A�N�V�����ŐF�ύX���s���̂ŁA���������Ă���
	GraphFilter(damageGraph, DX_GRAPH_FILTER_HSB, 0, 0, 0, 256);
}

/// <summary>
/// �`��
/// </summary>
void EnemyBase::Draw() const
{
	if (life > 0)
	{
		// �_���[�W���󂯂Ă���ꍇ�̓_���[�W���̃O���t�B�b�N��`�悷��
		if (damageFlag == true)
		{
			DrawGraph(x, y, damageGraph, TRUE);
		}
		else
		{
			DrawGraph(x, y, graph, TRUE);
		}
	}
}

/// <summary>
/// �ړ�
/// </summary>
void EnemyBase::Move()
{
	// �G�l�~�[�̍��W���ړ����Ă�������Ɉړ�����
	if (rightMove == true)
	{
		if (life < data->speedUpLifeLimit)
		{
			x += speed * 2;
		}
		else
		{
			x += speed;
		}
	}
	else
	{
		if (life < data->speedUpLifeLimit)
		{
			x -= speed * 2;
		}
		else
		{
			x -= speed;
		}
	}
}

/// <summary>
/// �X�V
/// </summary>
void EnemyBase::Update()
{
	// �g���\��Move�N���X�����ŌĂяo�����ƂŁA�ړ��ɕ�����������
	Move();

	// �G�l�~�[����ʒ[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
	if (x > SCREEN_W - w)
	{
		x = SCREEN_W - w;
		rightMove = false;
	}
	else if (x < 0)
	{
		x = 0;
		rightMove = true;
	}

	// �_���[�W���󂯂Ă��邩�ǂ����ŏ����𕪊�
	if (damageFlag == true)
	{
		damageCounter++;

		if (damageCounter == 5)
		{
			// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
			damageFlag = false;
		}
	}
}

/// <summary>
/// �_���[�W���󂯂�
/// </summary>
void EnemyBase::OnDamage()
{
	// �G�l�~�[�̊��c�߂Ă��邩�ǂ�����ێ�����ϐ��Ɂw�c�߂Ă���x��\��TRUE����
	damageFlag = true;

	// �G�l�~�[�̊��c�߂Ă��鎞�Ԃ𑪂�J�E���^�ϐ��ɂO����
	damageCounter = 0;

	life -= 1;
}