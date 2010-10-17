#pragma once

#include "GameState.h"
class GameStateManager;

class GameStateIntro : public GameState{
public:
	GameStateIntro();
	~GameStateIntro();

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
	void Pause();
	void Resume();
};

