#pragma once

// �v���g�^�C�v�錾
struct GameObject;

// MEMO:�V���b�g���̂�GameObject target������Ĉ�莞�Ԓǂ�������������Ƃ�
struct Shot
{
	GameObject	obj;
	int		power = 0;
	bool	visibleFlag = false;
};

// ������.
void InitShot(Shot& shot, int shotGraph, int shotW, int shotH, float angle, float speed, int power);

// �V���b�g�̈ړ�.
void MoveShot(Shot& shot);

// �V���b�g�̓����蔻��`�F�b�N
bool IsHitShot(Shot& shot, GameObject& target);

// �`��.
void DrawShot(Shot& shot);