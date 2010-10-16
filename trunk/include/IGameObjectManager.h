#pragma once

class GameObject;

class IGameObjectManager : protected IGameManager{
public:
	int AddObject(GameObject* newObject);
	void DestroyObject(int objectID);
	GameObject* GetObjectByID(int objectID);
};