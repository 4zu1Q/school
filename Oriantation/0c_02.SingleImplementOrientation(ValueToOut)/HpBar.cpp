#include "HpBar.h"
#include "DxLib.h"

void HpBar::Init()
{
	graph = LoadGraph("data/texture/hp.png");
}

void HpBar::Update()
{
	// �����Ȃ�.
}

void HpBar::Draw(int hp, int ScreenW, int HpMax)
{
	// ��ʃT�C�Y�ɍ��킹�āAHP�Q�[�W��\������
	printfDx("hp:%d\n", hp);
	if (hp > 0)
	{
		DrawExtendGraph(
			HpBarSideSpace,
			HpBarStartY,
			(int)((ScreenW - (HpBarSideSpace)) * ((float)hp / HpMax)),
			HpBarStartY + HpBarHight,
			graph,
			TRUE);
	}
}
