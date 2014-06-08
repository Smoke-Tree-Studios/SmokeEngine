#include "Audio\AudioPlayer.h"
#include "Audio\AudioSource.h"
#include "S_Debug.h";

AudioPlayer::AudioPlayer(SLEngineItf* EngineObject,AudioSource * src,SLObjectItf*  _outputMixerObject)
{

	SLDataSink laudioSink;

	SLDataLocator_OutputMix loutPutMix = {SL_DATALOCATOR_OUTPUTMIX,*_outputMixerObject};
	laudioSink.pLocator = &loutPutMix;
	laudioSink.pFormat = NULL;

	SLInterfaceID ids[4] = {SL_IID_SEEK, SL_IID_MUTESOLO, SL_IID_VOLUME,SL_IID_PLAY};
	SLboolean req[4] = {SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE,SL_BOOLEAN_TRUE,SL_BOOLEAN_TRUE};

	SLEngineItf lengine = (*EngineObject);
	SLresult lresult = (*lengine)->CreateAudioPlayer(lengine,&_playerObject,src->getAudioSource(),&laudioSink,4,ids,req);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create audio player");

	 lresult = (*_playerObject)->Realize(_playerObject,SL_BOOLEAN_FALSE);
	 if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create player");

	lresult = (*_playerObject)->GetInterface(_playerObject,SL_IID_PLAY,&_playerPlay);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create player");

	lresult = (*_playerObject)->GetInterface(_playerObject,SL_IID_SEEK,&_playerSeek);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create seek");

	lresult = (*_playerObject)->GetInterface(_playerObject,SL_IID_MUTESOLO,&_playerMuteSolo);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create mute solo");

	lresult = (*_playerObject)->GetInterface(_playerObject,SL_IID_VOLUME,&_playerVolume);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create player volume");

	this->SetPaused(false);
}

void AudioPlayer::SetLooped(bool state)
{
	(*_playerSeek)->SetLoop(_playerSeek,(SLboolean)state,0,SL_TIME_UNKNOWN);
}

void AudioPlayer::SetPaused(bool state)
{
	if(!state)
	{
		(*_playerPlay)->SetPlayState(_playerPlay,SL_PLAYSTATE_PLAYING);
	}
	else
	{
		(*_playerPlay)->SetPlayState(_playerPlay,SL_PLAYSTATE_PAUSED);
	}
}

void AudioPlayer::SetChannelMute(int channel,bool state)
{

	(*_playerMuteSolo)->SetChannelMute(_playerMuteSolo,channel,state);

}

int AudioPlayer::GetNumberOfChannels()
{
	SLuint8 lnumberOfChannels = 0;
	 (*_playerMuteSolo)->GetNumChannels(_playerMuteSolo,&lnumberOfChannels);
	 return lnumberOfChannels;
}

int AudioPlayer::GetVolume()
{
	SLmillibel lvolume = 0;
	(*_playerVolume)->GetVolumeLevel(_playerVolume,&lvolume);
	return lvolume;
}

void AudioPlayer::SetVolume(int volume)
{
	SLmillibel lvolume = volume;
	(*_playerVolume)->SetVolumeLevel(_playerVolume,lvolume);

}

void AudioPlayer::SetStereoPosition(bool state,int position)
{
	if(position == 0)
	{
		(*_playerVolume)->EnableStereoPosition(_playerVolume,false);
	}
	else
	{
		(*_playerVolume)->EnableStereoPosition(_playerVolume,true);
		(*_playerVolume)->SetStereoPosition(_playerVolume,position);
	}

}


AudioPlayer::~AudioPlayer(void)
{
}
