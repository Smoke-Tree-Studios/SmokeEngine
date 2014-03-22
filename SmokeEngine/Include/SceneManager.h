#pragma once
#include <functional>
#include <string>
#include "Node\SceneNode.h"
#include "Storage\ViewStorage.h"
#include <map>

class SceneManager
{
	private:
		std::map<std::string,SceneNode*> _sceneNodes;
		SceneNode* _activeScene;
	protected:

	public:

		void AppendScene(std::string id, SceneNode * node);
		void SetActiveScene(std::string id);

		void Update(float DeltaT);

		SceneNode* GetSceneNode(std::string id);

		SceneManager(void);
		~SceneManager(void);
};

