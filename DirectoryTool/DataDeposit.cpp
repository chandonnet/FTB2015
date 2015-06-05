#include "DataDeposit.h"

const std::string DataDeposit::CONFIG_PATH = "configPath.xml";


DataDeposit::DataDeposit(void)
{
	toDelete = false;
}

DataDeposit::~DataDeposit(void)
{
	if (toDelete)
	{
		delete directory;
	}
}

vector<Playlist*> DataDeposit::LoadCollection()
{
	setlocale(LC_ALL,"");
	pugi::xml_document collectionFile;
	pugi::xml_parse_result resultCollection = collectionFile.load_file(CONFIG_PATH.c_str());
	pugi::xml_node collectionNode = collectionFile.child("Config").child("Playlists");

	if(resultCollection != NULL){

		for (pugi::xml_node point = collectionNode.child("PlaylistPath"); point != nullptr; point = point.next_sibling("PlaylistPath"))
		{
			pugi::xml_attribute path = point.first_attribute();
			Playlist* newPlaylist = new Playlist(path.as_string());
			newPlaylist->Load();
			playlists.emplace_back(newPlaylist);
		}
	}
	return playlists;
}

Playlist* DataDeposit::LoadDirectory()
{
	setlocale(LC_ALL,"");
	pugi::xml_document directoryFile;
	pugi::xml_parse_result resultDirectory = directoryFile.load_file(CONFIG_PATH.c_str());;

	if(resultDirectory != NULL)
	{
		pugi::xml_attribute path = directoryFile.child("Config").child("DirectoryPath").first_attribute();
		directoryPath = path.as_string();
	}
	if(directoryPath == "")
	{
		directoryPath = "directory.m3u";
	}
	directory = new Playlist("directory", directoryPath);
	directory->Load();
	bool toDelete = true;

	return directory;
}

void DataDeposit::SaveConfig(Playlist* directory, vector<Playlist*> playlists)
{
	directory->SavePlayList();
	setlocale(LC_ALL,"");
	pugi::xml_document configFile;
	pugi::xml_node configNode = configFile.append_child("Config");
	pugi::xml_node dirPath = configNode.append_child("DirectoryPath");
	pugi::xml_attribute path = dirPath.append_attribute(directory->GetPath().c_str());
	path.set_value(directory->GetPath().c_str());

	pugi::xml_node allPlaylists = configNode.append_child("Playlists");


	for(vector<Playlist*>::iterator it = playlists.begin(); it != playlists.end(); it++)
	{
		pugi::xml_node playlist = allPlaylists.append_child("PlaylistPath");
		pugi::xml_attribute path = playlist.append_attribute("path");
		path.set_value((*it)->GetPath().c_str());
	}

	configFile.save_file(CONFIG_PATH.c_str());
}

