#include "SceneManager.h"
#include "Node\SceneNode.h"
#include "SmokeEngine.h"
#include "egl\egl.h"
#include "egl\eglext.h"

SceneManager::SceneManager(SmokeEngine* smokeEngine)
{
	mSmokeEngine = smokeEngine;
	_sceneNodes = std::map<std::string,SceneNode*>();
	_activeScene = NULL;
}

SceneManager::~SceneManager(void)
{
	
}

void SceneManager::AppendScene(std::string id, SceneNode * node)
{
	node->Inintalize();
	_sceneNodes.insert(std::pair<std::string,SceneNode*>(id,node));
}

std::list<std::string> SceneManager::GetSceneIds()
{
	std::list<std::string> lids = std::list<std::string>();
	for(std::map<std::string,SceneNode*>::iterator iter = _sceneNodes.begin(); iter != _sceneNodes.end(); iter++)
	{
	lids.push_back(iter->first);
	}
	return lids;
}

void SceneManager::UnloadAllScenes()
{
	for(std::map<std::string,SceneNode*>::iterator iter = _sceneNodes.begin(); iter != _sceneNodes.end(); iter++)
	{
		iter->second->UnLoad();
	}

}

void SceneManager::UnloadScene(std::string id)
{
	_sceneNodes[id]->UnLoad();
}

void  SceneManager::DeleteScene(std::string id)
{
	delete(_sceneNodes[id]);
	_sceneNodes.erase(id);
}

void SceneManager::SetActiveScene(std::string id)
{
	if(!_sceneNodes[id]->IsLoad())
		_sceneNodes[id]->Load();
	_sceneNodes[id]->InintalizeScene();

	_activeScene = _sceneNodes[id];

}

void SceneManager::Input(InputEvent* Event)
{
	_activeScene->Input(Event);
}

SceneNode* SceneManager::GetSceneNode(std::string id)
{
	return _sceneNodes[id];
}

void SceneManager::Update(float DeltaT)
{
	_activeScene->Update(DeltaT);

}

SceneNode* SceneManager::GetActiveSceneNode()
{

	return _activeScene;
}