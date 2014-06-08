#include "Storage\AudioSourceStorage.h"
#include "Audio\AudioSource.h"
#include <map>

AudioSourceStorage::AudioSourceStorage(void)
{
	_audioSource = std::map<std::string,AudioSource*>();
}


AudioSourceStorage::~AudioSourceStorage(void)
{
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

AudioSource*  AudioSourceStorage::GetSource(std::string id)
{
	return _audioSource[id];
}

