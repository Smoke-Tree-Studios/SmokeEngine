#include "Storage\ViewStorage.h"


ViewStorage::ViewStorage(void)
{
	_cameras = std::map<std::string,Camera*>();
}


ViewStorage::~ViewStorage(void)
{
}

void ViewStorage::AddCamera(std::string id,Camera * camera)
{
	_cameras.insert(std::pair<std::string,Camera*>(id,camera));

}


void ViewStorage::RemoveCamera(std::string id)
{
	delete( _cameras[id]);
	_cameras.erase(id);
}
Camera* ViewStorage::GetCamera(std::string id)
{
	return _cameras[id];
}
