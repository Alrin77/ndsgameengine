#pragma once

#include "GameState.h"

class GameStateCredits : public GameState{
public:
	GameStateCredits();
	~GameStateCredits();

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
	void Pause();
	void Resume();
};

