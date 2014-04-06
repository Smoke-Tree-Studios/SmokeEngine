#pragma once
#include "Node\SceneNode.h"

class TestScene : public SceneNode
{
public:
	
	TestScene(SmokeEngine* smokeEngine,Camera * camera);
	~TestScene(void);

	virtual void Update(float deltaT);
};

