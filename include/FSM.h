#pragma once

#include <stack>
#include <vector>
#include "FSMState.h"

//templated implementation of a simple stack based finite state machine.
//first template parameter is the states which will be managed by this FSM. This type
//should inherit the FSMState class.
//second template parameter is the interface through which the managed states will
//interact with the FSM. 
template <class stateType, class interfaceType>
class FSM{

public:
	//Push a new state onto the stack
	virtual void PushState(stateType* newState){
		_stateStack->push((FSMState<stateType, interfaceType>*)newState);
		_stateStack->top()->SetManager((interfaceType*)this);
	}

	//Remove top state and push a new state onto the stack
	//send true for second parameter to remove all states from the stack
	virtual void ChangeState(stateType* newState, bool clearStack = false){
		if(!clearStack) 
			PopState();
		else 
			EmptyStateStack();
		PushState(newState);
	}

	//Remove top state and move it to dead state list
	virtual bool PopState(){
		if(_stateStack->empty())
			return false;

		ClearDeadState();
		_deadState = _stateStack->top();
		_stateStack->pop();
		return true;
	}

	//Returns the top state on the stack
	virtual stateType* TopState(){
		//if(!StackIsEmpty())
			return (stateType*)_stateStack->top();
		//return NULL;
	}

protected:
	//Constructor
	FSM(){
		_stateStack = new std::stack<FSMState<stateType, interfaceType>*>();
		_deadState = NULL;
	}

	//virtual Destructor, preserves destructor execution order
	virtual ~FSM(){
		EmptyStateStack();
		delete _stateStack;
	}

	//Returns if the state stack is currently empty
	const bool StackIsEmpty(){
		return _stateStack->size() > 0;
	}

	//Empties the entire state stack
	void EmptyStateStack(){
		if(StackIsEmpty())
			return;

		FSMState<stateType, interfaceType>* tempState = _stateStack->top();
		_stateStack->pop();
		while(PopState());

		_deadState = tempState;
	}

	//Deallocate the state stored in _deadState if it exists
	void ClearDeadState(){
		if(_deadState != NULL){
			delete _deadState;
			_deadState = NULL;
			return;
		}
	}

private:

	//state to use to manager the states
	std::stack<FSMState<stateType, interfaceType>*>* _stateStack;

	//list to maintain the dead states waiting to be deallocated
	FSMState<stateType, interfaceType>* _deadState;
};