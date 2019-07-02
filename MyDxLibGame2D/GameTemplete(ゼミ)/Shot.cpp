// �V���b�g
#include "GameObject.h"
#include "Shot.h"
#include "Utility.h"

//----------------------------//
// �V���b�g�֐��Q.
//----------------------------//
// ������.
void InitShot(Shot& shot, int shotGraph, int shotW, int shotH, float angle, float speed, int power)
{
	// �V���b�g�̃O���t�B�b�N���������Ƀ��[�h.
	shot.obj.graph = shotGraph;

	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
	shot.visibleFlag = false;
	shot.obj.w = shotW;
	shot.obj.h = shotH;
	shot.obj.angle = angle;
	shot.obj.speed = speed;
	shot.power = power;
}

// �V���b�g�̈ړ�.
void MoveShot(Shot& shot)
{
	// �e�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e��true(���݂���)�̏ꍇ�̂ݍs�� )
	if (shot.visibleFlag == true)
	{
		// �e���ړ�������
		MoveGameObject(shot.obj);

		// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false(���݂��Ȃ�)��������
		if (shot.obj.pos.y < 0 - shot.obj.h * 0.5f
			|| shot.obj.pos.y > SCREEN_H + shot.obj.h * 0.5f
			|| shot.obj.pos.x < 0 - shot.obj.w * 0.5f
			|| shot.obj.pos.x > SCREEN_W + shot.obj.w * 0.5f)
		{
			shot.visibleFlag = false;
		}
	}
}
// �V���b�g�̓����蔻��`�F�b�N
bool IsHitShot(Shot& shot, GameObject& target)
{
	bool isHit = false;
	// �e�̂����蔻��.
	if (shot.visibleFlag == 1)
	{
		float shotLeft = shot.obj.pos.x - shot.obj.w * 0.5f;
		float shotRight = shot.obj.pos.x + shot.obj.w * 0.5f;
		float shotTop = shot.obj.pos.y - shot.obj.h * 0.5f;
		float shotBottom = shot.obj.pos.y + shot.obj.h * 0.5f;
		float targetLeft = target.pos.x - target.w * 0.5f;
		float targetRight = target.pos.x + target.w * 0.5f;
		float targetTop = target.pos.y - target.h * 0.5f;
		float targetBottom = target.pos.y + target.h;

		if (((shotLeft > targetLeft && shotLeft < targetRight) ||
			(targetLeft > shotLeft && targetLeft < shotRight)) &&
			((shotTop > targetTop && shotTop < targetBottom) ||
			(targetTop > shotTop && targetTop < shotBottom)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shot.visibleFlag = 0;

			// �������Ă�t���O�����Ă�
			isHit = true;
		}
	}
	return isHit;
}

// �`��.
void DrawShot(Shot& shot)
{
	if (shot.visibleFlag == true)
	{
		// ��ʂɒei��`�悷��
		DrawGameObject(shot.obj, shot.obj.graph);
	}
}
