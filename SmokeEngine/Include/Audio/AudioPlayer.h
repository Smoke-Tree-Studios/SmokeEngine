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

	/**
	*loop the player
	**/
	void SetLooped(bool state);

	/**
	*pause the player
	**/
	void SetPaused(bool state);

	/**
	*mute or unmute a channel
	**/
	void SetChannelMute(int channel,bool state);

	/**
	*get the number of channels
	**/
	int GetNumberOfChannels();

	/**
	*gets the volume of the player
	**/
	int GetVolume();

	/**
	*sets the volume of the player
	**/
	void SetVolume(int volume);

	/**
	*sets the stero position of the player
	**/
	void SetStereoPosition(bool state,int position);

	/**
	*get the state of the player
	**/
	int GetPlayerState();


};

