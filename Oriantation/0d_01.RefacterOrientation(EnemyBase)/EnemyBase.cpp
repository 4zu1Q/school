// 2023 Takeru Yui All Rights Reserved.
#include "DxLib.h"
#include "EnemyBase.h"

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