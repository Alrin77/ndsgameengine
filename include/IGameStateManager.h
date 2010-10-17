#pragma once

#include "IGameManager.h"

class GameState;

class IGameStateManager : protected IGameManager{
public:
	virtual void PushState(GameState* newState)=0;
	virtual void ChangeState(GameState* newState, bool clearStack)=0;
	virtual bool PopState()=0;
	virtual GameState* TopState()=0;
};