#include "Input\InputEvent.h"
#include "android\input.h"

InputEvent::InputEvent(AInputEvent* InputEvent)
{
	_event = InputEvent;
	_index = AKeyEvent_getKeyCode(InputEvent);
}

InputEvent::InputEvent(AInputEvent* InputEvent,int index)
{
	_event = InputEvent;
	_index = index;

}

Vector2 InputEvent::GetPosition()
{
	return Vector2(AMotionEvent_getX(_event,_index),AMotionEvent_getY(_event,_index));
}

int InputEvent::GetIndex()
{
	return _index;
}

int InputEvent::GetAction()
{
	return AInputEvent_getType(_event);
}

float InputEvent::GetPressure()
{
	AMotionEvent_getPressure(_event,_index);
}


InputEvent::~InputEvent(void)
{
}
