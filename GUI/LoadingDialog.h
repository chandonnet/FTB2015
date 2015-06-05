#pragma once
#include <qprogressdialog.h>
#include <string>
#include <iostream>

using namespace std;


class LoadingDialog: public QProgressDialog
{
public:
	LoadingDialog(int size);
	~LoadingDialog(void);

	void Update( int it, string songName = "Chargement");
};

