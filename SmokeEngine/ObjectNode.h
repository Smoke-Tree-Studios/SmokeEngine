#pragma once
#include "Node.h"
#include <string>
#include "Matrix4x4.h"


class ObjectNode : public Node
{
protected:

public:

	ObjectNode(std::string ID);
	virtual ~ObjectNode(void);

	virtual Matrix4x4 GetMatrix();
	void Draw();

};

