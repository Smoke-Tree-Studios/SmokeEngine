#include "Utility\ObjectWavefrontLoader.h"


ObjectWavefrontLoader::ObjectWavefrontLoader(SceneNode * sceneNode, std::string filename)
{
	cv::FileStorage lfile(filename,cv::FileStorage::READ);

	if(!lfile.isOpened())
	{
	
	}


	cv::FileNodeIterator literator = lfile["strings"].begin();
	cv::FileNodeIterator literator_end = lfile["strings"].end(); 
	while(literator != literator_end)
	{
		std::string lline = *literator;
		literator++;
	}

}


ObjectWavefrontLoader::~ObjectWavefrontLoader(void)
{
}
