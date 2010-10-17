#pragma once

#include "GameState.h"

class GameStatePlay : public GameState{
public:
	GameStatePlay();
	~GameStatePlay();

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
	void Pause();
	void Resume();
};

