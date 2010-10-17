#pragma once

#include "GameState.h"

class GameStatePause : public GameState{
public:
	GameStatePause();
	~GameStatePause();

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
	void Pause();
	void Resume();
};

