#include "Storage\ShaderSourceStorage.h"
#include <GLES2/gl2.h>

ShaderSourceStorage::ShaderSourceStorage(void)
{
	_shaderSource = std::map<std::string,Source*>();

}


ShaderSourceStorage::~ShaderSourceStorage(void)
{
	for(std::map<std::string,Source*>::iterator iter = _shaderSource.begin(); iter != _shaderSource.end(); iter++)
	{
		delete(iter->second);
	}
}

void ShaderSourceStorage::AppendSource(std::string id, Source* source)
{
	if(source->GetType() == GL_FRAGMENT_SHADER)
	{
		_shaderSource.insert(std::pair<std::string,Source*>(id + FRAMGENT_SOURCE,source));
	}
	else if(source->GetType() == GL_VERTEX_SHADER)
	{
		_shaderSource.insert(std::pair<std::string,Source*>(id + VERTEX_SOURCE,source));
	}
}

Source* ShaderSourceStorage::GetSource(std::string id, GLenum Type)
{
	if(Type == GL_FRAGMENT_SHADER)
	{
		return _shaderSource[id + FRAMGENT_SOURCE];
	}
	else if (Type == GL_VERTEX_SHADER)
	{
		return _shaderSource[id + VERTEX_SOURCE];
	}
	return NULL;
}

void ShaderSourceStorage::DeleteSource(std::string id, GLenum Type)
{
	std::string lid = "";

	if(Type == GL_FRAGMENT_SHADER)
	{
		lid = id + FRAMGENT_SOURCE;
	}
	else if (Type == GL_VERTEX_SHADER)
	{
		lid =  id + VERTEX_SOURCE;
	}
	delete _shaderSource[lid];
	_shaderSource.erase(lid);
}

bool ShaderSourceStorage::IsSourceUsed(std::string id,GLenum Type)
{
	std::string lid = "";

	if(Type == GL_FRAGMENT_SHADER)
	{
		lid = id + FRAMGENT_SOURCE;
	}
	else if (Type == GL_VERTEX_SHADER)
	{
		lid =  id + VERTEX_SOURCE;
	}
	
	if(_shaderSource.count(lid))
	{
		return true;
	}
	else
	{
		return false;
	}
}
