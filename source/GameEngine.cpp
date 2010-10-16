#include "GameEngine.h"
#include "temp.h"

IGameEngine* GameEngine::_gameEngine;

GameEngine::GameEngine(){
	_gcList = new std::vector<IGameManager*>();
	_running = true;
}

GameEngine::~GameEngine(){
	Cleanup();
}

void GameEngine::Run(){
	//***********************GET RID OF ME
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);
	//***********************GET RID OF ME

	//_gcList->push_back(GameStateManager::getSingleton());
	_gcList->push_back(GameObjectManager::getSingleton());
	Initialize();
	while(_running){
		Update();
		Draw();
	}
	Cleanup();
}

void GameEngine::ShutDown(){
	_running = false;
}

void GameEngine::Initialize(){
	for(std::vector<IGameManager*>::iterator it = _gcList->begin(); it != _gcList->end(); it++)
		(*it)->Initialize();
}

void GameEngine::Update(){
	for(std::vector<IGameManager*>::iterator it = _gcList->begin(); it != _gcList->end(); it++)
		(*it)->Update();
}

void GameEngine::Draw(){
	//***********************GET RID OF ME
	pixel(rand() % 256, rand() % 192, RGB15(rand()%31, rand()%31, rand()%31));
	//***********************GET RID OF ME
	for(std::vector<IGameManager*>::iterator it = _gcList->begin(); it != _gcList->end(); it++)
		(*it)->Draw();
}

void GameEngine::Cleanup(){
	for(std::vector<IGameManager*>::iterator it = _gcList->begin(); it != _gcList->end(); it++)
		(*it)->Cleanup();
}

void GameEngine::AddManager(IGameManager* newManager){
	newManager->Initialize();
	_gcList->push_back(newManager);
}

void GameEngine::RemoveManager(IGameManager* newManager){
	for(int i=0; i<_gcList->size();i++)
		if(newManager == _gcList->at(i)){
			_gcList->erase(_gcList->begin()+i);
			return;
		}
}