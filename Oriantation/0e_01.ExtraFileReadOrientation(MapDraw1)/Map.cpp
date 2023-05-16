#include<vector>
#include "Map.h"
#include "DxLib.h"

const int Map::Stage1Data[][StageDataColNum] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

/// <summary>
/// �R���X�g���N�^
/// </summary>
Map::Map()
	: chipGraph(-1)
{
	currentData.clear();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Map::~Map()
{
	// �����Ȃ�
}

/// <summary>
/// ���[�h
/// </summary>
void Map::Load()
{
	// �Ƃ肠�����}�b�v���[�h
	chipGraph = LoadGraph("data/mapChip1.png");

	//// ��X�Ⴄ�f�[�^�𓮓I�ɐ؂�ւ��邽�߁AcurrentData�ɃR�s�[
	//const int** targetData = (const int**)Stage1Data;

	//currentData.clear();
	//for (int i = 0; i < StageDataColNum; i++)
	//{
	//	std::vector<int> newColData;
	//	for (int j = 0; j < StageDataColNum; j++)
	//	{
	//		newColData.push_back(targetData[i][j]);
	//	}
	//	currentData.push_back(newColData);
	//}
}

/// <summary>
/// �X�V
/// </summary>
void Map::Update()
{
	// �����Ȃ�
}

/// <summary>
/// �`��
/// </summary>
void Map::Draw()
{
	// �䂭�䂭�̓J�����������Ă��āA�J�����͈͈ȊO�\�����Ȃ��悤��
	float size = 1.0f;
	DrawBillboard3D(VGet(0,0,0), 0, 0, size, 0, chipGraph, FALSE);
	//DrawGraph3D(0, 0, 0, chipGraph, FALSE);
}


