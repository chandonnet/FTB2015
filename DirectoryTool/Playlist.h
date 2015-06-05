#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
#include "..\Visualizer\SoundInfo.h"


using namespace std;

class Playlist
{
public:
	Playlist(string name, string path);
	Playlist(string path);
	~Playlist();
	vector<SoundInfo*>& GetPlayList();
	void AddSong(string path);
	void RemoveSong(int r);
	void SavePlayList();
	void SetName(string path);
	void SetPath(string name);
	string GetName();
	string GetPath();
	void Load();
	void InitPath(string path);
private:
	vector<SoundInfo*> playlist;
	string name;
	string path;
};

