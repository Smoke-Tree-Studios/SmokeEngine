#pragma once
#include <GLES2\gl2.h>
#include "string"
#include "Vector2.h"
#include <gles2\gl2.h>
#include <stdlib.h>

class Texture
{
private:
	GLuint _textureID;
	int _width;
	int _height;
	int _widthBuffer;
	int _heightBuffer;
	GLint _resourceID;

	std::string _textureName;

public:
	Texture(const char * filename);
	~Texture(void);

	/** returns the file name of the asset */
	std::string GetFilename();

	GLint GetResourceID();

	/** returns the texcoords width */
	float GetWidthScale();

	/** returns the texcoords height */
	float GetHeightScale();

	/** returns width to height ratio of the texture */
	float WidthToHeightRatio();

	/** returns height to width ratio of the texture */
	float HeightToWidthRatio();
	
};

