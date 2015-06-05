#include "Shortcut.h"


Shortcut::Shortcut(const QKeySequence key, QWidget *parent) :
	QShortcut(key, parent)
{
	this->setContext(Qt::ApplicationShortcut);	
}

Shortcut::~Shortcut(void)
{
}

void Shortcut::SetAssociatedButton(KeyboardButton* button)
{
	associatedButton = button;
}

KeyboardButton* Shortcut::GetAssociatedButton()
{
	return associatedButton;
}


