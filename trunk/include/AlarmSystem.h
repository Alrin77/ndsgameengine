#pragma once

#include <string>
#include <vector>
#include "AlarmObject.h"

//An alarm system class allows alarms to be registered and receive alarm events. Inherit this class
//to make it an alarm system. Must overwrite the AlarmEvent function to receive the alarm events and
//take the necessary actions
class AlarmSystem{
	friend AlarmObject;
#pragma region public

public:
	//Create an alarm in this alarm system
	void CreateAlarm(int timeLeft, std::string message){
		CreateAlarm(new AlarmObject((double)timeLeft, message));
	}

	//Create an alarm in this alarm system
	void CreateAlarm(float timeLeft, std::string message){
		CreateAlarm(new AlarmObject((double)timeLeft, message));
	}

	//Create an alarm in this alarm system
	void CreateAlarm(double timeLeft, std::string message){
		CreateAlarm(new AlarmObject(timeLeft, message));
	}

	//Create an alarm in this alarm system
	void CreateAlarm(AlarmObject* newAlarm){
		newAlarm->SetAlarmSystem(this);
		_alarms->push_back(newAlarm);
	}

	//Update all of the currently active alarms
	virtual void Update(double timer){
		for(std::vector<AlarmObject*>::iterator it = _alarms->begin(); it != _alarms->end();){
			if((*it)->Update(timer)){
				delete *it;
				it = _alarms->erase(it);
			}else 
				it++;
		}
	}

#pragma endregion

#pragma region protected

protected:
	//Constructor
	AlarmSystem(){
		_alarms = new std::vector<AlarmObject*>();
	}

	//Destructor
	virtual ~AlarmSystem(){
		while(!_alarms->empty()){
			delete _alarms->back();
			_alarms->pop_back();
		}
		delete _alarms;
	}

	//Called whenever an alarm timer expires and the alarms' message is passed in
	virtual void AlarmEvent(std::string message)=0;

#pragma endregion

#pragma region private

private:
	//Contains all of the active alarms
	std::vector<AlarmObject*>* _alarms;

#pragma endregion
};