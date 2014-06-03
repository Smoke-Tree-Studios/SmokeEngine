#include "Audio/AudioManager.h"
#include "S_Debug.h"

AudioManager::AudioManager(void)
{
	SLresult lresult;

	// engine
	const SLuint32 lengineMixIIDCount = 1;
	const SLInterfaceID lengineMixIIDs[] = {SL_IID_ENGINE};
	const SLboolean lengineMixReqs[] = {SL_BOOLEAN_TRUE};

	//create engine
	lresult = slCreateEngine(&_engineObject,0,NULL,lengineMixIIDCount,lengineMixIIDs,lengineMixReqs);
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
    const SLInterfaceID ids[1] = {SL_IID_ENVIRONMENTALREVERB};
    const SLboolean req[1] = {SL_BOOLEAN_FALSE};
	lresult = (*_mainEngine)->CreateOutputMix(_mainEngine, &_outputMixerObject, 1, ids, req);
	if (lresult != SL_RESULT_SUCCESS)
	  ERROR("can't create audio mix");

	// realize the output mix
    lresult = (*_outputMixerObject)->Realize(_outputMixerObject, SL_BOOLEAN_FALSE);
	  ERROR("can't realize audio mix");
}


AudioManager::~AudioManager(void)
{
}
