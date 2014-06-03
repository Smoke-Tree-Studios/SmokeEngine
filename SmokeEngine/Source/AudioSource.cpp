#include "Audio/AudioSource.h"
#include <android\asset_manager.h>
#include <android\asset_manager_jni.h>
#include <sys/types.h>
#include "S_Debug.h"
AudioSource::AudioSource(void* data)
{
}
AudioSource::AudioSource(const char* fileLocation,AAssetManager* assetManager)
{
	
	AAsset* lasset = AAssetManager_open(assetManager,fileLocation,AASSET_MODE_UNKNOWN);

	if(NULL == lasset)
		ERROR("failed to open: %s",fileLocation);

	
	off_t lstart,llength;
	int lfd = AAsset_openFileDescriptor(lasset,&lstart,&llength);

	_formatMime = new SLDataFormat_MIME();
	_formatMime->formatType = SL_DATAFORMAT_MIME;
	_formatMime->mimeType = NULL;
	_formatMime->containerType = SL_CONTAINERTYPE_UNSPECIFIED;

	_locFd = new SLDataLocator_AndroidFD();
	_locFd->locatorType = SL_DATAFORMAT_MIME;
	_locFd->fd = lfd;
	_locFd->offset = lstart;
	_locFd->length =llength;

	//SLDataLocator_AndroidFD lloc_fd = {SL_DATALOCATOR_ANDROIDFD,lfd,lstart,llength};
	//SLDataFormat_MIME lformat_mime = {SL_DATAFORMAT_MIME,NULL,SL_CONTAINERTYPE_UNSPECIFIED};

	_audioSource = new SLDataSource();
	_audioSource->pLocator = _locFd;
	_audioSource->pFormat =	_formatMime;

}

SLDataSource* AudioSource::getAudioSource()
{
	return _audioSource;
}


AudioSource::~AudioSource(void)
{
	delete(_audioSource);
	delete(_locFd);
	delete(_formatMime);
}
