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
	SLMuteSoloItf _playerMuteSolo;
	SLVolumeItf _playerVolume;


public:
	AudioPlayer(SLEngineItf *EngineObject,AudioSource * src,SLObjectItf*  _outputMixerObject);
	~AudioPlayer(void);

	void SetLooped(bool state);
	void SetPaused(bool state);
	void SetChannelMute(int channel,bool state);
	int GetNumberOfChannels();
	int GetVolume();
	void SetVolume(int volume);
	void SetStereoPosition(bool state,int position);


};

