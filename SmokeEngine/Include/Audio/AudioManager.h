#pragma once
#include "string"
class AudioManager
{
private:

public:
	void LoadAudio(std::string id, std::string file);

	AudioManager(void);
	~AudioManager(void);
};

