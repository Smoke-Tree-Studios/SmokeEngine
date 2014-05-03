#include "Utility\WaveFrontLoad.h"
#include <android\asset_manager.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android\log.h>
#include "Utility\Vector\Vector3.h"
#include "Utility\Vector\Vector2.h"
#include <stdlib.h>
#include <vector>
#include "VertexObject\VertexArrayObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
//#include <sstream>
#include <string>
#include <boost\algorithm\string.hpp>
#include "S_Debug.h"

std::vector<float> WaveFrontLoad::_splitFloat(std::string str,std::string character)
{
	
	std::vector<float> lfinal = std::vector<float>();
	std::vector<std::string> lstr = std::vector<std::string>();

	boost::split(lstr,str,boost::is_any_of(character.c_str()));

	for(int x = 0; x < lstr.size(); x++)
	{
		if(lstr[x] != "")
		{
			lfinal.push_back((float)atof(lstr[x].c_str()));
		}
	}

	return lfinal;

}

std::vector<int> WaveFrontLoad::_splitInt(std::string str,std::string character)
{
	std::vector<int> lfinal = std::vector<int>();
	std::vector<std::string> lstr = std::vector<std::string>();

	boost::split(lstr,str,boost::is_any_of(character.c_str()));

	
	for(int x = 0; x < lstr.size(); x++)
	{
		if(lstr[x] != "")
		{
			lfinal.push_back(atoi(lstr[x].c_str())-1);
		}
		else
		{
			lfinal.push_back(-1);
		}
	}
	/*std::ostringstream os ;
	for(int x = 0; x < lfinal.size(); x++)
	{
		 os << lfinal[x] << ",";
	}
	INFO(os.str().c_str());
	int s = lfinal.size();*/
	
	return lfinal;
}

VertexArrayObject* WaveFrontLoad::Load(const char* file,AAssetManager* assetManager, VertexBufferObjectWithSubData * vertexBufferObjectWithSubData)
{
	std::vector<GLushort> lindecies = std::vector<GLushort>();
	std::vector<Vector3> lverticies = std::vector<Vector3>();
	std::vector<Vector2> ltexCoords = std::vector<Vector2>();
	std::vector<Vector3> lvertexNormals = std::vector<Vector3>();

	Vector3 *lfinalVerts = NULL;
	Vector2 *lfinalTexCoords = NULL;
	Vector3 *lfinalNormals = NULL;

	AAsset* lasset = AAssetManager_open(assetManager,file,AASSET_MODE_UNKNOWN);

	if(NULL == lasset)
	{
		 __android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE",(char*)("Failed to open: " + std::string(file)).c_str());
	}
	

	long lsize = AAsset_getLength(lasset);

	char* lbuffer = (char*) (char*)calloc(lsize +1, sizeof(char));
	lbuffer[lsize] = 0;
	AAsset_read(lasset,lbuffer,lsize);

	int index = 0;
	while(index  < lsize)
	{
		std::string lfinal = "";
		while(index  < lsize)
		{
			lfinal += lbuffer[index];
			index++;
			if(lbuffer[index] == '\n')
			{
				index++;
				break;
			}
		}
	
		//verticies
		if(lfinal[0] == 'v' && lfinal[1] == ' ')
		{
			std::vector<float> f = _splitFloat(lfinal.substr(2)," ");
			lverticies.push_back(Vector3(f[0],f[1],f[2]));
		}
		//vertex normal
		if(lfinal[0] == 'v' && lfinal[1] == 'n')
		{
			std::vector<float> f = _splitFloat(lfinal.substr(2)," ");
			lvertexNormals.push_back(Vector3(f[0],f[1],f[2]));
		}
		//texture coordinates
		if(lfinal[0] == 'v' && lfinal[1] == 't')
		{
			std::vector<float> f = _splitFloat(lfinal.substr(2)," ");
			ltexCoords.push_back(Vector2(f[0],f[1]));
		}
		//fragment faces
		if(lfinal[0] == 'f' && lfinal[1] == ' ')
		{

			std::vector<int> f = _splitInt(lfinal.substr(2), "/ ");
			if(lfinalVerts == NULL)
				lfinalVerts =  new Vector3[lverticies.size()];

			//vertex/texture-coords
			if(f.size() == 6)
			{
				if(lfinalTexCoords == NULL)
					lfinalTexCoords =  new Vector2[lverticies.size()];
				

				//pass in verticies
				lfinalVerts[f[0]] = lverticies[f[0]];
				lfinalVerts[f[2]] = lverticies[f[2]];
				lfinalVerts[f[4]] = lverticies[f[4]];
				
				//tex-coords
				lfinalTexCoords[f[0]] = ltexCoords[f[1]];
				lfinalTexCoords[f[2]] = ltexCoords[f[3]];
				lfinalTexCoords[f[4]] = ltexCoords[f[5]];

				lindecies.push_back(f[0]);
				lindecies.push_back(f[2]);
				lindecies.push_back(f[4]);
			}
			//vertex/normal
			else if(f[1] == -1)
			{
				if(lfinalNormals == NULL)
					lfinalNormals=new Vector3[lverticies.size()];
				
				lindecies.push_back(f[0]);
				lindecies.push_back(f[3]);
				lindecies.push_back(f[6]);

				//pass in verticies
				lfinalVerts[f[0]] = lverticies[f[0]];
				lfinalVerts[f[3]] = lverticies[f[3]];
				lfinalVerts[f[6]] = lverticies[f[6]];
				
				//pass in vertex normals
				lfinalNormals[f[0]] = lvertexNormals[f[2]];
				lfinalNormals[f[3]] = lvertexNormals[f[5]];
				lfinalNormals[f[6]] = lvertexNormals[f[8]];
				
			}
			else
			{

				if(lfinalTexCoords == NULL)
					lfinalTexCoords= new Vector2[lverticies.size()];
				if(lfinalNormals == NULL)
					lfinalNormals= new Vector3[lverticies.size()];
				

				//pass in verticies
				lfinalVerts[f[0]] = lverticies[f[0]];
				lfinalVerts[f[3]] = lverticies[f[3]];
				lfinalVerts[f[6]] = lverticies[f[6]];
				
				//pass in vertex normals
				lfinalNormals[f[0]] = lvertexNormals[f[2]];
				lfinalNormals[f[3]] = lvertexNormals[f[5]];
				lfinalNormals[f[6]] = lvertexNormals[f[8]];

				//pass in texCoords
				lfinalTexCoords[f[8]] = ltexCoords[f[1]];
				lfinalTexCoords[f[3]] = ltexCoords[f[4]];
				lfinalTexCoords[f[6]] = ltexCoords[f[7]];

				lindecies.push_back(f[0]);
				lindecies.push_back(f[3]);
				lindecies.push_back(f[6]);
			}
		}
	}
 
	vertexBufferObjectWithSubData->AddSubData(new VertexBufferObjectWithSubData::SubData(lfinalVerts,lverticies.size(),VERTEX));
	delete[] lfinalVerts;

	if(lfinalNormals != NULL)
	{
		vertexBufferObjectWithSubData->AddSubData(new VertexBufferObjectWithSubData::SubData(lfinalNormals,lverticies.size(),NORMALS));
		delete[] lfinalNormals;
	}
	if(lfinalTexCoords != NULL)
	{
		vertexBufferObjectWithSubData->AddSubData(new VertexBufferObjectWithSubData::SubData(lfinalTexCoords,lverticies.size(),TEX_COORDS));
		delete[] lfinalTexCoords;
	}

	free(lbuffer);
	GLushort* lind = &lindecies[0];
	return new VertexArrayObject(lind,lindecies.size());

	
}