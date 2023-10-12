#pragma once
#include <functional>
#include <map>

/// <summary>
/// �X�e�[�g�}�V��
/// </summary>
template <class TState> class StateMachine
{
public:
	typedef const std::function<void(void)> Delegate;

	// �X�e�[�g�̓o�^
	void AddState(TState state, Delegate enter, Delegate update, Delegate exit);

	// �X�e�[�g�̕ύX
	void ChangeState(TState state);

	// �X�V
	void Update() const;

	// �X�e�[�g�̎擾
	TState GetCurrentState() const { return currentState; }

private:
	class StateDelegateSet
	{
		TState state;
		Delegate enter, update, exit;
	};

	TState currentState;
	std::map<TState, StateDelegateSet> stateFuncMap;
};

