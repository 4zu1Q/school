// �Q�[���I�u�W�F�N�g
#include "GameObject.h"

// �Q�[���I�u�W�F�N�g�ړ�
void MoveGameObject(GameObject& obj)
{
	VECTOR velocity = VScale(obj.dir, obj.speed);
	obj.pos = VAdd(obj.pos, velocity);
}

// �Q�[���I�u�W�F�N�g�`��B�Ⴄ�摜���`��ł���悤��graph���������Ă���
void DrawGameObject(GameObject& obj, int graph)
{
	DrawRotaGraph((int)obj.pos.x, (int)obj.pos.y,
		obj.scale,
		obj.angle,
		graph, TRUE);
}
