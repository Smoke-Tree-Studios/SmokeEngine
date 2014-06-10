#include "SceneManager.h"
#include "Node\SceneNode.h"
#include "SmokeEngine.h"
#include "egl\egl.h"
#include "egl\eglext.h"

SceneManager::SceneManager(SmokeEngine* smokeEngine)
{
	mSmokeEngine = smokeEngine;
	_sceneNodes = std::map<std::string,SceneNode*>();
}

SceneManager::~SceneManager(void)
{
	
}

void SceneManager::AppendScene(std::string id, SceneNode * node)
{
	_sceneNodes.insert(std::pair<std::string,SceneNode*>(id,node));
}

void  SceneManager::DeleteScene(std::string id)
{
	delete(_sceneNodes[id]);
	_sceneNodes.erase(id);
}

void SceneManager::SetActiveScene(std::string id)
{
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