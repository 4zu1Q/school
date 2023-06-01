// 2023 Takeru Yui All Rights Reserved.
#include<vector>
#include "Map.h"
#include "DxLib.h"
#include "WorldSprite.h"
#include "PlatinumLoader.h"

const float Map::ChipSize = 0.725f;
const int Map::ChipPixelSize = 32;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Map::Map()
	: chipGraph(-1)
{
	currentData.clear();
	loader = new PlatinumLoader();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Map::~Map()
{
	for (const auto& sprite : sprites)
	{
		if (sprite != nullptr)
		{
			delete sprite;
		}
	}
	sprites.clear();
	if (loader != nullptr)
	{
		delete loader;
		loader = nullptr;
	}
}

/// <summary>
/// ���[�h
/// </summary>
void Map::Load(const TCHAR* fmfFilePath)
{
	loader->Load(fmfFilePath);
	currentData.clear();

	std::vector<int> newColData;
	loader->GetMapSize(dataRowNum, dataColNum);		// �}�b�v�̃T�C�Y=�f�[�^�̍s�Ɨ�̒���������
	for (int i = 0; i < dataColNum; i++)
	{
		newColData.clear();
		for (int j = 0; j < dataRowNum; j++)
		{
			int spriteNo = loader->GetChipSpriteNo(LayerType::BackGround, j, i);
			newColData.push_back(spriteNo);
		}
		currentData.push_back(newColData);
	}

	// �Ƃ肠�����}�b�v���[�h
	chipGraph = LoadGraph("data/map.png");

	// WorldSprite���̐ݒ�ƈʒu������
	VECTOR chipLeftTopPos = VGet(0, dataColNum * ChipSize, 0);			// �}�b�v�̕`��J�n�ʒu�i����j
	for (int i = 0; i < dataColNum; i++)
	{
		for (int j = 0; j < dataRowNum; j++)
		{
			auto sprite = new WorldSprite();
			sprite->Initialize(chipGraph, ChipPixelSize, currentData[i][j]);
			VECTOR chipHalfOffset = VGet(-Map::ChipSize * 0.5f, -Map::ChipSize * 0.5f, 0);					// �}�b�v�`�b�v�̔����T�C�Y�����ɂ��炷�I�t�Z�b�g
			VECTOR chipPos = VAdd(VGet(j * Map::ChipSize,  (-i - 1) * Map::ChipSize, 0), chipHalfOffset);	// �^�񒆃s�{�b�g�Ȃ̂Ń}�b�v�`�b�v�����T�C�Y���炷+�n�ʂȂ̂ň����
			chipPos = VAdd(chipPos, chipLeftTopPos);
			sprite->SetTransform(chipPos, Map::ChipSize);
			sprites.push_back(sprite);
		}
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
	for (const auto& sprite : sprites)
	{
		sprite->Draw();
	}
}


