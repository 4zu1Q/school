#include "HpBar.h"
#include "DxLib.h"

void HpBar::Init(float firstDrawHp)
{
	graph = LoadGraph("data/texture/hp.png");
	drawHp = aimHp = firstDrawHp;
}

void HpBar::Update()
{
	// ���t���[���ɂ₩�ɖڕW�ɋ߂Â�
	if (drawHp != aimHp)
	{
		drawHp -= AimHpSpeed;
		// �ڕW�ɍ��v������~�߂�
		if (drawHp < aimHp)
		{
			drawHp = aimHp;
		}
	}
}

void HpBar::OnDamage(float afterHp)
{
	aimHp = afterHp;
}

void HpBar::Draw(int ScreenW, float HpMax)
{
	// ��ʃT�C�Y�ɍ��킹�āAHP�Q�[�W��\������
	printfDx("     drawHp:%f aimHp:%f\n", drawHp, aimHp);
	if (drawHp > 0.0f)
	{
		DrawExtendGraph(
			HpBarSideSpace,
			HpBarStartY,
			HpBarSideSpace + (int)((ScreenW - (HpBarSideSpace * 2)) * ((float)drawHp / HpMax)),
			HpBarStartY + HpBarHight,
			graph,
			TRUE);
	}
}
