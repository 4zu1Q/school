#include "GameObject.h"
#include "BG.h"
#include "DxLib.h"

// ������.
void InitBG(BG& bg, int graph, int index)
{
	bg.obj.graph = graph;
	GetGraphSize(bg.obj.graph, &bg.obj.w, &bg.obj.h);
	bg.obj.pos.x = bg.obj.w * 0.5f;
	bg.obj.pos.y = (float)(index * bg.obj.h);
}

// �A�b�v�f�[�g.
void UpdateBG(BG& bg)
{
	// �w�i�c�X�N���[��.
	bg.obj.pos.y += BG_SCROLL_SPEED;

	// �w�i��y���W���w�i����]�v�ɉ��ɂȂ������Ɉړ�.
	if (bg.obj.pos.y > bg.obj.h + bg.obj.h * 0.5f)
	{
		bg.obj.pos.y -= bg.obj.h * 2;
	}
}

// �`��.
void DrawBG(BG& bg)
{
	DrawGameObject(bg.obj, bg.obj.graph);
}