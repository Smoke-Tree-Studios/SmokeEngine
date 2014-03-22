#pragma once
#include <map>
#include <string>
#include "Utility\Source.h"


#define VERTEX_SOURCE "VERTEX_SOURCE"
#define FRAMGENT_SOURCE "FRAMGENT_SOURCE"

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
	 * retrives the source with the id 
	 *
	 * Type has to be GL_FRAGMENT_SHADER or GL_FRAGMENT_SHADER
	 *
	 *@return NULL if the Type is wrong
	*/
	Source* GetSource(std::string id, GLenum Type);

};

