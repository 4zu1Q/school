//----------------------------//
// ���[�e�B���e�B�i�֗��j�֐��Q
//----------------------------//
#include "Utility.h"
#include "DxLib.h"

// �w�肳�ꂽ�S������̕����擾.
int GetDrawStringWidthFull(char* str)
{
	return GetDrawStringWidth(str, (int)strlen(str));
}

// �f�B�O���[�����W�A���ɕϊ�
float GetRadian(float degree)
{
	return (PI / 180.0f) * degree;
}