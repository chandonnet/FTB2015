#pragma once
#include <qshortcut.h>
#include "KeyboardButton.h"

class Shortcut: public QShortcut
{
public:
	Shortcut(const QKeySequence key, QWidget *parent);
	~Shortcut(void);

	KeyboardButton* GetAssociatedButton();
	void SetAssociatedButton(KeyboardButton* button);

private:
	KeyboardButton* associatedButton;
};

