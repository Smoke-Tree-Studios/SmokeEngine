#pragma once
#include "Node.h"
#include "SmokeEngine.h"

class SceneManager;
class ViewStorage;
class Camera;
class SmokeEngine;
class SceneManager;
class AttachmentNode;
class SharedNodeInfo;
class AInputQueue;
class SceneNode
{
private:
	bool _isLoaded;
	//node information that is shared between all the nodes
	SharedNodeInfo* _sharedNodeInfo;
protected:
	class RootNode : public Node
	{
		public:
			RootNode(SceneNode * sceneNode,SharedNodeInfo* sharedNodeInfo, std::string ID);
			virtual std::string GetType();
	};
public:
	//the main camera 
	Camera * mMainCamera;

	ViewStorage * mViewStorage;
	RootNode * mRootSceneNode;
	RootNode * mRootOverlayNode;

	SmokeEngine * mSmokeEngine;

	/**
	*updates the scene with the given deltaT value
	**/
	virtual void Update(float deltaT) =0;
	virtual void Input(InputEvent* Event) = 0;

	virtual void Load();
	virtual void UnLoad();
	virtual void Inintalize() = 0;
	virtual void InintalizeScene() = 0;

	bool IsLoad();

	SceneNode( SmokeEngine* smokeEngine,Camera * camera);
	~SceneNode(void);
};

