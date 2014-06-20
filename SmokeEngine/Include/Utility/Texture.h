#pragma once

#include "string"
#include <GLES2\gl2.h>
#include <stdlib.h>


class AAssetManager;
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
	Texture(const char * filename,AAssetManager* assetManager);
	~Texture(void);

	/** 
	*returns the file name of the asset 
	**/
	std::string GetFilename();

	GLint GetResourceID();

	/** 
	*returns the texcoords value minus the buffer area outside of the texture area
	**/
	float GetWidthScale();

	/** 
	*returns the texcoords height 
	**/
	float GetHeightScale();

	/** 
	*returns width to height ratio of the texture 
	**/
	float WidthToHeightRatio();

	/** 
	*returns height to width ratio of the texture 
	**/
	float HeightToWidthRatio();
	
};

