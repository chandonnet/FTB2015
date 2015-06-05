#ifndef GUI_H
#define GUI_H

#include "InterfaceLogique.h"
#include <qsplashscreen.h>
#include "SFMLWindow.h"
#include "MessageWindow.h"
#include "KeyboardFacade.h"
#include "GeneratedFiles\ui_gui.h"
#include <qcolordialog.h>
#include <QtWidgets/QMainWindow>

class GUI : public QMainWindow
{
	Q_OBJECT 

public:
	GUI(QWidget *parent = 0);
	~GUI();
	QSplashScreen qSplashScreen;
	Ui::mainWindow ui;
	InterfaceLogique* logic;
	void ShowSFMLViews();

private:
	void ConnectAll();
	void InitAll();
	void InitIcons();
	void InitKeyboard();

	QPixmap* icon;
	QTimer *timer;
	SFMLWindow* sfmlViewHome;
	SFMLWindow* sfmlViewVis;

	vector<KeyboardFacade*> keyboard;
	QString* keys;
	int nbKeys;

	void CheckValid(bool valid, string titleError, string messageError);
	void CheckValid(bool valid, string titleError, string messageError, string titleSuccess, string messageSuccess);
	void ClearKeyboard();
	void SetColumnWidth(QTableWidget* table, int nbRow);
	void SetColumnWidth(QTableWidget* table, int nbRow, int lastRowSize);

public slots:
	//Quickplay
	void sPlayMusic();
	void sSetVolume();
	void sSetTime();
	void sSetSongTime();
	void sChangeToPrevMusic();
	void sChangeToNextMusic();

	//Playlist & Directory
	void sAddFilePlaylist();
	void sRemoveFilePlayList();
	void sSavePlayList();
	void sAddCollection();
	void sAddToDirectory();
	void sRemoveFromDirectory();
	void sRemoveCollection();
	void sShowSelectedCollection(int r, int c);
	void sAddCollectionToCurrent();
	void sAddDirectoryToCurrent();

	//Keyboard
	void sAddSoundToKeyboard();
	void sPlayKeyboardSound();

	//Visualizer Option
	void sChangeSampleSize();
	void sChangeSoundBarsColor();
	void sChangeJumpersColor();
	void sChangeBGColor();


	//CurrentList
	void sEmptyCurrent();
	void sRemoveFromCurrent();
	void sUpSongCurrent();
	void sDownSongCurrent();
	void sPutNext();
	void sCurrentListOptionSecurity(int r, int c);
	void sShuffle();

	//Equalizer
	void sRemoveEffectsFromEq();
	void sSetVolumeFromEq();
	void sSetSpeedFromEq();
	void sSetEchoFromEq();
	void sSetPitchFromEq();
	void sSetFlangeFromEq();
	void sSetTremoloFromEq();
	void sSetDistortionFromEq();
};

#endif // GUI_H
