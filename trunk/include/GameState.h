#pragma once

#include "FSMState.h"
#include "GameStd.h"

class GameStateManager;
class GameState;

//Base class which all GameStates must inherit
class GameState : public FSMState<GameState, IGameStateManager>{
	friend class GameStateManager;
public:
	virtual void Pause() = 0;
	virtual void Resume() = 0;	

	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Cleanup()=0;
};