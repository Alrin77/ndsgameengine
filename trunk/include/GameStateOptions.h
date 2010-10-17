#pragma once

#include "GameState.h"

class GameStateOptions : public GameState{
public:
	GameStateOptions();
	~GameStateOptions();
	
	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
	void Pause();
	void Resume();
};

