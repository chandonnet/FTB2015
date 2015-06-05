#pragma once
#include "MediaSystem.h"

class Visualizer
{
public:
	Visualizer(FMOD::System &FMODsys);
	~Visualizer(void);

private:
	FMOD::System *system;
	FMOD_RESULT visResult;

	FMOD::Sound *visualizerSound;
	FMOD::Channel *visualizerSoundChannel;
};

