#include "InputManager.h"

IInputManager* InputManager::_inputManager;

InputManager::InputManager(){
}

void InputManager::Update(){
	scanKeys();
	_held = keysHeld();
	_down = keysDown();
	_up = keysUp();
}

int InputManager::GetKeyPressed(){
	return _down;
}

int InputManager::GetKeyReleased(){
	return _up;
}

int InputManager::GetKeyHeld(){
	return _held;
}