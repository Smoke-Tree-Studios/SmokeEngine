#pragma once
#include <string>
#include "sles\OpenSLES.h"
#include "sles\OpenSLES_Android.h"

class AAssetManager;
class AudioSource
{
private:
	
	SLDataSource _audioSource;
	SLDataFormat_MIME _formatMime;
	SLDataLocator_AndroidFD _locFd;

public:
	AudioSource(void* data);
	AudioSource(const char* fileLocation,AAssetManager* assetManager);
	SLDataSource* getAudioSource();
	~AudioSource(void);
};

