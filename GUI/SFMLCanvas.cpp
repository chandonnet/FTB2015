#include "SFMLCanvas.h"


SFMLCanvas::SFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, unsigned int FrameTime) : 
	QWidget(parent),
	isInitialized(false)
{

	//Autoriser le rendu direct dans la widget
	this->setAttribute(Qt::WA_PaintOnScreen);
	this->setAttribute(Qt::WA_OpaquePaintEvent);
	this->setAttribute(Qt::WA_NoSystemBackground);

	//Changement de police pour autoriser le widget à capter les évènements clavier
	this->setFocusPolicy(Qt::StrongFocus);

	//Définition de la position/taille du widget
	this->move(position);
	this->resize(size);

	this->timer.setInterval(FrameTime);
}


SFMLCanvas::~SFMLCanvas(void)
{
}

#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif
void SFMLCanvas::showEvent(QShowEvent*)
{
	if (!isInitialized)
	{
		 #ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif

		// On crée la fenêtre SFML avec l'identificateur du widget
        RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));

		OnInit();

		//On paramètre le timer de sorte qu'il genère un rafraichissement
		connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));
		timer.start();

		isInitialized = true;
	}
}

QPaintEngine* SFMLCanvas::paintEngine() const
{
	//Cette fonction retourne une valeur nulle 
	//pour s'assurer que Qt n'utilisera pas ses moteurs de rendu
    return 0;
}

void SFMLCanvas::paintEvent(QPaintEvent*)
{
    OnUpdate();
    display();
}
void SFMLCanvas::OnInit() {}
void SFMLCanvas::OnUpdate() {}
