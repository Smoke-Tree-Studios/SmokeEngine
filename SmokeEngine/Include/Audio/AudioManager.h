#pragma once
#include "string"
#include "sles\OpenSLES.h"
#include "sles\OpenSLES_Android.h"
#include "list"
class AudioPlayer;
class AudioSource;
class AudioManager
{
private:
	std::list<AudioPlayer*> _audio;
	SLObjectItf _engineObject;
	SLEngineItf _mainEngine;
	SLObjectItf _outputMixerObject;

public:

	AudioManager(void);
	~AudioManager(void);

	/**
	*plays the track
	**/
	AudioPlayer* PlayTrack(AudioSource * src);

	/**
	*play the sound
	**/
	void PlaySound(AudioSource * src);

	void ClearAudioBuffer();

	void Update();
};

