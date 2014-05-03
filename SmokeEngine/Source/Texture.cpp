#include "Utility\Texture.h"
#include <android\log.h>
#include "Utility\LodePNG.h"

extern unsigned int POWER_TWO [26] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};


Texture::Texture(const char * filename,AAssetManager* assetManager)
{

	_textureName = filename;

	AAsset* lasset = AAssetManager_open(assetManager,filename,AASSET_MODE_UNKNOWN);

	if(NULL == lasset)
	{
		 __android_log_print(ANDROID_LOG_ERROR,"SMOKE_ENGINE",(char*)("Failed to open: " + std::string(filename)).c_str());
	}

	long lsize = AAsset_getLength(lasset);

	 char* lbuffer = (char*) malloc(sizeof(char)*lsize);
	AAsset_read(lasset,lbuffer,lsize);

	size_t width, height;
	unsigned char* loutput;
	lodepng_decode32(&loutput, &width, &height,(unsigned char*) lbuffer,lsize);

	glGenTextures(1, (&_textureID));   
	
	glBindTexture(GL_TEXTURE_2D,_textureID);               
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S , GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,loutput);
		
	for(int x = 0; x < 26;x++)
	{
			if(_width > POWER_TWO[x])
			{
				_widthBuffer = ((float)POWER_TWO[x]);
			}
	}

	for(int y = 0; y < 26;y++)
	{
		if(_height > POWER_TWO[y])
		{
			_heightBuffer =((float)POWER_TWO[y]);
		}
	}
	
}


std::string Texture::GetFilename()
{
	return _textureName;
}

float Texture::GetWidthScale()
{
	return (((float)_width) /((float)(_width +_widthBuffer)));
}

float Texture::GetHeightScale()
{
	return (((float)_height) /((float)(_height +_heightBuffer)));
}


GLint Texture::GetResourceID()
{
	return _textureID;
}


Texture::~Texture(void)
{
	glDeleteTextures(1,&_textureID);
}


float Texture::WidthToHeightRatio()
{
	return ((float)_width)/((float)_height);
}

float Texture::HeightToWidthRatio()
{
	return ((float)_height)/((float)_width);
}