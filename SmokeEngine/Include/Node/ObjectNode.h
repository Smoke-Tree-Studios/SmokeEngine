#pragma once

#include <map>
#include <string>
#include "Node.h"
#include "Utility/Vector/Vector3.h"

class RenderObject;
class Matrix4x4;
class AttachmentNodeCallback;

class ObjectNode : public Node
{
private:
	std::map<std::string, AttachmentNodeCallback *> _attachmentNodeSet;
public:
	RenderObject * mRenderObject;
	//the origin of the object for the given item
	Vector3 Origin;

	ObjectNode(std::string ID, RenderObject * renderObject);
	virtual ~ObjectNode(void);

	/**
	*returns the matrix of the object
	**/
	virtual Matrix4x4 GetMatrix();

	/**
	*adds the attachment node callback to the object node
	**/
	void AddAttchmentNodeCallback(std::string nodeType,AttachmentNodeCallback* attachmentNodeCallback);

	/**
	*removes the attachment node from the callback based on the type
	**/
	void RemoveAndDeleteAttachmentNodeCallback(std::string nodeType);
	
	/**
	*updates the object node
	**/
	virtual void Update();
	void Draw(Matrix4x4 transform, Matrix4x4 view);

	/**
	*returns the objects type for the given class object
	**/
	virtual std::string GetType();
};