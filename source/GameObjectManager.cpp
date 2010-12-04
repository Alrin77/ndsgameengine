#include "GameObjectManager.h"

IGameObjectManager* GameObjectManager::_gameObjectManager;

GameObjectManager::GameObjectManager(){
	_gameObjectMap = new __gnu_cxx::hash_map<u32, GameObject*, __gnu_cxx::hash<u32>, intCompare>();
	_deadObjectList = new std::vector<GameObject*>();
}

GameObjectManager::~GameObjectManager(){
	Cleanup();

	if(!_deadObjectList->empty())
		for(_deadIterator = _deadObjectList->begin(); _deadIterator != _deadObjectList->end();_deadIterator++){
			(*_deadIterator)->Cleanup();
			delete *_deadIterator;
		}
	_deadObjectList->clear();

	delete _gameObjectMap;
	delete _deadObjectList;
	_gameObjectManager = 0;
}

void GameObjectManager::Initialize(){
	_objectIdCount = 0;
}

void GameObjectManager::Update(){
	for(_objectIterator = _gameObjectMap->begin(); _objectIterator != _gameObjectMap->end(); _objectIterator++)
		(*_objectIterator).second->Update();

	if(!_deadObjectList->empty())
		for(_deadIterator = _deadObjectList->begin(); _deadIterator != _deadObjectList->end();_deadIterator++){
			_gameObjectMap->erase((*_deadIterator)->GetID());
			(*_deadIterator)->Cleanup();
			delete *_deadIterator;
		}
	_deadObjectList->clear();
}

void GameObjectManager::Draw(){
	for(_objectIterator = _gameObjectMap->begin(); _objectIterator != _gameObjectMap->end(); _objectIterator++)
		(*_objectIterator).second->Draw();
}

void GameObjectManager::Cleanup(){
	for(_objectIterator = _gameObjectMap->begin(); _objectIterator != _gameObjectMap->end(); _objectIterator++)
		_deadObjectList->push_back((*_objectIterator).second);

	
	_gameObjectMap->clear();
}

u32 GameObjectManager::AddObject(GameObject* newObject){
	_gameObjectMap->insert(__gnu_cxx::pair<u32, GameObject*>(++_objectIdCount, newObject));
	newObject->_objectID = _objectIdCount;
	newObject->Initialize();
	return _objectIdCount;
}

void GameObjectManager::DestroyObject(u32 objectID){
	_deadObjectList->push_back(GetObjectByID(objectID));
	//_gameObjectMap->erase(objectID);
}

u32 GameObjectManager::GetObjectTypeByID(u32 objectID){
	return GetObjectByID(objectID)->GetType();
}

GameObject* GameObjectManager::GetObjectByID(u32 objectID){
	return (*_gameObjectMap->find(objectID)).second;
}


void GameObjectManager::DestroyAllObjects(){
	Cleanup();
}