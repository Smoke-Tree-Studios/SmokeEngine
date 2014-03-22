#include "TextureStorage.h"
#include "Texture.h"

TextureStorage::TextureStorage()
{
	_textures = std::map<std::string,Texture*>();
}


TextureStorage::~TextureStorage(void)
{
	for(std::map<std::string,Texture*>::iterator iter = _textures.begin(); iter != _textures.end(); iter++)
	{
		delete(iter->second);
	}

}

void TextureStorage::AppendTexture(Texture* texture)
{
	_textures.insert(std::pair<std::string,Texture*>(texture->GetFilename(),texture));
}

void TextureStorage::RemoveTexture(std::string id)
{
	Texture * ltexture = _textures[id];
	_textures.erase(id);
	delete(ltexture);
}

Texture* TextureStorage::GetTexture(std::string id)
{
	return _textures[id];
}