#pragma once
#include "Audio/AudioManager.h"
#include "sles\OpenSLES_Android.h"

class AudioSource;
class AudioPlayer
{
private:
	SLObjectItf _playerObject;

	SLPlayItf _playerPlay;
	SLSeekItf _playerSeek;
	SLMuteSoloItf _playerMutoSolo;


public:
	AudioPlayer(SLEngineItf * EngineObject,AudioSource * src,SLObjectItf * _outputMixerObject);
	~AudioPlayer(void);
};

