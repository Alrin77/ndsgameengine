#pragma once

#include "GameStd.h"

class IInputManager{
	virtual int GetKeyPressed()=0;
	virtual int GetKeyReleased()=0;
	virtual int GetKeyHeld()=0;
};