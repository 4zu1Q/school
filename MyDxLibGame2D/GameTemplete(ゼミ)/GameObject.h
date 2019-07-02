// �Q�[���I�u�W�F�N�g
#pragma once
#include "DxLib.h"

struct GameObject
{
	int		graph = -1;
	VECTOR	pos = VGet(0, 0, 0);
	VECTOR	dir = VGet(0, 1, 0);
	float	speed = 0.0f;
	int		w = 0;
	int		h = 0;
	float	angle = 0;
	float	scale = 1.0f;
};

// �Q�[���I�u�W�F�N�g�ړ�
void MoveGameObject(GameObject& obj);

// �Q�[���I�u�W�F�N�g�`��B�Ⴄ�摜���`��ł���悤��graph���������Ă���
void DrawGameObject(GameObject& obj, int graph);