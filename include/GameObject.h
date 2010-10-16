#pragma once

#include <string>
class GameObjectManager;

class GameObject{
	friend class GameObjectManager;

public:
	int GetID() {return _objectID;}	
	std::string GetType() {return _objectType;}
	
protected:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Cleanup()=0;

private:
	int _objectID;
	std::string _objectType;
};