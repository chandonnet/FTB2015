#include "gui.h"
//#include <vld.h>
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSplashScreen screen(QPixmap("..//Splash.png"));
	screen.show();
	GUI w;	
	w.setFixedSize(w.size());
	screen.finish(&w);
	w.show();

	w.ShowSFMLViews();

	return a.exec();
}
