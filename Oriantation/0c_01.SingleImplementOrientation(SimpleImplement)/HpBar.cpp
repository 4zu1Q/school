#include "HpBar.h"
#include "DxLib.h"

void HpBar::Init()
{
	graph = LoadGraph("data/texture/hp.png");
}

void HpBar::Update()
{
	// �L�[���͂������ꂽ�u�Ԃ����Ƃ�BHP�����炷
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (prevHitKey == false)
		{
			--hp;
			prevHitKey = true;
		}
	}
	else
	{
		prevHitKey = false;
	}
}

void HpBar::Draw()
{
	// ��ʃT�C�Y�ɍ��킹�āAHP�Q�[�W��\������
	printfDx("hp:%d\n", hp);
	DrawExtendGraph(
		HpBarSideSpace,
		HpBarStartY,
		(int)((ScreenW - (HpBarSideSpace * 2)) * ((float)hp / HpMax)),
		HpBarStartY + HpBarHight,
		graph,
		TRUE);
}
