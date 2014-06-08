#include "Audio/AudioManager.h"
#include "S_Debug.h"
#include "Audio\AudioSource.h"
#include "Audio\AudioPlayer.h"

AudioManager::AudioManager(void)
{
	SLresult lresult;

	// engine
	const SLInterfaceID lengineMixIIDs[] = {SL_IID_ENGINE};
	const SLboolean lengineMixReqs[] = {SL_BOOLEAN_TRUE};
	lresult = slCreateEngine(&_engineObject,0,NULL,1,lengineMixIIDs,lengineMixReqs);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create audio engine");

	//realize engine
	 lresult = (*_engineObject)->Realize(_engineObject, SL_BOOLEAN_FALSE);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't realize audio engine");

	 // get interfaces
	 lresult = (*_engineObject)->GetInterface(_engineObject, SL_IID_ENGINE, &_mainEngine);
	 if (lresult != SL_RESULT_SUCCESS)
	  ERROR("can't create audio interface");




	// create output mix, with environmental reverb specified as a non-required interface
	 const SLInterfaceID ids[0] = {};
    const SLboolean req[0] = {};
	lresult = (*_mainEngine)->CreateOutputMix(_mainEngine, &_outputMixerObject, 0, ids, req);
	if (lresult != SL_RESULT_SUCCESS)
	  ERROR("can't create audio mix");

	// realize the output mix
    lresult = (*_outputMixerObject)->Realize(_outputMixerObject, SL_BOOLEAN_FALSE);
	if (lresult != SL_RESULT_SUCCESS)
	  ERROR("can't realize audio mix");
}


AudioPlayer* AudioManager::PlayTrack(AudioSource * src)
{
	AudioPlayer * lplayer = new AudioPlayer(&_mainEngine,src,&_outputMixerObject);
	lplayer->SetLooped(true);
	return lplayer;

}
void AudioManager::PlaySound(AudioSource * src)
{

}


AudioManager::~AudioManager(void)
{
}
