#include "GameServices.h"
#include "GameEngine.h"
#include "GameStateManager.h"
#include "GameObjectManager.h"
#include "InputManager.h"

IGameEngine* GameServices::GameEngine(){
	return GameEngine::getSingleton();
}

IGameStateManager* GameServices::GameStateManager(){
	return GameStateManager::getSingleton();
}

IGameObjectManager* GameServices::GameObjectManager(){
	return GameObjectManager::getSingleton();
}

IInputManager* GameServices::InputManager(){
	return InputManager::getSingleton();
}