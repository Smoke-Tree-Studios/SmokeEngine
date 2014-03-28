#include "SceneManager.h"


SceneManager::SceneManager(SmokeEngine* smokeEngine)
{
	mSmokeEngineEngine = smokeEngine;
	_sceneNodes = std::map<std::string,SceneNode*>();
}

SceneManager::~SceneManager(void)
{
	
}

void SceneManager::AppendScene(std::string id, SceneNode * node)
{
	_sceneNodes.insert(std::pair<std::string,SceneNode*>(id,node));
}


void SceneManager::SetActiveScene(std::string id)
{
	_activeScene = _sceneNodes[id];
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