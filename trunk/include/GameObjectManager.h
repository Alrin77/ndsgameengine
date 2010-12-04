#pragma once

#include "GameStd.h"
#include "GameObject.h"

//Class to manage the actions of game objects
class GameObjectManager : public IGameObjectManager{
	friend class GameEngine;	//allows the game engine to access protected members

public:
	//add an object to the manager. returns a unique identifier for the object
	u32 AddObject(GameObject* newObject);
	
	//destroy an object
	void DestroyObject(u32 objectID);

	//returns an object type by its unique identifier
	u32 GetObjectTypeByID(u32 objectID);

	//retreive an object by its unique identifier
	GameObject* GetObjectByID(u32 objectID);

	//singleton class, single instance and static access
	static IGameObjectManager* getSingleton(){
		if(!_gameObjectManager)
			_gameObjectManager = new GameObjectManager();
		return _gameObjectManager;
	}

	void DestroyAllObjects();

protected:
	//protected constructor and destructor enforces singleton
	GameObjectManager();
	~GameObjectManager();

	//singleton instance of this class
	static IGameObjectManager* _gameObjectManager;

	//initialize the manager
	void Initialize();

	//update all game objects
	void Update();

	//draw all game objects
	void Draw();

	//destroy all objects
	void Cleanup();
	
private:

	//maps unique object identifiers to the game object
	__gnu_cxx::hash_map<u32, GameObject*, __gnu_cxx::hash<u32>, intCompare>* _gameObjectMap;
	__gnu_cxx::hash_map<u32, GameObject*, __gnu_cxx::hash<u32>, intCompare>::iterator _objectIterator;
	
	//list of dead objects
	std::vector<GameObject*>* _deadObjectList;
	std::vector<GameObject*>::iterator _deadIterator;

	u32 _objectIdCount;
};