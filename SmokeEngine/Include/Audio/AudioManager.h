#pragma once
#include "string"
#include "sles\OpenSLES.h"
#include "sles\OpenSLES_Android.h"
class AudioPlayer;
class AudioSource;
class AudioManager
{
private:

	//engine interface
	SLObjectItf _engineObject;
	SLEngineItf _mainEngine;

	//output mix interface
	SLObjectItf _outputMixerObject;

public:
	AudioManager(void);
	~AudioManager(void);

	AudioPlayer* PlayTrack(AudioSource * src);
	void PlaySound(AudioSource * src);
};

