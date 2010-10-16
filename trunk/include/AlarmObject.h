#pragma once

#include <string>

//An alarm object which is a single alarm. A message is stored and sent back to the
//alarm system whenever the timer is expired. This class may be inherited to make
//custom alarms
class AlarmObject{
	friend class AlarmSystem;

#pragma region public

public:
	//Constructor
	AlarmObject(double timeLeft, std::string message){
		_timeLeft = timeLeft;
		_message = message;
	}

#pragma endregion

#pragma region protected

protected:
	//virtual destructor ensures proper destructor execution order
	virtual ~AlarmObject(){}

	//sets the alarm system managing this alarm
	void SetAlarmSystem(AlarmSystem* system){
		_system = system;
	}

	//updates the alarm system for this frame
	virtual bool Update(double timeElapsed){
		_timeLeft -= timeElapsed;

		//set off the alarm event whenever the timer is expired
		if(_timeLeft <= 0){
			_system->AlarmEvent(_message);
			return true;
		}

		//timer has not been expired yet
		return false;
	}

#pragma endregion

#pragma region private

private:
	//the alarm system managing this alarm object
	AlarmSystem* _system;

	//the message this alarm system will pass back
	std::string _message;

	//the time left for this alarm
	double _timeLeft;

#pragma endregion

};