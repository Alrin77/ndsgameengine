#include "GameObjectManager.h"
#include "temp.h"

IGameObjectManager* GameObjectManager::_gameObjectManager;

GameObjectManager::GameObjectManager(){
	_gameObjectMap = new __gnu_cxx::hash_map<int, GameObject*, __gnu_cxx::hash<int>, intCompare>();
	_deadObjectList = new std::vector<GameObject*>();
}

GameObjectManager::~GameObjectManager(){
	Cleanup();
	delete _gameObjectMap;
	delete _deadObjectList;
	_gameObjectManager = NULL;
}

void GameObjectManager::Initialize(){
	Cleanup();
	_objectIdCount = 0;
}

void GameObjectManager::Update(){
	//***********************GET RID OF ME
	pixel(rand() % 256, rand() % 192, RGB15(rand()%31, rand()%31, rand()%31));
	//***********************GET RID OF ME

	for(_objectIterator = _gameObjectMap->begin(); _objectIterator != _gameObjectMap->end(); _objectIterator++)
		(*_objectIterator).second->Update();

	if(!_deadObjectList->empty())
		for(_deadIterator = _deadObjectList->begin(); _deadIterator != _deadObjectList->end();_deadIterator++){
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

	if(!_deadObjectList->empty())
		for(_deadIterator = _deadObjectList->begin(); _deadIterator != _deadObjectList->end();_deadIterator++){
			(*_deadIterator)->Cleanup();
			delete *_deadIterator;
		}
	_deadObjectList->clear();
	_gameObjectMap->clear();
}

int GameObjectManager::AddObject(GameObject* newObject){
	_gameObjectMap->insert(__gnu_cxx::pair<int, GameObject*>(++_objectIdCount, newObject));
	newObject->_objectID = _objectIdCount;
	return _objectIdCount;
}

void GameObjectManager::DestroyObject(int objectID){
	_deadObjectList->push_back(GetObjectByID(objectID));
	_gameObjectMap->erase(objectID);
}

GameObject* GameObjectManager::GetObjectByID(int objectID){
	return (*_gameObjectMap->find(objectID)).second;
}
