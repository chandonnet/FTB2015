#pragma once
#include "fmod.hpp"
#include "fmod_errors.h"
#include <vector>
#include <iostream>
#include <string>
#include "SoundInfo.h"
#include "CustomSound.h"

class MediaSystem
{
public:
	MediaSystem();
	~MediaSystem();

	void LoadVisualiser(std::string path);
	void PlayMusic(std::string path);
	void StopMusic();
	void SetSampleSize(int newSize);
	FMOD::System* GetFmodSys();
	void AddChannelToMaster(FMOD::Channel* newChannel);

	FMOD::Channel* channel;
	FMOD::Sound* currentSound;
	float *spec;
	
private:
	FMOD::System *FMODsys;
	FMOD_RESULT result;
	FMOD::ChannelGroup* masterSound;
	int sampleSize;
	bool change;

	void FMODErrorCheck(FMOD_RESULT result);

	void InitSpec();
};

