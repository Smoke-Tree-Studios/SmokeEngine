#pragma once
#include "string"
#include <sles\OpenSLES_Android.h>
class AudioManager
{
private:

	SLresult _res;
public:
	void LoadAudio(std::string id, std::string file);

	AudioManager(void);
	~AudioManager(void);
};

