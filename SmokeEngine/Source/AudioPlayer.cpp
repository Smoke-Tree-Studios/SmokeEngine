#include "Audio\AudioPlayer.h"
#include "Audio\AudioSource.h"
#include "S_Debug.h";

AudioPlayer::AudioPlayer(SLEngineItf * EngineObject,AudioSource * src,SLObjectItf * _outputMixerObject)
{

	SLDataSink* laudioSink = new SLDataSink();

	SLDataLocator_OutputMix loutPutMix = {SL_DATALOCATOR_OUTPUTMIX,*_outputMixerObject};
	laudioSink->pLocator = &loutPutMix;
	laudioSink->pFormat = NULL;

	SLInterfaceID ids[3] = {SL_IID_SEEK, SL_IID_MUTESOLO, SL_IID_VOLUME};
	SLboolean req[3] = {SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE,SL_BOOLEAN_TRUE};
	SLEngineItf lengine = (*EngineObject);

	SLresult lresult = (*lengine)->CreateAudioPlayer(lengine,&_playerObject,src->getAudioSource(),laudioSink,3,ids,req);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create audio player");

	 lresult = (*_playerObject)->Realize(_playerObject,SL_BOOLEAN_FALSE);
	 if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't realize audio player");

	lresult = (*_playerObject)->GetInterface(_playerObject,SL_IID_PLAY,&_playerPlay);
	if(lresult != SL_RESULT_SUCCESS)
		ERROR("can't create audio player");



}


AudioPlayer::~AudioPlayer(void)
{
}
