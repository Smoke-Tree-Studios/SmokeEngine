#include "Storage\TextureStorage.h"
#include "Utility\Texture.h"

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

bool TextureStorage::IsTextureUsed(std::string id)
{
	if(_textures.count(id))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TextureStorage::DeleteTexture(std::string id)
{
	delete(_textures[id]);
	_textures.erase(id);
	
}

Texture* TextureStorage::GetTexture(std::string id)
{
	return _textures[id];
}