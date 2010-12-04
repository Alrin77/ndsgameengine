#pragma once

#include "GameStd.h"

//maintains user input information and makes it accessible to the game engine
class InputManager : public IInputManager{
	friend class GameEngine;	//provides access to protected members
public:
	
	int GetKeyHeld(int keyCheck);		//returns the integer containing key held information
	int GetKeyDown(int keyCheck);		//returns whether or not a specific key is down
	int GetKeyUp(int keyCheck);			//returns whether or not a specific key is up
	touchPosition GetTouchPosition();

	//register and unregister objects to listen for input changes
	void RegisterListener(IInputListener* listener);
	void UnregisterListener(IInputListener* listener);

	//singleton class, single instance and static access
	static IInputManager* getSingleton(){
		if(!_inputManager)
			_inputManager = new InputManager();
		return _inputManager;
	}

protected:
	//protected constructor and destructor enforces singleton
	InputManager();
	~InputManager();

	static IInputManager* _inputManager;		//singleton instance of this class

	void Initialize();
	void Update();
	void Draw();
	void Cleanup();

	void NotifyHeld();							//notify listeners of input held
	void NotifyDown();							//notify listeners of input down
	void NotifyUp();							//notify listeners of input up

	//the keys which are held
	int _held;
	int _prevHeld;

	//the keys which were pressed this frame
	int _down;
	int _prevDown;

	//the keys which were released this frame
	int _up;
	int _prevUp;

	touchPosition _touch;

	std::vector<IInputListener*>* _listenerList;	//the list of objects listening to input
	std::vector<IInputListener*>* _newList;
	std::vector<IInputListener*>* _deadList;
	
};