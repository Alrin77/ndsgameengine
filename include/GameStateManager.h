#pragma once

#include <vector>
#include <stack>
#include "FSM.h"
#include "GameState.h"
#include "IGameManager.h"

//Game state management, provides functionality for switching between game states
class GameStateManager : public IGameStateManager, public FSM<GameState, IGameStateManager>{
	friend class GameEngine;
public:
	virtual ~GameStateManager();

	void PushState(GameState* newState);
	void ChangeState(GameState* newState, bool clearStack);
	bool PopState();
	GameState* TopState();

	static IGameStateManager* getSingleton(){
		if(_gameStateManager == NULL)
			_gameStateManager = new GameStateManager();
		return _gameStateManager;
	}

protected:
	static IGameStateManager* _gameStateManager;

	GameStateManager();
	
	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
};