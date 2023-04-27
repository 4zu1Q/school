#pragma once

/// <summary>
/// �G�l�~�[�̊��ɂȂ�N���X
/// </summary>
class EnemyBase
{
public:
	int GetLife() const { return life; }
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetW() const { return w; }
	int GetH() const { return h; }

	void Draw() const;	// �`��
	void OnDamage();	// �_���[�W���󂯂�

	virtual void Init();		// ������
	virtual void Update();		// �A�b�v�f�[�g

protected:
	virtual void SetInitializeData() = 0;
	virtual void Move();

	int		x;
	int		y;
	int		graph;
	bool	damageFlag;
	int		damageCounter;
	int		damageGraph;
	int		w;
	int		h;
	int		life;
	int     speed;
	int		speedUpLifeLimit;
	const char* enemyGlaphStr;

	// �G�l�~�[���E�ړ����Ă��邩�ǂ���
	bool	rightMove;
};

