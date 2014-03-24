#pragma once
#include <functional>
#include <string>
#include "Node\SceneNode.h"
#include "Storage\ViewStorage.h"
#include "SmokeEngine.h"
#include <map>

class SceneNode;
class SmokeEngine;
class SceneManager
{
	private:
		std::map<std::string,SceneNode*> _sceneNodes;
		SceneNode* _activeScene;
	protected:

	public:
		SmokeEngine* mSmokeEngineEngine;

		void AppendScene(std::string id, SceneNode * node);
		void SetActiveScene(std::string id);

		void Update(float DeltaT);

		SceneNode* GetSceneNode(std::string id);

		SceneManager(SmokeEngine* smokeEngine);
		~SceneManager(void);
};

