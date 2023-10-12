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

private:
	class StateDelegateSet
	{
	public:
		TState state;
		Delegate enter, update, exit;
	};

	TState currentState;
	std::map<TState, StateDelegateSet> stateFuncMap;

public:
	/// <summary>
	/// �X�e�[�g�̒ǉ�
	/// </summary>
	void AddState(TState state, Delegate enter, Delegate update, Delegate exit)
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
	void ChangeState(TState state)
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
	void Update()
	{
		stateFuncMap[currentState].update();
	}

	// �X�e�[�g�̎擾
	TState GetCurrentState() const { return currentState; }
};

