#include "StateMachine.h"

/// <summary>
/// �X�e�[�g�̒ǉ�
/// </summary>
template <class TState>
void StateMachine<TState>::AddState(TState state, Delegate enter, Delegate update, Delegate exit)
{
	// FIXME: �d���l��
	StateDelegateSet set;
	set.state = state;
	set.enter = enter;
	set.update = update;
	set.exit = exit;
	stateFuncMap.emplace(state, set);
}

/// <summary>
/// �X�e�[�g�̕ύX
/// </summary>
template <class TState>
void StateMachine<TState>::ChangeState(TState state)
{
	// ���O��state��exit���Ă�ŃX�e�[�g���X�V
	if (currentState != state)
	{
		stateFuncMap[currentState].exit();
		currentState = state;
		stateFuncMap[currentState].enter();
	}
}

/// <summary>
/// �X�V
/// </summary>
template <class TState>
void StateMachine<TState>::Update() const
{
	stateFuncMap[currentState].update();
}