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
#include <string>
#include <boost\algorithm\string.hpp>

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
			lfinal.push_back(atoi(lstr[x].c_str()));
		}
		else
		{
			lfinal.push_back(-1);
		}
	}
	int s = lfinal.size();
	
	return lfinal;
}

VertexArrayObject* WaveFrontLoad::Load(const char* file,AAssetManager* assetManager, VertexBufferObjectWithSubData * vertexBufferObjectWithSubData)
{
	std::vector<GLushort> lindecies = std::vector<GLushort>();
	std::vector<Vector3> lverticies = std::vector<Vector3>();
	std::vector<Vector2> ltexCoords = std::vector<Vector2>();
	std::vector<Vector3> lvertexNormals = std::vector<Vector3>();

	float *lfinalVerts = NULL;
	float *lfinalTexCoords = NULL;
	float *lfinalNormals = NULL;

	AAsset* lasset = AAssetManager_open(assetManager,file,AASSET_MODE_UNKNOWN);

	if(NULL == lasset)
	{
		 __android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE",(char*)("Failed to open: " + std::string(file)).c_str());
	}
	

	long lsize = AAsset_getLength(lasset);

	char* lbuffer = (char*) malloc(sizeof(char)*lsize);
	AAsset_read(lasset,lbuffer,lsize);

	int index = 0;
	while(index  <= lsize)
	{
		std::string lfinal = "";
		while(index  <= lsize)
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
			std::string lstr[] = {" "};
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
			{
				lfinalVerts = (float*) malloc(sizeof(float)*lverticies.size() * 3);
				lfinalTexCoords= (float*) malloc(sizeof(float)*lverticies.size() * 2);
				lfinalNormals= (float*) malloc(sizeof(float)*lverticies.size() * 3);
			}

			//vertex/texture-coords
			if(f.size() == 6)
			{
				//pass in verticies
				lfinalVerts[f[0]*3 + 0] = lverticies[f[0]].X;
				lfinalVerts[f[0]*3 + 1] = lverticies[f[0]].Y;
				lfinalVerts[f[0]*3 + 2] = lverticies[f[0]].Z;

				lfinalVerts[f[2]*3 + 0] = lverticies[f[2]].X;
				lfinalVerts[f[2]*3 + 1] = lverticies[f[2]].Y;
				lfinalVerts[f[2]*3 + 2] = lverticies[f[2]].Z;

				lfinalVerts[f[4]*3 + 0] = lverticies[f[4]].X;
				lfinalVerts[f[4]*3 + 1] = lverticies[f[4]].Y;
				lfinalVerts[f[4]*3 + 2] = lverticies[f[4]].Z;


				lindecies.push_back(f[0]);
				lindecies.push_back(f[2]);
				lindecies.push_back(f[4]);
			}
			//vertex/normal
			else if(f[1] == -1)
			{
				//pass in verticies
				lfinalVerts[f[0]*3 + 0] = lverticies[f[0]].X;
				lfinalVerts[f[0]*3 + 1] = lverticies[f[0]].Y;
				lfinalVerts[f[0]*3 + 2] = lverticies[f[0]].Z;

				lfinalVerts[f[3]*3 + 0] = lverticies[f[3]].X;
				lfinalVerts[f[3]*3 + 1] = lverticies[f[3]].Y;
				lfinalVerts[f[3]*3 + 2] = lverticies[f[3]].Z;

				lfinalVerts[f[6]*3 + 0] = lverticies[f[6]].X;
				lfinalVerts[f[6]*3 + 1] = lverticies[f[6]].Y;
				lfinalVerts[f[6]*3 + 2] = lverticies[f[6]].Z;
				
				//pass in vertex normals
				lfinalNormals[f[2]*3+0] = lvertexNormals[f[2]].X;
				lfinalNormals[f[2]*3+1] = lvertexNormals[f[2]].Y;
				lfinalNormals[f[2]*3+2] = lvertexNormals[f[2]].Z;

				lfinalNormals[f[5]*3+0] = lvertexNormals[f[5]].X;
				lfinalNormals[f[5]*3+1] = lvertexNormals[f[5]].Y;
				lfinalNormals[f[5]*3+2] = lvertexNormals[f[5]].Z;

				lfinalNormals[f[8]*3+0] = lvertexNormals[f[8]].X;
				lfinalNormals[f[8]*3+1] = lvertexNormals[f[8]].Y;
				lfinalNormals[f[8]*3+2] = lvertexNormals[f[8]].Z;

				lindecies.push_back(f[0]);
				lindecies.push_back(f[3]);
				lindecies.push_back(f[6]);
			}
			else
			{
				//pass in verticies
				lfinalVerts[f[0]*3 + 0] = lverticies[f[0]].X;
				lfinalVerts[f[0]*3 + 1] = lverticies[f[0]].Y;
				lfinalVerts[f[0]*3 + 2] = lverticies[f[0]].Z;

				lfinalVerts[f[3]*3 + 0] = lverticies[f[3]].X;
				lfinalVerts[f[3]*3 + 1] = lverticies[f[3]].Y;
				lfinalVerts[f[3]*3 + 2] = lverticies[f[3]].Z;

				lfinalVerts[f[6]*3 + 0] = lverticies[f[6]].X;
				lfinalVerts[f[6]*3 + 1] = lverticies[f[6]].Y;
				lfinalVerts[f[6]*3 + 2] = lverticies[f[6]].Z;
				
				//pass in vertex normals
				lfinalNormals[f[2]*3+0] = lvertexNormals[f[2]].X;
				lfinalNormals[f[2]*3+1] = lvertexNormals[f[2]].Y;
				lfinalNormals[f[2]*3+2] = lvertexNormals[f[2]].Z;

				lfinalNormals[f[5]*3+0] = lvertexNormals[f[5]].X;
				lfinalNormals[f[5]*3+1] = lvertexNormals[f[5]].Y;
				lfinalNormals[f[5]*3+2] = lvertexNormals[f[5]].Z;

				lfinalNormals[f[8]*3+0] = lvertexNormals[f[8]].X;
				lfinalNormals[f[8]*3+1] = lvertexNormals[f[8]].Y;
				lfinalNormals[f[8]*3+2] = lvertexNormals[f[8]].Z;

				//pass in texCoords
				lfinalTexCoords[f[1]*3+0] = lvertexNormals[f[1]].X;
				lfinalTexCoords[f[1]*3+1] = lvertexNormals[f[1]].Y;
				lfinalTexCoords[f[1]*3+2] = lvertexNormals[f[1]].Z;

				lfinalTexCoords[f[4]*3+0] = lvertexNormals[f[4]].X;
				lfinalTexCoords[f[4]*3+1] = lvertexNormals[f[4]].Y;
				lfinalTexCoords[f[4]*3+2] = lvertexNormals[f[4]].Z;

				lfinalTexCoords[f[7]*3+0] = lvertexNormals[f[7]].X;
				lfinalTexCoords[f[7]*3+1] = lvertexNormals[f[7]].Y;
				lfinalTexCoords[f[7]*3+2] = lvertexNormals[f[7]].Z;

				lindecies.push_back(f[0]);
				lindecies.push_back(f[3]);
				lindecies.push_back(f[6]);
			}
		}
	}

	vertexBufferObjectWithSubData->AddSubData(new VertexBufferObjectWithSubData::SubData(lfinalVerts,lverticies.size(),3,VERTEX));

	if(lfinalNormals != NULL)
	{
		vertexBufferObjectWithSubData->AddSubData(new VertexBufferObjectWithSubData::SubData(lfinalNormals,lverticies.size(),3,NORMALS));
	}
	if(lfinalTexCoords != NULL)
	{
		vertexBufferObjectWithSubData->AddSubData(new VertexBufferObjectWithSubData::SubData(lfinalTexCoords,lverticies.size(),2,TEX_COORDS));
	}

	free(lbuffer);
	free(lfinalVerts);
	free(lfinalTexCoords);
	free(lfinalNormals);

	GLushort* lind = &lindecies[0];
	return new VertexArrayObject(lind,lindecies.size());

	
}