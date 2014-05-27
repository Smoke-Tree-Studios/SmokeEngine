#pragma once
#include "Node.h"
#include <string>
#include "Utility\Vector\Vector3.h"

class RenderObject;
class Matrix4x4;
class AttachmentNodeCallback;
class ObjectNode : public Node
{
private:
	std::map<std::string, AttachmentNodeCallback *> _attachmentNodeSet;
public:
	RenderObject * mRenderObject;
	Vector3 Origin;

	ObjectNode(std::string ID, RenderObject * renderObject);
	virtual ~ObjectNode(void);

	virtual Matrix4x4 GetMatrix();

	void AddAttchmentNodeCallback(std::string nodeType,AttachmentNodeCallback* attachmentNodeCallback);
	//removes the attachment node of the callback
	void RemoveAndDeleteAttachmentNodeCallback(std::string nodeType);
	
	virtual void Update();
	void Draw(Matrix4x4 transform, Matrix4x4 view);

	virtual std::string GetType();
};