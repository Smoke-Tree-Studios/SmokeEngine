#pragma once
#include "Node\SceneNode.h"

class Node;
class ObjectNode;
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
};

