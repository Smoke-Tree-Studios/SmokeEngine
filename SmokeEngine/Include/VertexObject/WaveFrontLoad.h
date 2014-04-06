#pragma once
#include <string>
#include <vector>

class VertexBufferObjectWithSubData;
class VertexArrayObject;
class AAssetManager;
class WaveFrontLoad
{
private:
	 static std::vector<float> _splitFloat(std::string str,std::string character);
	 static std::vector<int> _splitInt(std::string str,std::string character);
public:
	static VertexArrayObject* Load(const char* file,AAssetManager* assetManager, VertexBufferObjectWithSubData * vertexBufferObjectWithSubData);
};

