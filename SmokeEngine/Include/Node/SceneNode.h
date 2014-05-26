#pragma once
#include "Node.h"
#include "SmokeEngine.h"

class SceneManager;
class ShaderSourceStorage;
class TextureStorage;
class VertexBufferStorage;
class ViewStorage;
class Camera;
class SmokeEngine;
class SceneManager;
class AttachmentNode;
class SharedNodeInfo;
class SceneNode
{
private:
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

	ShaderSourceStorage * mShaderSourceStorage;
	TextureStorage * mTextureStorage;
	VertexBufferStorage * mVertexBufferStorage;
	ViewStorage * mViewStorage;

	SceneManager * mSceneManager;

	RootNode * mRootSceneNode;
	RootNode * mRootOverlayNode;

	SmokeEngine * mSmokeEngine;

	virtual void Update(float deltaT) =0;

	SceneNode( SmokeEngine* smokeEngine,Camera * camera);
	~SceneNode(void);
};

