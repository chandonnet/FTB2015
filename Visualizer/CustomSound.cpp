#include "CustomSound.h"


CustomSound::CustomSound(std::string path, FMOD::System* FMODsys, bool sfx)
{
	system = FMODsys;

	this->path = path;
	this->sfx = sfx;

	Load();
}

CustomSound::~CustomSound(void)
{
	if(!this->sfx)
	{
		this->sound->release();
	}
}

void CustomSound::Load()
{
	FMOD_RESULT result;
	result = system->createSound(path.c_str(), FMOD_SOFTWARE | FMOD_CREATECOMPRESSEDSAMPLE, 0, &sound);

	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (%d) %s\n" << result;
		exit(-1);
	}
}

void CustomSound::Play()
{
	system->playSound(FMOD_CHANNEL_FREE, sound, false, &this->channel);
}

FMOD::Sound* CustomSound::GetSound()
{
	return this->sound;
}


