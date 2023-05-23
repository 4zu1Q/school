// 2023 Takeru Yui All Rights Reserved.
#pragma once

class WorldSprite;

/// <summary>
/// 2D�̔w�i�}�b�v
/// </summary>
class Map
{
public:
	Map();
	~Map();

	void Load();
	void Update();
	void Draw();

private:
	static const int StageDataColNum = 15;
	static const int Stage1Data[][StageDataColNum];
	
	std::vector<std::vector<int>> currentData;
	WorldSprite* sprite;
	int chipGraph;
};

