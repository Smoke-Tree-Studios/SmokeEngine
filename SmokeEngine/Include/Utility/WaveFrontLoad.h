#pragma once
#include <string>
#include <vector>

class VertexBufferObjectWithSubData;
class VertexArrayObject;
class AAssetManager;
class WaveFrontLoad
{
private:
	/**
	*splits the string out of a float
	**/
	 static std::vector<float> _splitFloat(std::string str,std::string character);
	 /**
	 *splits intiger values out of a string
	 **/
	 static std::vector<int> _splitInt(std::string str,std::string character);
public:
	/**
	*loads the wavefront file and stores the values within the subdata object and array object
	**/
	static VertexArrayObject* Load(const char* file,AAssetManager* assetManager, VertexBufferObjectWithSubData * vertexBufferObjectWithSubData);
};

