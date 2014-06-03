#pragma once
#include "string"
#include "sles\OpenSLES.h"
#include "sles\OpenSLES_Android.h"
class AudioManager
{
private:

	//engine interface
	SLObjectItf _engineObject;
	SLEngineItf _mainEngine;

	//output mix interface
	SLObjectItf _outputMixerObject;
	SLEnvironmentalReverbItf _outputMixEnviromentReverb;

public:

	AudioManager(void);
	~AudioManager(void);
};

