#pragma once
#include <string>
#include <map>
class AudioSource;
class AudioSourceStorage
{
private:
	std::map<std::string,AudioSource*> _audioSource;
public:
	void AppendAudioSource(std::string id,AudioSource * src );
	void RemoveAudioSource(std::string id);
	AudioSource *  GetSource(std::string id);


	AudioSourceStorage(void);
	~AudioSourceStorage(void);
};

