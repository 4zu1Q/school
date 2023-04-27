#pragma once

/// <summary>
/// �G�l�~�[�̊��ɂȂ�N���X
/// </summary>
class EnemyBase
{
public:
	// �G�������p�f�[�^
	struct Data
	{
		const char* graphPath;
		int			firstX;
		int			firstY;
		int			life;
		int			speed;
		int			speedUpLifeLimit;
	};

	int GetLife() const { return life; }
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetW() const { return w; }
	int GetH() const { return h; }

	void Draw() const;	// �`��
	void OnDamage();	// �_���[�W���󂯂�

	void Init(const Data& srcData);		// ������
	virtual void Update();		// �A�b�v�f�[�g

protected:
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

	// �G�l�~�[���E�ړ����Ă��邩�ǂ���
	bool	rightMove;

	const Data* data;	// �f�[�^�ւ̎Q��
};

