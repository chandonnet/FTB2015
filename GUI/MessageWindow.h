#pragma once
#include <qmessagebox.h>
#include <string>
class MessageWindow : public QMessageBox
{
public:
	MessageWindow(std::string title, std::string message);
	~MessageWindow(void);
	void Execute();
};

