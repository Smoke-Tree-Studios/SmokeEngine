#pragma once
#include "Node\SceneNode.h"
#include <string>
#include <opencv2\opencv.hpp>
#include <iostream>


class ObjectWavefrontLoader
{
public:
	ObjectWavefrontLoader(SceneNode * sceneNode, std::string filename);
	~ObjectWavefrontLoader(void);


};

