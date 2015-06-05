#include "Playlist.h"


Playlist::Playlist(string name, string path)
{
	this->name = name;
	this->path = path;
}

Playlist::Playlist(string path)
{
	int posSlash = path.find_last_of("//");
	int length = path.find_last_of(".") - posSlash;
	this->name = path.substr(posSlash + 1, length - 1);
	InitPath(path);
}


Playlist::~Playlist()
{
	if(!this->playlist.empty())
	{
		vector<SoundInfo*>::iterator it;

		for (it = this->playlist.begin() ; it < this->playlist.end(); it++)
		{
			delete *it;
		}

		this->playlist.clear();
	}
}

void Playlist::InitPath(string path)
{
	string intruder = "file:";
	if(!path.find(intruder))
	{
		this->path = path.substr(8, path.length());
	}
	else
	{
		this->path = path;
	}
}

void Playlist::AddSong(string path)
{
	playlist.emplace_back(new SoundInfo(path));
}

void Playlist::RemoveSong(int r)
{

	delete playlist.at(r);
	playlist.erase(playlist.begin() + r);
}

void Playlist::SavePlayList()
{
	ofstream myfile;
	if(path.find(".m3u") != -1)
	{
		myfile.open(path);
	}
	else
	{
		myfile.open(path + "/" + name + ".m3u");
	}
	for(vector<SoundInfo*>::iterator it = playlist.begin(); it != playlist.end(); it++)
	{
		myfile << (*it)->GetPath() << endl;
	}
	myfile.close();
}

void Playlist::SetName(string name)
{
	this->name	= name;
}

void Playlist::SetPath(string path)
{
	this->path = path;
}

string Playlist::GetPath()
{
	return path;
}

void Playlist::Load()
{
	WIN32_FIND_DATA file;
	HANDLE search_handle = FindFirstFile(path.c_str(), &file);

	if (search_handle != INVALID_HANDLE_VALUE)
	{
		std::ifstream file(path.c_str());
		std::string str;
		while (std::getline(file, str))
		{
			playlist.emplace_back(new SoundInfo(str));
		}
	}
}

vector<SoundInfo*>& Playlist::GetPlayList()
{
	return playlist;
}

string Playlist::GetName()
{
	return name;
}