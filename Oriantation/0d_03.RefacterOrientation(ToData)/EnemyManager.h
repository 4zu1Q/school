// 2023 Takeru Yui All Rights Reserved.
#pragma once
#include <vector>

class EnemyBase;

/// <summary>
/// �G���܂Ƃ߂�
/// </summary>
class EnemyManager
{
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();

	const std::vector<EnemyBase*>& GetEnemies() const
	{ 
		return enemies; 
	}

private:
	std::vector<EnemyBase*> enemies;
};

