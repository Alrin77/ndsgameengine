#include "GameStateManager.h"

IGameStateManager* GameStateManager::_gameStateManager;

GameStateManager::GameStateManager(){}

GameStateManager::~GameStateManager(){
	Cleanup();
}

void GameStateManager::Initialize(){
	Cleanup();
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

void GameStateManager::PushState(GameState* newState){
	newState->Initialize();
	FSM<GameState,IGameStateManager>::PushState(newState);
}

void GameStateManager::ChangeState(GameState* newState, bool clearStack = false){
	TopState()->Cleanup();
	newState->Initialize();
	FSM<GameState,IGameStateManager>::ChangeState(newState, clearStack);
}

bool GameStateManager::PopState(){
	TopState()->Cleanup();
	FSM<GameState,IGameStateManager>::PopState();
}

GameState* GameStateManager::TopState(){
	return FSM<GameState, IGameStateManager>::TopState();
}