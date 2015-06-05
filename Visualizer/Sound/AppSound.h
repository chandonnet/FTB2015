#pragma once
#include <string>
#include "fmod.hpp"
#include "fmod_errors.h"


	class AppSound 
	{
	public:
		AppSound(std::string path, std::string name);
		~AppSound();

		std::string GetPath();
		std::string GetName();
		FMOD::Sound* GetSound();
	private:
		std::string path;
		std::string name;
		FMOD::Sound* sound;
	};


