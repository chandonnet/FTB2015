#pragma once
#include <string>
#include "fmod.hpp"
#include "fmod_errors.h"
#include <iostream>

using namespace std;

class CustomSound
{
public:
	CustomSound(std::string path, FMOD::System* FMODsys, bool sfx);
	~CustomSound(void);

	void Play();
	void Load();

	FMOD::Sound* GetSound();
	
	FMOD::Channel* channel;

private:
	
	FMOD::Sound* sound;
	FMOD::System* system;
	std::string path;
	bool sfx;
};

