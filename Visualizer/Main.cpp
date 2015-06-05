#include "MediaSystem.h"
#include <iostream>
//#include <vld.h>
#include <SFML\Graphics.hpp>

int main()
{

	MediaSystem player;
	//player.CreateChannel();
	//player.CreateChannel();
	//player.CreateChannel();

	//player.LoadSound("homers_scream.mp3");
	//player.LoadSound("jaguar.wav");
	//player.LoadSound("BABYCRY2.mp3");


	//player.PlaySound(player.soundList[0], player.channelList[0]);
	//player.PlaySound(player.soundList[1], player.channelList[1]);
	//player.PlaySound(player.soundList[2], player.channelList[2]);


	player.LoadVisualiser("bt2.mp3");

	system("pause");
}
