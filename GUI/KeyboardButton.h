#pragma once
#include <qpushbutton.h>
#include "../Visualizer/CustomSound.h"
#include "../Visualizer/MediaSystem.h"
#include <qlabel.h>
#include <qtimer.h>

class KeyboardButton: public QPushButton
{
public:
	KeyboardButton(void);
	KeyboardButton::KeyboardButton(std::string path, MediaSystem &sys);

	~KeyboardButton(void);

	void SetSound(std::string path, MediaSystem &sys);
	void Play(MediaSystem &sys);
	void SetAssociatedLabel(QLabel* lbl);
	QLabel* GetAssociatedLabel();
	CustomSound* GetSound();


private:
	CustomSound* currentSound;
	QLabel* associatedLabel;
};

