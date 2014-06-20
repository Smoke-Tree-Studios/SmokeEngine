#pragma once
#include "Render/RenderObject.h"
#define SPRITE_VERTICIES_SIZE 12
#define SPRITE_VERTICIES {0,0,0, 1,0,0, 0,1,0, 1,1,0 }

#define SPRITE_INDECIES_SIZE 6
#define SPRITE_INDECIES {2,0,1,2,1,3}

#define SPRITE_VERTEX_SHADER "\
attribute  vec3 in_Verts; \
attribute float in_Index; \
uniform mat4 in_Transform; \
uniform mat4 in_View; \
uniform vec2 in_Clipping_Position; \
uniform vec2 in_Clipping_Size; \
varying mediump vec2 p_TexCoords; \
void main(void)\
{ \
	gl_Position =in_View *  in_Transform * vec4(in_Verts,1.0); \
	if(int(in_Index) == 0) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x ,in_Clipping_Position.y + in_Clipping_Size.y); \
	} \
	else if(int(in_Index) == 1) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x+in_Clipping_Size.x,in_Clipping_Position.y + in_Clipping_Size.y); \
	} \
	else if(int(in_Index) == 2) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x,in_Clipping_Position.y); \
	} \
	else if(int(in_Index) == 3) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x+ in_Clipping_Size.x,in_Clipping_Position.y); \
	} \
}"
#define SPRITE_FRAGMENT_SHADER "\
varying mediump vec2 p_TexCoords; \
uniform sampler2D in_BaseImage\
\
void main()\
{\
gl_gragColor = texture2d(in_BaseImage,p_TexCoords);\
}"
#define SPRITE "SMOKE_SPRITE"
class Vector2;
class Matrix4x4;
class SceneNode;
class VertexBufferObjectWithSubData;
class VertexArrayObject;
class Source;
class Texture;
class Sprite : public RenderObject
{
private:
	VertexArrayObject * mVertexArrayObject;
	SceneNode * _sceneNode;
	//sprite intalization
	void _initialize(SceneNode * sceneNode);
public:
	VertexBufferObjectWithSubData * mVertexSubData;
	/**
	*create a spirte object with custom fragment shader
	*textures will have to be done manually in shader
	**/
	Sprite(SceneNode * sceneNode,Source * fragmentShader);
	/**
	*
	**/
	Sprite(SceneNode * sceneNode,Texture * texture);
	~Sprite(void);

	/**
	*sets the clipping rectangle for the sprite
	*ranged from 0 to 1 based on tex coords
	**/
	void SetClippingRectangle(Vector2 pos, Vector2 size);

	virtual void Draw(Matrix4x4 transform, Matrix4x4 view);
	virtual void DepthDraw(Matrix4x4 transform, Matrix4x4 view);

};

