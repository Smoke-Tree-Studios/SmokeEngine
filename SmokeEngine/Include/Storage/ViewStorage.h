#pragma once
#include <map>
#include "Utility\Camera.h"
#include <string>
class ViewStorage
{
private:
	std::map<std::string,Camera*> _cameras;
public:
	ViewStorage(void);
	~ViewStorage(void);

	void AddCamera(std::string id,Camera * camera);
	void RemoveCamera(std::string id);
	Camera * GetCamera(std::string id);

};

