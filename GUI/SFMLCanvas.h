#pragma once
#include <QtWidgets/QMainWindow>
#include <qtimer.h>
#include <qwidget.h>
#include "GeneratedFiles\ui_gui.h"
#include <SFML\Graphics.hpp>

class SFMLCanvas: public QWidget, public sf::RenderWindow
{
public:
	SFMLCanvas(QWidget* parent, const QPoint& position, const QSize& size, unsigned int FrameTime = 3);
	virtual ~SFMLCanvas(void);

	virtual void OnInit();

	virtual void OnUpdate();

	virtual QPaintEngine* paintEngine() const;

	virtual void showEvent(QShowEvent*);

	virtual void paintEvent(QPaintEvent*);

private:
	QTimer timer;
	bool isInitialized;

};

