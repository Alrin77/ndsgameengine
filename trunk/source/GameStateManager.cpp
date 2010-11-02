#include "GameStateManager.h"

IGameStateManager* GameStateManager::_gameStateManager;

GameStateManager::GameStateManager(){}

GameStateManager::~GameStateManager(){
	Cleanup();
}

void GameStateManager::Initialize(){
}

void GameStateManager::Update(){
	TopState()->Update();
}

void GameStateManager::Draw(){
	TopState()->Draw();
}

void GameStateManager::Cleanup(){
	while(!StackIsEmpty()){
		TopState()->Cleanup();
		PopState();
	}
}

void GameStateManager::PushState(int StateToPush){
	FSM<GameState,IGameStateManager>::PushState(getGameState(StateToPush));
	TopState()->Initialize();
}

void GameStateManager::ChangeState(int newState, bool clearStack = false){
	TopState()->Cleanup();
	FSM<GameState,IGameStateManager>::ChangeState(getGameState(newState), clearStack);
	TopState()->Initialize();
}

bool GameStateManager::PopState(){
	TopState()->Cleanup();
	FSM<GameState,IGameStateManager>::PopState();
}

GameState* GameStateManager::TopState(){
	return FSM<GameState, IGameStateManager>::TopState();
}


GameState* GameStateManager::getGameState(int GameToGet){
	switch (GameToGet){
		case STATE_INTRO:
			return new GameStateIntro();
		case STATE_OPTIONS:
			return new GameStateOptions();
		case STATE_SETUP:
			return new GameStateSetup();
		case STATE_PLAY:
			return new GameStatePlay();
		case STATE_CREDIT:
			return new GameStateCredits();
		case STATE_PAUSE:
			return new GameStatePause();
	}
}