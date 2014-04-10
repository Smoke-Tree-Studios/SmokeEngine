#pragma once
#include "Node\SceneNode.h"

class ObjectNode;
class TestScene : public SceneNode
{
private:
	ObjectNode * _testObject;

public:
	

	TestScene(SmokeEngine* smokeEngine,Camera * camera);
	~TestScene(void);

	virtual void Update(float deltaT);
};

