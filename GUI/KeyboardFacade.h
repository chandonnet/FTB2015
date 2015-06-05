#pragma once
#include <qlayout.h>
#include "Shortcut.h"
#include "KeyboardButton.h"
#include <qlabel.h>

class KeyboardFacade: public QVBoxLayout
{
public:
	KeyboardFacade(QWidget* parent);
	~KeyboardFacade(void);

	KeyboardButton* GetButton();
	Shortcut* GetShortcut();
	QLabel* GetLabel();

private:
	KeyboardButton* button;
	Shortcut* shortcut;
	QLabel* label;
};

