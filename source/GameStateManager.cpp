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
	FSM<GameState,IGameStateManager>::PushState(newState);
}

void GameStateManager::ChangeState(GameState* newState){
	FSM<GameState,IGameStateManager>::ChangeState(newState);
}

bool GameStateManager::PopState(){
	FSM<GameState,IGameStateManager>::PopState();
}

GameState* GameStateManager::TopState(){
	return FSM<GameState, IGameStateManager>::TopState();
}