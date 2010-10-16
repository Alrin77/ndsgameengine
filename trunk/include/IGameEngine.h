#pragma once

class IGameManager;

class IGameEngine{
public:
	virtual void Run()=0;	
	virtual void ShutDown()=0;

	void AddManager(IGameManager* newManager);
	void RemoveManager(IGameManager* newManager);
};