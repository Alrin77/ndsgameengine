#pragma once

#include <vector>
#include <stack>
#include "FSM.h"
#include "GameState.h"
#include "IGameManager.h"

#pragma region GameStates
#include "GameStateIntro.h"
#include "GameStateOptions.h"
#include "GameStateSetup.h"
#include "GameStatePlay.h"
#include "GameStateCredits.h"
#include "GameStatePause.h"
#pragma endregion

//Game state management, provides functionality for switching between game states
class GameStateManager : public IGameStateManager, public FSM<GameState, IGameStateManager>{
	friend class GameEngine;
public:
	virtual ~GameStateManager();

	void PushState(int StateToPush);
	void ChangeState(int newState, bool clearStack);
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

private:
	GameState* getGameState(int GameToGet);
};