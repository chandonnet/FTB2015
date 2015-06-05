#include "KeyboardButton.h"

#define PRECISION 250


KeyboardButton::KeyboardButton(void)
{
	currentSound = NULL;
	this->setGeometry(200,200,200,200);
	this->show();
}

KeyboardButton::KeyboardButton(std::string path, MediaSystem &sys)
{
	currentSound = new CustomSound(path, sys.GetFmodSys(), true);	
}

KeyboardButton::~KeyboardButton(void)
{
	delete currentSound;
}

void KeyboardButton::SetSound(std::string path, MediaSystem &sys)
{
	if (currentSound != NULL)
	{
		currentSound->GetSound()->release();
		delete currentSound;
	}

	currentSound = new CustomSound(path, sys.GetFmodSys(), true);
}

void KeyboardButton::SetAssociatedLabel(QLabel* lbl)
{
	this->associatedLabel = lbl;
}

QLabel* KeyboardButton::GetAssociatedLabel()
{
	return this->associatedLabel;
}

void KeyboardButton::Play(MediaSystem &sys)
{
	if (this->currentSound != NULL)
	{
		currentSound->GetSound()->release();
		currentSound->Load();

		this->currentSound->Play();
		sys.AddChannelToMaster(currentSound->channel);
		currentSound->channel->setPaused(false);
	}	
}

CustomSound* KeyboardButton::GetSound()
{
	return this->currentSound;
}