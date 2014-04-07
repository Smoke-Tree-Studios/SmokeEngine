#pragma once
#include <string>
#include <map>

class SmokeEngine;
class SceneNode;
class SmokeEngine;
class AAssetManager;
class SceneManager
{
	private:
		std::map<std::string,SceneNode*> _sceneNodes;
		SceneNode* _activeScene;
	protected:

	public:
		SmokeEngine* mSmokeEngine;

		void AppendScene(std::string id, SceneNode * node);

		void SetActiveScene(std::string id);
		SceneNode* GetActiveSceneNode();

		void Update(float DeltaT);

		SceneNode* GetSceneNode(std::string id);

		SceneManager(SmokeEngine* smokeEngine);
		~SceneManager(void);
};

