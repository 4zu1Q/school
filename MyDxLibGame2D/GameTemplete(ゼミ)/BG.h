#pragma once

// �v���g�^�C�v�錾
struct GameObject;

#define BG_SCROLL_SPEED		2		// �w�i�̏c�X�N���[���X�s�[�h.

// �w�i.
struct BG
{
	GameObject	obj;
};

// ������.
void InitBG(BG& bg, int graph, int index);

// �A�b�v�f�[�g.
void UpdateBG(BG& bg);

// �`��.
void DrawBG(BG& bg);