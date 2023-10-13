#pragma once

#include <functional>

class EnemyParam;
class EnemyParamModel;
class EnemyUiHp;

// OnDamage�֐��̊֐��|�C���^��`
typedef std::function<void(int)> OnDamageDelegate;

/// <summary>
/// Enemy��UI�Ƃ�܂Ƃ� (Controller, Presenter)
/// ���f���ł���EnemyParam�������R���g���[���\�����A���ڂ̏��������͍s��Ȃ�
/// </summary>
class EnemyParamUI
{
public:
	const EnemyParam& GetParam() const { return paramModel.GetParam(); }
	void Draw();
	void OnDamage(int damage);

private:
	EnemyParamModel paramModel;
	EnemyUiHp hpUi;
};

