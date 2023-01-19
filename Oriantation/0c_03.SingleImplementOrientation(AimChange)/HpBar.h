#pragma once
class HpBar
{
public:
	void Init(float firstDrawHp);
	void Update();
	// void SetHp(float hp);		// HP�̐ݒ�H�񕜂⏉�����ɂ��g����́H
	void OnDamage(float afterHp);	// �_���[�W���󂯂����B�񕜂Ə����𕪂�����B
	void Draw(int ScreenW, float HpMax);

private:
	const int HpBarStartY = 20;
	const int HpBarHight = 20;
	const int HpBarSideSpace = 20;
	const float AimHpSpeed = 0.02f;

	int graph = -1;
	float drawHp = 0;
	float aimHp = 0;
};

