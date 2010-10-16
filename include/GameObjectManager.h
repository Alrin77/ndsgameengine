#pragma once

#include <vector>
#include <ext/hash_map>
#include "IGameComponent.h"
#include "IGameObjectManager.h"
#include "GameObject.h"

class GameObjectManager : public IGameObjectManager{
	friend class GameEngine;

public:
	~GameObjectManager();

	int AddObject(GameObject* newObject);
	void DestroyObject(int objectID);
	GameObject* GetObjectByID(int objectID);

	static IGameObjectManager* getSingleton(){
		if(!_gameObjectManager)
			_gameObjectManager = new GameObjectManager();
		return _gameObjectManager;
	}

protected:
	GameObjectManager();

	static IGameObjectManager* _gameObjectManager;

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();
	
	
private:
	struct intCompare{
		bool operator()(const int p1, const int p2) const{
			return p1 == p2;
		}
	};

	__gnu_cxx::hash_map<int, GameObject*, __gnu_cxx::hash<int>, intCompare>* _gameObjectMap;
	__gnu_cxx::hash_map<int, GameObject*, __gnu_cxx::hash<int>, intCompare>::iterator _objectIterator;
	
	std::vector<GameObject*>* _deadObjectList;
	std::vector<GameObject*>::iterator _deadIterator;

	int _objectIdCount;
};