#pragma once
#include <qfiledialog.h>
#include <list>
#include <thread>
#include <qtablewidget.h>
#include "GeneratedFiles\ui_gui.h"
#include "KeyboardButton.h"
#include "LoadingDialog.h"
#include "KeyboardButton.h"
#include "MessageWindow.h"
#include "..\DirectoryTool\Playlist.h"
#include "..\Visualizer\MediaSystem.h"
#include "..\DirectoryTool\DataDeposit.h"

class InterfaceLogique
{
	/* Classe qui va contenir tout les "slots" et tout les action qui peuvent être faites par l'interface */
public:
	InterfaceLogique(Ui::mainWindow &ui);
	~InterfaceLogique(void);

	void Load();
	MediaSystem mySys;

	//**SLOT**//
	//Directory & PlayLists
	bool AddFilePlayList(QList<QUrl> urlList);
	bool AddFileDirectory(QList<QUrl> urlList);
	bool RemoveFilePlayList();
	bool SavePlayList(QString name,  QUrl url);
	bool AddCollectionToCurrent();
	bool AddCollection(QUrl url);
	bool RemoveCollection();
	bool ShowSelectedCollection(int r);
	bool AddSongToDirectory();
	bool RemoveSongFromDirectory();

	//Current
	bool AddSongToCurrentFromDirectory();
	bool RemoveSongFromCurrent();
	void EmptyCurrent();
	void CurrentListSecurity(int r);
	bool PutNext();
	bool UpSong();
	bool DownSong();
	bool ShuffleCurrent();

	//Keyboard
	string AddKeyboardSound(KeyboardButton* button, QUrl url);

	//Quickplay
	bool ChangeSong(bool next);
	bool PlayThread();

	//Equalizer
	void RemoveEffects();
	void SlidersToDefault();
	void AdjustVolume(QSlider* slider, QSlider* slider2);
	void SetSpeed();
	void SetEcho();
	void SetPitch();
	void SetFlange();
	void SetTremolo();
	void SetDistortion();

	bool GetIsPlaying();
	void SetIsPlaying(bool play);
	int GetCurrentLength();
	void SetCurrentLength(int length);
	void SetCurrentFrequency(float f);
	
private:
	Playlist* buildPList; // Playlist en construction (créer une playlist)
	list<SoundInfo*> currentList; //Liste de chansons actuellement en lecture / en attente
	vector<Playlist*> playlists; //Liste des collections présente dans l'application
	Playlist* directory; //Représentation de la bibliotèque de l'application
	Ui::mainWindow* myUI;
	DataDeposit dd;
	bool isPlaying;
	bool isPaused;
	int currentlength;
	float currentFrequency;

	void FindFile(QList<QUrl> urlList, vector<SoundInfo*>& list);
	void FindFile(QList<QUrl> urlList, Playlist& list);
	void FillTable(QTableWidget* table, std::list<SoundInfo*> list);
	void FillTable(QTableWidget* table, std::vector<SoundInfo*> list);
	void FillTable(QTableWidget* table, std::vector<Playlist*> list);
	void ClearTable(QTableWidget* table);
	void ColorTableLine(QTableWidget* table, int r, int nbCol, QColor color);
	bool ValidateUrls(QList<QUrl> urlList);
	bool ValidateUrl(QUrl url);
	bool SelectSong();
	void FillFromDirectory(int nb);
	bool FillFromCollection();
	void FillListFromVector(list<SoundInfo*>& cible, vector<SoundInfo*> source);

	void DeleteList();
	void RemoveSong(SoundInfo* toRemove);
	void RemoveCollectionMember(Playlist* toRemove);
	void ClearCurrentList();
	void ClearPlaylists();
	void Task();

	FMOD::DSP* DSPEcho;
	FMOD::DSP* DSPPitch;
	FMOD::DSP* DSPFlange;
	FMOD::DSP* DSPTremolo;
	FMOD::DSP* DSPDistortion;
};


