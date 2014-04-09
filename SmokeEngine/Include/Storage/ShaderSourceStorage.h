#pragma once
#include <map>
#include <string>
#include "Utility\Source.h"

#define VERTEX_SOURCE "VERTEX_SOURCE"
#define FRAMGENT_SOURCE "FRAMGENT_SOURCE"
/**
*stores shader source to be used with multiple objects within the engine
**/
class ShaderSourceStorage
{
private:
	std::map<std::string,Source*> _shaderSource;
public:
	ShaderSourceStorage(void);
	~ShaderSourceStorage(void);

	/** 
	* appends the source to the storage 
	*
	* two id's can be the same given that the type is diffrent
	*/
	void AppendSource(std::string id, Source* source);
	
	/**
	*tells if the source is used
	**/
	bool IsSourceUsed(std::string id,GLenum Type);

	/** 
	 * retrives the source with the id 
	 *
	 * Type has to be GL_FRAGMENT_SHADER or GL_VERTEX_SHADER
	 *
	 *@return NULL if the Type is wrong
	*/
	Source* GetSource(std::string id, GLenum Type);

};

