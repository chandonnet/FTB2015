#pragma once
#include "string"
//#include <id3\tag.h>
#pragma comment(lib, "id3lib.lib")

using namespace std;
class SoundInfo
{
public:
	SoundInfo(string path);
	~SoundInfo();
	//void Init();
	void InitTag();

	string GetTitle();
	string GetAlbum();
	string GetArtist();
	string GetPath();

private:
	string filePath;
	string title;
	string artist;
	string album;
};

