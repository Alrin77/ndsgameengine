#pragma once

#include "GameStd.h"

class InputManager : public IInputManager{
public:
	void Update();

	int GetKeyPressed();
	int GetKeyReleased();
	int GetKeyHeld();

	static IInputManager* getSingleton(){
		if(!_inputManager)
			_inputManager = new InputManager();
		return _inputManager;
	}


protected:
	InputManager();

	static IInputManager* _inputManager;

	int _held;
	int _down;
	int _up;
};