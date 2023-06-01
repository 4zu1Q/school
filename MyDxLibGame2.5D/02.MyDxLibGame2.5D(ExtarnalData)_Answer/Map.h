// 2023 Takeru Yui All Rights Reserved.
#pragma once
#include "DxLib.h"
#include <vector>

class WorldSprite;
class PlatinumLoader;

/// <summary>
/// 2D�̔w�i�}�b�v
/// </summary>
class Map
{
public:
	Map();
	~Map();

	void Load(const TCHAR* fmfFilePath);
	void Update();
	void Draw();

	// �}�b�v�`�b�v�̃T�C�Y
	static const float	ChipSize;
	static const int	ChipPixelSize;

private:
	std::vector<std::vector<int>> currentData;
	int dataColNum = 0;
	int dataRowNum = 0;
	std::vector<WorldSprite*> sprites;
	int chipGraph;
	PlatinumLoader* loader;
};

