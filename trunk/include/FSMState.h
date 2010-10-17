#pragma once

#include <string>

//forward declaration
template <class stateType, class interfaceType>
class FSM;

//A templated state which can be managed by the FSM class. Must be inherited
//by all states managed by the FSM class.
//First parameter should be the state which inherits this class.
//Second parameter is the interface type which the states will use to send
//callbacks to the manager
template <class stateType, class interfaceType>
class FSMState{
	friend class FSM<stateType, interfaceType>;

public:
	//Returns the FSM which is managing this state
	interfaceType* Machine(){
		return _machine;
	}

	std::string GetStateName(){
		return _stateName;
	}

protected: 
	//Virtual destructor ensures inherited destructors are called in the
	//correct order
	virtual ~FSMState(){};

	//Sets the manager which is managing this state. Allows states to 
	//send callbacks to the manager
	void SetManager(interfaceType* machine){
		_machine = machine;
	}
	
	std::string _stateName;

private:
	//reference to the FSM managing this state
	interfaceType* _machine;

	
};

