#include "MediaSystem.h"
#include <iostream>
#include <algorithm>

MediaSystem::MediaSystem()
{
	InitSpec();

	result = FMOD::System_Create(&FMODsys);
	FMODErrorCheck(result);
	FMODErrorCheck(result = FMODsys->init(100, FMOD_INIT_NORMAL, 0));

	FMODErrorCheck(this->FMODsys->createChannelGroup(NULL, &this->masterSound));
}


MediaSystem::~MediaSystem()
{
	delete[] spec;	

	FMODsys->release();
}

void  MediaSystem::PlayMusic(std::string path)
{
	CustomSound* s = new CustomSound(path, FMODsys, false);
	this->currentSound = s->GetSound();

	LoadVisualiser(path);
	delete s;
}

void MediaSystem::LoadVisualiser(std::string path)
{
	FMODErrorCheck(FMODsys->playSound(FMOD_CHANNEL_FREE, this->currentSound, true, &this->channel));

	FMODErrorCheck(this->channel->setChannelGroup(masterSound));

	this->channel->setPaused(false);

	this->change = false;
	bool isPlaying = true;
	bool paused = false;
	bool firstTime = true;
	float *specLeft;
	float *specRight;

	while(true)
	{
		if(this->channel->getPaused(&paused) == FMOD_OK && !paused)
		{
			FMODsys->update();	

			specLeft = new float[sampleSize];
			specRight = new float[sampleSize];

			this->masterSound->getSpectrum(specLeft, sampleSize, 0, FMOD_DSP_FFT_WINDOW_RECT);
			this->masterSound->getSpectrum(specRight, sampleSize, 1, FMOD_DSP_FFT_WINDOW_RECT);

			for (int i = 0; i < sampleSize; i++)
			{
				spec[i] = (specLeft[i] + specRight[i]) / 2;
			}

			/*Fréquence max*/
			auto maxIterator = std::max_element(&spec[0], &spec[sampleSize]);
			float maxVol = *maxIterator;

			// Normaliser
			if (maxVol != 0)
			{
				for (int i = 0; i < sampleSize; i++)
				{
					spec[i] = spec[i] / maxVol;
					std::cout << spec[i] << std::endl;
				}
			}
			delete[] specLeft;
			delete[] specRight;
		}

		if(change)
		{
			break;
		}
	}
	this->channel->stop();
	
}

void MediaSystem::SetSampleSize(int newSize)
{
	this->sampleSize = newSize;
	float* newSpec = new float[sampleSize];

	for (int i = 0; i < sampleSize; i++)
	{
		newSpec[i] = 0;
	}

	delete spec;
	spec = newSpec;
}

void MediaSystem::StopMusic()
{
	this->change = true;
}

FMOD::System* MediaSystem::GetFmodSys()
{
	return this->FMODsys;
}

void MediaSystem::AddChannelToMaster(FMOD::Channel* newChannel)
{
	newChannel->setChannelGroup(masterSound);
}

void MediaSystem::InitSpec()
{
	sampleSize = 256;
	spec = new float[sampleSize];

	for (int i = 0; i < sampleSize; i++)
	{
		spec[i] = 0;
	}
}

void MediaSystem::FMODErrorCheck(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        std::cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << std::endl;
        exit(-1);
    }
}