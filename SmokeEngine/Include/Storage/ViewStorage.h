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

	/**
	*adds the camera to the storage
	**/
	void AddCamera(std::string id,Camera * camera);
	
	/**
	 * Removes the camera from the scene
	 **/
	void RemoveCamera(std::string id);
	
	/**
	 * retrieves the camera from storage
	 **/
	Camera * GetCamera(std::string id);

};

