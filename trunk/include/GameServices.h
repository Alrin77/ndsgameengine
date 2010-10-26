#pragma once

#include "IGameEngine.h"
#include "IGameStateManager.h"
#include "IGameObjectManager.h"
#include "IInputManager.h"


class GameServices{
public:
	static IGameEngine* GameEngine();
	static IGameStateManager* GameStateManager();
	static IGameObjectManager* GameObjectManager();
	static IInputManager* InputManager();
};