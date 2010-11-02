#pragma once

class GameObject;

class IGameObjectManager : protected IGameManager{
public:
	virtual int AddObject(GameObject* newObject)=0;
	virtual void DestroyObject(int objectID)=0;
	virtual GameObject* GetObjectByID(int objectID)=0;
};