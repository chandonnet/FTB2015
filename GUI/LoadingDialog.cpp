#include "LoadingDialog.h"
#include "GeneratedFiles\ui_gui.h"

LoadingDialog::LoadingDialog(int size)
{
	this->setMinimumDuration(0);

	this->setLabelText("Chargement...");

	this->setValue(0);
	this->setMaximum(size);

	this->setCancelButton(0);

	this->setWindowModality(Qt::WindowModality::WindowModal);	
	this->setWindowFlags(Qt:: Dialog | Qt:: FramelessWindowHint | Qt:: WindowTitleHint | Qt:: CustomizeWindowHint);
}


LoadingDialog::~LoadingDialog(void)
{
}

void LoadingDialog::Update(int it, string songName)
{
	this->setValue(it);
	string text = songName + "... " + std::to_string(it) + "/" + std::to_string(this->maximum());
	this->setLabelText(QString::fromStdString(text));
	QCoreApplication::processEvents();
}