#pragma once
#include <string>
#include <map>
#include <list>
class SmokeEngine;
class SceneNode;
class SmokeEngine;
class AAssetManager;
class AInputQueue;
class AInputEvent;
class InputEvent;
class SceneManager
{
	private:
		std::map<std::string,SceneNode*> _sceneNodes;
		SceneNode* _activeScene;
	protected:

	public:
		std::list<std::string> GetSceneIds();

		SmokeEngine* mSmokeEngine;
		/**
		*appends a scene to the manager that can be accessed later
		**/
		void AppendScene(std::string id, SceneNode * node);

		void UnloadAllScenes();

		void UnloadScene(std::string id);

		/**
		*sets the scene as the active view to be updated and rendered
		**/
		void SetActiveScene(std::string id);
		/**
		*returns the active scene
		**/
		SceneNode* GetActiveSceneNode();

		/**
		*updates the active scene and draws
		**/
		void Update(float DeltaT);


		/**
		*handles input
		**/
		void Input(InputEvent* Event);

		/**
		*delets the scene
		**/
		void DeleteScene(std::string id);

		/**
		*gets the scene node based on the given set id from append
		**/
		SceneNode* GetSceneNode(std::string id);

		SceneManager(SmokeEngine* smokeEngine);
		~SceneManager(void);
};

