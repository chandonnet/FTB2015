#include "MessageWindow.h"


MessageWindow::MessageWindow(std::string title, std::string message)
{
	this->setWindowTitle(title.c_str());
	this->setText(message.c_str());
	this->setDefaultButton(QMessageBox::Ok);
}


MessageWindow::~MessageWindow(void)
{
}

void MessageWindow::Execute()
{
	this->exec();
}