#include "InputManager.h"

IInputManager* InputManager::_inputManager;

InputManager::InputManager(){
	_listenerList = new std::vector<IInputListener*>();
	_deadList = new std::vector<IInputListener*>();
	_newList = new std::vector<IInputListener*>();
}

InputManager::~InputManager(){
	Cleanup();

	while(_deadList->size() > 0){
		for(int i=0; i<_listenerList->size(); i++){
			if(_listenerList->at(i) == _deadList->back()){
				_listenerList->erase(_listenerList->begin()+i);
			}
		}
		_deadList->pop_back();
	}

	delete _listenerList;
	delete _deadList;
}

int InputManager::GetKeyHeld(int keyCheck){
	return _held & keyCheck;
}

int InputManager::GetKeyDown(int keyCheck){
	return _down & keyCheck;
}

int InputManager::GetKeyUp(int keyCheck){
	return _up & keyCheck;
}

touchPosition InputManager::GetTouchPosition(){
	return _touch;
}

void InputManager::Initialize(){
}

void InputManager::Update(){
	
	while(_newList->size() > 0){
		_listenerList->push_back(_newList->back());
		_newList->pop_back();
	}

	while(_deadList->size() > 0){
		for(int i=0; i<_listenerList->size(); i++){
			if(_listenerList->at(i) == _deadList->back()){
				_listenerList->erase(_listenerList->begin()+i);
			}
		}
		_deadList->pop_back();
	}
	_deadList->clear();
	
	_prevHeld = _held;
	_prevDown = _down;
	_prevUp = _up;

	scanKeys();
	_held = keysHeld();
	_down = keysDown();
	_up = keysUp();
	

	if(_held && _prevHeld != 0)
		NotifyHeld();

	if(_prevDown != _down && _down > _prevDown)
		NotifyDown();

	if(_prevUp != _up && _up > _prevUp)
		NotifyUp();
}

void InputManager::Draw(){
}

void InputManager::Cleanup(){
	_listenerList->clear();
}

void InputManager::RegisterListener(IInputListener* listener){
	_newList->push_back(listener);
}

void InputManager::UnregisterListener(IInputListener* listener){
	_deadList->push_back(listener);
}

void InputManager::NotifyHeld(){
	for(std::vector<IInputListener*>::iterator it = _listenerList->begin(); it != _listenerList->end(); it++)
		(*it)->OnKeyHeld(_held);
}

void InputManager::NotifyDown(){
	for(std::vector<IInputListener*>::iterator it = _listenerList->begin(); it != _listenerList->end(); it++){
		(*it)->OnKeyDown(_down);
	}
}

void InputManager::NotifyUp(){
	for(std::vector<IInputListener*>::iterator it = _listenerList->begin(); it != _listenerList->end(); it++)
		(*it)->OnKeyUp(_up);
}