#include "AppSound.h"


AppSound::AppSound(std::string path, std::string name)
{
	this->path = path;
	this->name = name;
}

AppSound::~AppSound()
{
	delete sound;
}

std::string AppSound::GetPath()
{
	return path;
}

std::string AppSound::GetName()
{
	return name;
}


FMOD::Sound* AppSound::GetSound()
{
	return sound;
}
