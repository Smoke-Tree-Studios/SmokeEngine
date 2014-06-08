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
	/**
	*declaring the audio source as data
	**/
	AudioSource(void* data);

	/**
	*loading the audio source from the file location
	**/
	AudioSource(const char* fileLocation,AAssetManager* assetManager);

	/**
	*retrieves the audio source used for the player
	**/
	SLDataSource* getAudioSource();
	~AudioSource(void);
};

