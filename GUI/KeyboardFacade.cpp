#include "KeyboardFacade.h"


KeyboardFacade::KeyboardFacade(QWidget* parent)
{
	this->button = new KeyboardButton();
	this->shortcut = new Shortcut((Qt::Key_Q), parent);
	this->label = new QLabel("Bouton");

	label->setAlignment(Qt::AlignCenter);
	label->setText("(Vide)");

	button->SetAssociatedLabel(label);

	shortcut->SetAssociatedButton(button);

	this->addWidget(button);
	this->addWidget(label);
}


KeyboardFacade::~KeyboardFacade(void)
{
}

KeyboardButton* KeyboardFacade::GetButton()
{
	return this->button;
}
Shortcut* KeyboardFacade::GetShortcut()
{
	return this->shortcut;
}
QLabel* KeyboardFacade::GetLabel()
{
	return this->label;
}
