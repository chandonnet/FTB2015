#pragma once
#include "SFMLCanvas.h"
#include <SFML\Graphics.hpp>

class SFMLWindow : public SFMLCanvas
{
public:
public :
	SFMLWindow(QWidget* Parent, const QPoint& Position, const QSize& Size);
	SFMLWindow::~SFMLWindow(void);
	void OnInit();
	void OnUpdate();

	void SetSpec(float* specs);
	void SetSampleSize(int newSize);

	void SetJumpersColor(int r, int g, int b);
	void SetSoundBarsColor(int r, int g, int b);
	void SetBackGroundColor(int r, int g, int b);

private :
	sf::Clock clock;
	sf::RectangleShape* soundBars;
	sf::RectangleShape* jumpers;

	sf::Color bgColor;
	sf::Color soundBarsColor;
	sf::Color jumpersColor;

	float* visualiserSpec;
	int sampleSize;

	void SetJumpersPosition(sf::RectangleShape &jumper, sf::RectangleShape &soundBar);
	sf::RectangleShape CreateSoundBar(int index);
	sf::RectangleShape CreateJumper(int index, sf::RectangleShape &soundBar);
};

