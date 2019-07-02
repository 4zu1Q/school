#pragma once

// �v���g�^�C�v�錾
struct Game;

// UI�Ɏg��������.
#define	TITLE_STR			"�V���[�e�B���O"
#define	GAME_OVER_STR		"�Q�[���I�[�o�["
#define	GAME_CLEAR_STR		"�Q�[���N���A�I"
#define	STARTBUTTON_STR		"�X�y�[�X�L�[�ŃX�^�[�g"
#define	RETURN_TITLE_STR	"�X�y�[�X�L�[�Ń^�C�g����"
#define	TIME_STR			"�c��F"

// UI�p�ʒu����.
#define	TITLE_STR_OFFSET_Y		-100	// ���o��������y�I�t�Z�b�g.
#define	PRESS_STR_OFFSET_Y		100		// �{�^���������Ă��������nUI��y�I�t�Z�b�g.
#define	TIME_STR_OFFSET_X		-100	// ��������(�u�c��v)��x�I�t�Z�b�g.
#define	TIME_STR_POS_Y			25		// �c�莞��UI��y�|�W�V����.
#define	TITLE_FONT_SIZE			64		// ���o�������̃t�H���g�T�C�Y.
#define	PRESS_STR_FONT_SIZE		24		// �{�^���������Ă��������nUI�̃T�C�Y.
#define	TIME_STR_FONT_SIZE		24		// ��������(�u�c��v)�̃t�H���g�T�C�Y.
#define	TIME_NUM_STR_FONT_SIZE	40		// ��������(����)�̃t�H���g�T�C�Y.
#define	ENEMY_HP_STR_FONT_SIZE	24		// �G�̗͂̃t�H���g�T�C�Y.
#define	ENEMY_HP_STR_POS_Y		2		// �G�̗͕�����y�|�W�V����.
#define	ENEMY_HP_STR_POS_X		10		// �G�̗͕�����x�|�W�V����.
#define	ENEMY_HP_LEFT_OFFSET_X	80		// �G�̗͂̍�����̃I�t�Z�b�g.
#define	ENEMY_HP_RIGHT_OSSET_X	30		// �G�̗͉摜�̉E����̃I�t�Z�b�g.
#define	ENEMY_HP_HIGHT			15		// �G�̗͉摜�̍���.
#define	PLAYER_HP_FONT_SIZE		10		// �v���C���[�̗̑̓T�C�Y.
#define	PLAYER_HP_OFFSET_Y		45		// �v���C���[�̗͂̃I�t�Z�b�g.

// UI
struct UI
{
	int		hpGraph;
	int		hpBackGraph;
};

// UI������.
void InitUI(UI& ui);

// UI�`��.
void DrawUI(UI& ui, Game& game);