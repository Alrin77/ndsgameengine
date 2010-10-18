#pragma once

#include "GameStd.h"
#include "FSMState.h"

class GameStateManager;

//Base class which all GameStates must inherit
class GameState : public FSMState<GameState, IGameStateManager>{
	friend class GameStateManager;
public:
	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Cleanup()=0;
	virtual void Pause()=0;
	virtual void Resume()=0;
};