#pragma once
#include "Utility\Vector\Vector2.h"
class AInputEvent;
class AInputQueue;
class InputEvent
{
private:
	int _index;
	AInputEvent* _event;
public:
	InputEvent(AInputEvent* InputEvent);
	InputEvent(AInputEvent* InputEvent,int index);
	~InputEvent(void);

	/**
	*get the position of the input
	**/
	Vector2 GetPosition();
	
	/**
	*get the index of the input
	**/
	int GetIndex();

	/**
	*gets the action of the event
    *AINPUT_EVENT_TYPE_KEY 
    *AINPUT_EVENT_TYPE_MOTION
	**/
	int GetAction();

	/**
	*get the pressure of the input
	**/
	float GetPressure();

};

