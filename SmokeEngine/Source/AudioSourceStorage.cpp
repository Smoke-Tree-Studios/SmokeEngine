#include "Storage\AudioSourceStorage.h"
#include "Audio\AudioSource.h"
#include <map>

AudioSourceStorage::AudioSourceStorage(void)
{
	_audioSource = std::map<std::string,AudioSource*>();
}


AudioSourceStorage::~AudioSourceStorage(void)
{
	for(std::map<std::string,AudioSource*>::iterator iter = _audioSource.begin(); iter != _audioSource.end(); iter++)
	{
		delete(iter->second);
	}
	_audioSource.clear();

}

void AudioSourceStorage::AppendAudioSource(std::string id,AudioSource * src )
{
	_audioSource.insert(std::pair<std::string,AudioSource*>(id,src));
}

void AudioSourceStorage::RemoveAudioSource(std::string id)
{
	delete(_audioSource[id]);
	_audioSource.erase(id);
}

bool AudioSourceStorage::IsAudioSourceUsed(std::string id)
{
	if(_audioSource.count(id))
	{
		return true;
	}
	else
	{
		return false;
	}
}

AudioSource*  AudioSourceStorage::GetSource(std::string id)
{
	return _audioSource[id];
}

