#include "SFMLWindow.h"


SFMLWindow::SFMLWindow(QWidget* parent, const QPoint& position, const QSize& size):
	SFMLCanvas(parent, position, size)
{
	sampleSize = 185;

	bgColor = sf::Color::Black;
	soundBarsColor = sf::Color::Green;
	jumpersColor = sf::Color::Yellow;

	this->soundBars = new sf::RectangleShape[sampleSize];
	this->jumpers = new sf::RectangleShape[sampleSize];
}

SFMLWindow::~SFMLWindow(void)
{
	delete[] soundBars;
	delete[] jumpers;
}

void SFMLWindow::OnInit()
{
	this->setVerticalSyncEnabled(true);	

	for (int i = 0; i < sampleSize; i++)
	{
		soundBars[i] = CreateSoundBar(i);
		jumpers[i] = CreateJumper(i, soundBars[i]);
	}

	clock.restart();
}

void SFMLWindow::OnUpdate()
{
	clear(bgColor);

	sf::Vector2f newSoundSize;

	int initialY = 5;
	int potentialNewY;

	for (int i = 0; i < sampleSize; i++)
	{
		newSoundSize.x = soundBars[i].getSize().x;
		potentialNewY = initialY + (this->getSize().y - 25) * visualiserSpec[i];

		if (potentialNewY >= soundBars[i].getSize().y)
		{
			newSoundSize.y = potentialNewY;
		}
		else
		{
			newSoundSize.y = soundBars[i].getSize().y - 10;
		}

		soundBars[i].setSize(newSoundSize);
		soundBars[i].setPosition(soundBars[i].getPosition().x, this->size().rheight() - soundBars[i].getSize().y);

		SetJumpersPosition(jumpers[i], soundBars[i]);

		draw(soundBars[i]);
		draw(jumpers[i]);
	}

	clock.restart();
}

sf::RectangleShape SFMLWindow::CreateJumper(int index, sf::RectangleShape &soundBar)
{
	sf::RectangleShape newJumper;

	newJumper.setSize(sf::Vector2f(this->size().rwidth()/sampleSize, 4));
	newJumper.setFillColor(jumpersColor);
	newJumper.setOutlineThickness(1);
	newJumper.setOutlineColor(sf::Color::Black);
	newJumper.setPosition((index)*(soundBar.getSize().x +1), this->size().rheight() - soundBar.getSize().y);

	return newJumper;
}

sf::RectangleShape SFMLWindow::CreateSoundBar(int index)
{
	sf::RectangleShape soundB;

	soundB.setSize(sf::Vector2f(this->size().rwidth()/sampleSize, 5));
	soundB.setFillColor(soundBarsColor);
	soundB.setOutlineThickness(1);
	soundB.setOutlineColor(sf::Color::Black);
	soundB.setPosition((index)*(soundB.getSize().x +1), this->size().rheight() - soundB.getSize().y);

	return soundB;
}

void SFMLWindow::SetJumpersPosition(sf::RectangleShape &jumper, sf::RectangleShape &soundBar)
{
	if (soundBar.getPosition().y <= jumper.getPosition().y)
	{
		jumper.setPosition(soundBar.getPosition());
	}
	else
	{
		jumper.setPosition(jumper.getPosition().x, jumper.getPosition().y + 5);
	}
}

void SFMLWindow::SetSpec(float* specs)
{
	this->visualiserSpec = specs;
}

void SFMLWindow::SetSampleSize(int newSize)
{
	clear(bgColor);

	this->sampleSize = newSize;

	sf::RectangleShape* newSoundBars = new sf::RectangleShape[sampleSize];
	sf::RectangleShape* newJumpers = new sf::RectangleShape[sampleSize];

	for (int i = 0; i < sampleSize; i++)
	{
		newSoundBars[i] = CreateSoundBar(i);
		newJumpers[i] = CreateJumper(i, newSoundBars[i]);

		draw(newSoundBars[i]);
		draw(newJumpers[i]);
	}

	display();

	delete[] soundBars;
	delete[] jumpers;

	soundBars = newSoundBars;
	jumpers = newJumpers;

}

void SFMLWindow::SetJumpersColor(int r, int g, int b)
{
	jumpersColor = sf::Color(r,g,b);

	for (int i = 0; i < sampleSize; i++)
	{
		jumpers[i].setFillColor(jumpersColor);
	}
}
void SFMLWindow::SetSoundBarsColor(int r, int g, int b)
{
	soundBarsColor = sf::Color(r,g,b);

	for (int i = 0; i < sampleSize; i++)
	{
		soundBars[i].setFillColor(soundBarsColor);
	}
}
void SFMLWindow::SetBackGroundColor(int r, int g, int b)
{
	bgColor = sf::Color(r,g,b);
}
