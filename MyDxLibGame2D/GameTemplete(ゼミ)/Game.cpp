#include "DxLib.h"
#include "Utility.h"
#include "GameObject.h"
#include "Shot.h"
#include "BG.h"
#include "UI.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

//----------------------------//
// �Q�[�����̂��̂̊֐��Q.
//----------------------------//
// ������.
void InitGame(Game& game)
{
	game.gameStartTime = 0;
	game.state = STATE_TITLE;
}

// �Q�[���X�^�[�g���̏�����
void InitGameStart(Game& game)
{
	game.gameStartTime = GetNowCount();

	InitUI(game.ui);
	InitPlayer(game.player);
	InitEnemy(game.enemy);

	// �O���t�B�b�N�����[�h���ăT�C�Y���擾.
	int bgGraph = game.bg[0].obj.graph;
	if (bgGraph < 0)
	{
		// ���ӁI��ʂ̃T�C�Y�Ɣw�i�摜�̃T�C�Y�͈ꏏ����Ȃ��ƃ_��
		bgGraph = LoadGraph("data/texture/FancyBG_back.png");
	}
	for (int i = 0; i < BG_NUM; i++)
	{
		InitBG(game.bg[i], bgGraph, i);
	}
}

// �X�e�[�g�؂�ւ�.
void ChangeGameState(STATE state, Game& game)
{
	// �����ɐ؂�ւ�肷����̂ŁA������Ǝ��Ԃ��~�߂�.
	WaitTimer(STATE_CHANGE_WAIT);

	// �X�e�[�g���؂�ւ�����u�Ԃ̓L�[��������������Z�b�g.
	game.keyOn = false;
	game.keyRelease = false;

	game.state = state;

	// �X�e�[�g���؂�ւ�����u�ԁA�K�v�Ȃ珉�����Ȃǂ̏������s��
	switch (game.state)
	{
		// �^�C�g��.
	case STATE_TITLE:
		break;
		// �Q�[����.
	case STATE_GAME:
		InitGameStart(game);
		break;
		// �N���A���.
	case STATE_CLEAR:
		break;
		// �Q�[���I�[�o�[.
	case STATE_GAMEOVER:
		break;
	default:
		break;
	}
}

// �A�b�v�f�[�g.
void UpdateGame(Game& game)
{
	// �L�[�������u�Ԃ����.
	if (game.keyOn)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 0)
		{
			game.keyOn = false;
			game.keyRelease = true;
		}
	}
	else if (game.prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		game.keyRelease = false;
		game.keyOn = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		game.prevKeyOn = true;
	}
	else
	{
		game.prevKeyOn = false;
	}

	// �X�e�[�g���Ƃɏ������킯��.
	switch (game.state)
	{
		// �^�C�g��.
	case STATE_TITLE:
		// �L�[���͂���������Q�[���J�n�̏�Ԃ�
		if (game.keyRelease)
		{
			ChangeGameState(STATE_GAME, game);
		}
		break;
		// �Q�[����.
	case STATE_GAME:
		UpdatePlayer(game.player, game.enemy);
		UpdateEnemy(game.enemy, game.player);
		for (int i = 0; i < BG_NUM; i++)
		{
			UpdateBG(game.bg[i]);
		}

		// �G�����񂾂�N���A��Ԃ�
		if (game.enemy.life <= 0)
		{
			ChangeGameState(STATE_CLEAR, game);
		}
		// �v���C���[�����ʂ����Ԑ؂�ŃQ�[���I�[�o�[
		else if (GetNowCount() - game.gameStartTime > LIMIT_TIME_COUNT * 1000 || game.player.life <= 0)
		{
			ChangeGameState(STATE_GAMEOVER, game);
		}
		break;
		// �N���A���.
	case STATE_CLEAR:
		// �L�[�������ꂽ��^�C�g����
		if (game.keyRelease)
		{
			ChangeGameState(STATE_TITLE, game);
		}
		break;
		// �Q�[���I�[�o�[.
	case STATE_GAMEOVER:
		// �L�[�������ꂽ��^�C�g����
		if (game.keyRelease)
		{
			ChangeGameState(STATE_TITLE, game);
		}
		break;
	default:
		break;
	}
}

// �Q�[���`��
void DrawGame(Game& game)
{
	// �e�`��֐����Ă�.
	// UI�ȊO�̓Q�[���������`�悷��
	if (game.state == STATE_GAME)
	{
		for (int i = 0; i < BG_NUM; i++)
		{
			DrawBG(game.bg[i]);
		}
		DrawPlayer(game.player);
		DrawEnemy(game.enemy);
	}
	DrawUI(game.ui, game);
}
