#include "Utility.h"
#include "UI.h"
#include "DxLib.h"
#include "GameObject.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "Game.h"

// UI������.
void InitUI(UI& ui)
{
	if (ui.hpGraph < 0)
	{
		ui.hpGraph = LoadGraph("data/texture/hp.png");
	}
	if (ui.hpBackGraph < 0)
	{
		ui.hpBackGraph = LoadGraph("data/texture/hpBack.png");
	}
}

// UI�`��.
// ��������UI���̂��\���ɂ��Ď����ōl���邱�ƁI.
void DrawUI(UI& ui, Game& game)
{
	// ���Ԃ����镶����.
	char timeNumStr[256];

	// �c�胉�C�t�����镶����.
	char lifeStr[256];

	// HP�\�����n�߂�X���W.
	int hpGraphStartX;

	// ���[�����Ƃɕ\������ς���.
	switch (game.state)
	{
		// �^�C�g��.
	case STATE_TITLE:
		SetFontSize(TITLE_FONT_SIZE);

		// ��ʃT�C�Y/2 ����@�`�悷�镶����̕�2/�A�܂��ʂ̒����ɕ�����\�����Ă���.
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(TITLE_STR) / 2, SCREEN_H / 2 + TITLE_STR_OFFSET_Y, TITLE_STR, GetColor(255, 255, 255));

		SetFontSize(PRESS_STR_FONT_SIZE);
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(STARTBUTTON_STR) / 2, SCREEN_H / 2 + PRESS_STR_OFFSET_Y, STARTBUTTON_STR, GetColor(255, 255, 255));
		break;
		// �Q�[����.
	case STATE_GAME:

		// ��������.
		SetFontSize(TIME_STR_FONT_SIZE);
		DrawString(SCREEN_W / 2 + TIME_STR_OFFSET_X, TIME_STR_POS_Y, TIME_STR, GetColor(255, 0, 0));

		// GetNowCount��1000���̂P�b�Ȃ̂ł�������v�Z����.
		sprintf_s(timeNumStr, "%d", LIMIT_TIME_COUNT + ((game.gameStartTime - GetNowCount()) / 1000));

		SetFontSize(TIME_NUM_STR_FONT_SIZE);
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(timeNumStr) / 2, TIME_STR_POS_Y, timeNumStr, GetColor(255, 0, 0));

		// �v���C���[�̗�.
		sprintf_s(lifeStr, "HP:%d", game.player.life);
		SetFontSize(TIME_STR_FONT_SIZE);
		DrawString((int)(game.player.obj.pos.x - GetDrawStringWidthFull(lifeStr) / 2), (int)(game.player.obj.pos.y + PLAYER_HP_OFFSET_Y), lifeStr, GetColor(255, 0, 0));

		// �G�̗�.
		SetFontSize(ENEMY_HP_STR_FONT_SIZE);
		DrawString(ENEMY_HP_STR_POS_X, ENEMY_HP_STR_POS_Y, "Enemy", GetColor(255, 0, 0));
		hpGraphStartX = ENEMY_HP_STR_POS_X + ENEMY_HP_LEFT_OFFSET_X;

		// �̗͉摜�͈�F�̉摜���A�����L�΂��ĉ�ʂ��炢�������̈ʒu�ɂ����Ă���.
		DrawExtendGraph(
			hpGraphStartX,
			ENEMY_HP_STR_POS_Y,
			SCREEN_W - ENEMY_HP_RIGHT_OSSET_X,
			ENEMY_HP_STR_POS_Y + ENEMY_HP_HIGHT,
			ui.hpBackGraph,
			TRUE);

		DrawExtendGraph(
			hpGraphStartX,
			ENEMY_HP_STR_POS_Y,
			hpGraphStartX + (int)((SCREEN_W - hpGraphStartX - ENEMY_HP_RIGHT_OSSET_X) * ((float)game.enemy.life / ENEMY_LIFE)),
			ENEMY_HP_STR_POS_Y + ENEMY_HP_HIGHT,
			ui.hpGraph,
			TRUE);

		break;

		// �N���A���.
	case STATE_CLEAR:
		SetFontSize(TITLE_FONT_SIZE);
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(GAME_CLEAR_STR) / 2, SCREEN_H / 2 + TITLE_STR_OFFSET_Y, GAME_CLEAR_STR, GetColor(255, 255, 0));
		SetFontSize(PRESS_STR_FONT_SIZE);
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(RETURN_TITLE_STR) / 2, SCREEN_H / 2 + PRESS_STR_OFFSET_Y, RETURN_TITLE_STR, GetColor(255, 255, 255));
		break;
		// �Q�[���I�[�o�[.
	case STATE_GAMEOVER:
		SetFontSize(TITLE_FONT_SIZE);
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(GAME_OVER_STR) / 2, SCREEN_H / 2 + TITLE_STR_OFFSET_Y, GAME_OVER_STR, GetColor(255, 0, 0));
		SetFontSize(PRESS_STR_FONT_SIZE);
		DrawString(SCREEN_W / 2 - GetDrawStringWidthFull(RETURN_TITLE_STR) / 2, SCREEN_H / 2 + PRESS_STR_OFFSET_Y, RETURN_TITLE_STR, GetColor(255, 255, 255));
		break;
	default:
		break;
	}
}
