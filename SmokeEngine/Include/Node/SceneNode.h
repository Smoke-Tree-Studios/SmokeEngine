#pragma once
#include "SmokeEngine.h"
#include "Node.h"
#include "SceneManager.h"
#include "Storage\ShaderSourceStorage.h"
#include "Storage\TextureStorage.h"
#include "Storage\VertexBufferStorage.h"
#include "Storage\ViewStorage.h"

class SmokeEngine;
class SceneManager;
class SceneNode
{
private:
	std::map<std::string, Node*>* _nodes;

protected:
	class RootNode : public Node
	{
		public:
			RootNode(SceneNode * sceneNode,std::map<std::string, Node* >* nodes, std::string ID);
	};
public:
	ShaderSourceStorage * mShaderSourceStorage;
	TextureStorage * mTextureStorage;
	VertexBufferStorage * mVertexBufferStorage;
	ViewStorage * mStorageView;

	SceneManager * mSceneManager;

	RootNode * mRootSceneNode;
	RootNode * mRootOverlayNode;

	SmokeEngine * mSmokeEngine;

	virtual void Update(float deltaT) =0;

	SceneNode(SceneManager* sceneManager, SmokeEngine* smokeEngine);
	~SceneNode(void);
};

