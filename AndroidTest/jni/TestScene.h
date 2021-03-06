#pragma once
#include "Node\SceneNode.h"

class Node;
class ObjectNode;
class AInputQueue;
class TestScene : public SceneNode
{
private:
	ObjectNode * _testObject;
	Node * _lightNode;
	float x;
public:
	

	TestScene(SmokeEngine* smokeEngine,Camera * camera);
	~TestScene(void);

	virtual void Update(float deltaT);
	virtual void Input(InputEvent* Event) ;

	virtual void Load();
	virtual void UnLoad();
	virtual void Inintalize();
	virtual void InintalizeScene();
};

