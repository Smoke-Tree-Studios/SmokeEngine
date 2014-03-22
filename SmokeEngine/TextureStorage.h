#pragma once
#include "Texture.h"
#include <map>
class TextureStorage
{
private:
	std::map<std::string,Texture*> _textures;
public:
	TextureStorage();
	~TextureStorage(void);

	/** append texture to the texturestorage*/
	void AppendTexture(Texture* texture);

	/** removes the texture from the set */
	void RemoveTexture(std::string id);

	/** retrieves the texture from storage */
	Texture* GetTexture(std::string id);
};

