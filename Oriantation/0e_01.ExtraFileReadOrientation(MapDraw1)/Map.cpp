// 2023 Takeru Yui All Rights Reserved.
#include<vector>
#include "Map.h"
#include "DxLib.h"
#include "WorldSprite.h"

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
	sprite = new WorldSprite();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Map::~Map()
{
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}
}

/// <summary>
/// ���[�h
/// </summary>
void Map::Load()
{
	// �Ƃ肠�����}�b�v���[�h
	chipGraph = LoadGraph("data/map.png");
	sprite->Initialize(chipGraph, 32, 65);
	sprite->SetTransform(VGet(-0.5f, -0.5f, 0), 1.0f);

	// ��X�Ⴄ�f�[�^�𓮓I�ɐ؂�ւ��邽�߁AcurrentData�ɃR�s�[
	const int(*targetDataRows)[StageDataColNum] = Stage1Data;

	currentData.clear();
	for (int i = 0; i < StageDataColNum; i++)
	{
		std::vector<int> newColData;
		for (int j = 0; j < StageDataColNum; j++)
		{
			newColData.push_back(targetDataRows[i][j]);
		}
		currentData.push_back(newColData);
	}
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
	sprite->Draw();
}


