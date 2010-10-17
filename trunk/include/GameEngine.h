#pragma once

#include "GameStd.h"
#include "GameServices.h"
#include "GameStateManager.h"
#include "GameObjectManager.h"


class GameEngine : public IGameEngine{
public:
	~GameEngine();

	void Run();	
	void ShutDown();

	void AddManager(IGameManager* newManager);
	void RemoveManager(IGameManager* newManager);

	static IGameEngine* getSingleton(){
		if(_gameEngine == NULL)
			_gameEngine = new GameEngine();
		return (IGameEngine*)_gameEngine;
	}

protected:
	GameEngine();

	static IGameEngine* _gameEngine;

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();

	bool _running;
	std::vector<IGameManager*>* _gcList;
};