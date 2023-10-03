#pragma once

#include "EnemyUiHp.h"
#include "EnemyParam.h"

/// <summary>
/// Enemy��UI�Ƃ�܂Ƃ� (Controller, Presenter)
/// ���f���ł���EnemyParam�������R���g���[���\�����A���ڂ̏��������͍s��Ȃ�
/// </summary>
class EnemyParamUI
{
public:
	const EnemyParam& GetParam() const { return param; }
	void OnChangeParam(const EnemyParam& param) { this->param = param; }
	void Draw();

private:
	EnemyParam param;
	EnemyUiHp hpUi;
};

