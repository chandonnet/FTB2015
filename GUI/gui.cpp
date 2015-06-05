#include "gui.h"

#define PRECISION 500

GUI::GUI(QWidget *parent) : QMainWindow(parent)
{
	logic = new InterfaceLogique(this->ui);
	timer = new QTimer(this);

	InitAll();
	ConnectAll();

	sfmlViewHome = new SFMLWindow(this->ui.frmSFML, QPoint(0,0), this->ui.frmSFML->size());
	sfmlViewVis = new SFMLWindow(this->ui.frmSFMLVisualizer, QPoint(0,0), this->ui.frmSFMLVisualizer->size());
}

GUI::~GUI()
{
	this->logic->mySys.StopMusic();
	bool isPlaying = true;
	while(this->logic->mySys.channel->isPlaying(&isPlaying) == FMOD_OK && isPlaying){}
	ClearKeyboard();

	delete sfmlViewHome;
	delete sfmlViewVis;

	delete timer;
	delete icon;
	delete logic;
}

void GUI::InitKeyboard()
{
	for (int i = 0; i < 6; i++)
	{
		KeyboardFacade* newFacade = new KeyboardFacade(this);

		newFacade->GetButton()->setText(keys[i]);
		newFacade->GetShortcut()->setKey(QKeySequence::fromString(keys[i]));

		connect(newFacade->GetButton(), SIGNAL(clicked()), this, SLOT(sAddSoundToKeyboard()));
		connect(newFacade->GetShortcut(), SIGNAL(activated()), this, SLOT(sPlayKeyboardSound()));

		this->ui.hboxKeyboard->insertLayout(i, newFacade);

		keyboard.emplace_back(newFacade);
	}
}

void GUI::InitIcons()
{
	icon = new QPixmap(100, 100);

	icon->fill(QColor(0, 255, 0));
	this->ui.pbtnSoundBars->setIcon(QIcon(*icon));

	icon->fill(QColor(255, 255, 0));
	this->ui.pbtnJumpers->setIcon(QIcon(*icon));

	icon->fill(QColor(0, 0, 0));
	this->ui.pbtnBackground->setIcon(QIcon(*icon));
}

void GUI::ShowSFMLViews()
{
	sfmlViewHome->show();
	sfmlViewHome->SetSpec(this->logic->mySys.spec);

	sfmlViewVis->show();
	sfmlViewVis->SetSpec(this->logic->mySys.spec);
}

void GUI::sPlayKeyboardSound()
{
	Shortcut* source = (Shortcut*) QObject::sender();

	source->GetAssociatedButton()->Play(this->logic->mySys);
}

void GUI::sAddSoundToKeyboard()
{
	KeyboardButton* source = (KeyboardButton*) QObject::sender();

	QUrl url = QFileDialog::getOpenFileUrl(this, "Choisir un fichier...", QDir::homePath(), tr("Fichier Audio (*.mp3)"));
	string filePath = logic->AddKeyboardSound(source, url);

	if (filePath != "")
	{
		source->GetAssociatedLabel()->setText(QString::fromStdString(filePath.substr(filePath.rfind('/')+1, filePath.length())));
	}	
}

void GUI::sPlayMusic()
{
	bool isPaused;

	if(this->logic->PlayThread())
	{
		logic->mySys.channel->getPaused(&isPaused);

		if(!isPaused)
		{
			timer->start(500);

			ui.pBtnNext->setEnabled(true);
			ui.pBtnPrev->setEnabled(true);

			unsigned int length;
			this->logic->mySys.currentSound->getLength(&length, FMOD_TIMEUNIT_MS);
			this->logic->SetCurrentLength(length);

			float freq;
			this->logic->mySys.channel->getFrequency(&freq);
			this->logic->SetCurrentFrequency(freq);

			this->ui.vSlider_Volume->valueChanged(this->ui.vSlider_Volume->value());

			if(((length/1000)%60) < 10)
			{
				ui.label_3->setText(QString::number((length/1000)/60) + ":0" + QString::number((length/1000)%60));
			}
			else
			{
				ui.label_3->setText(QString::number((length/1000)/60) + ":" + QString::number((length/1000)%60));
			}
			ui.timeSlider->setSingleStep(1);
			ui.timeSlider->setMaximum(length);
			ui.vSlider_Speed->setMaximum(freq * 1.5);
			ui.vSlider_Speed->setMinimum(freq/2);
			ui.vSlider_Speed->setValue(freq);
			this->logic->RemoveEffects();
		}
	}

	logic->mySys.channel->getPaused(&isPaused);
	this->ui.cboxSample->setEnabled(isPaused);
}

void GUI::sRemoveEffectsFromEq()
{
	this->logic->RemoveEffects();
}

void GUI::sSetVolume()
{
	this->logic->AdjustVolume(ui.volSlider, ui.vSlider_Volume);
}

void GUI::sSetVolumeFromEq()
{
	this->logic->AdjustVolume(ui.vSlider_Volume, ui.volSlider);
}

void GUI::sSetSpeedFromEq()	
{
	this->logic->SetSpeed();
}

void GUI::sSetEchoFromEq()
{
	this->logic->SetEcho();
}

void GUI::sSetPitchFromEq()
{
	this->logic->SetPitch();
}

void GUI::sSetFlangeFromEq()
{
	this->logic->SetFlange();
}

void GUI::sSetTremoloFromEq()
{
	this->logic->SetTremolo();
}

void GUI::sSetDistortionFromEq()
{
	this->logic->SetDistortion();
}

void GUI::sSetTime()
{
	unsigned int time;

	logic->mySys.channel->getPosition(&time, FMOD_TIMEUNIT_MS);
	int t = time;
	if(((t/1000)%60) < 10)
	{
		ui.label_2->setText(QString::number((t/1000)/60) + ":0" + QString::number((t/1000)%60));
	}
	else
	{
		ui.label_2->setText(QString::number((t/1000)/60) + ":" + QString::number((t/1000)%60));
	}
	ui.timeSlider->setValue(t);

	int l = this->logic->GetCurrentLength();

	if((std::abs(l - t) < PRECISION && std::abs(l - t) < PRECISION))	
	{
		this->sChangeToNextMusic();
	}
}

void GUI::sSavePlayList()
{

	QUrl url = QFileDialog::getExistingDirectoryUrl();
	bool valid = logic->SavePlayList(ui.txtName->text(), url);
	CheckValid(valid, "Erreur", "Sauvegarde Impossible", "Succès", "Collection Sauvegardé");
}

void GUI::sAddFilePlaylist()
{
	QList<QUrl> urls = QFileDialog::getOpenFileUrls(this, "Choisir un fichier...", QDir::homePath(), tr("Fichier Audio (*.mp3)"));
	logic->AddFilePlayList(urls);
}

void GUI::sRemoveFilePlayList()
{
	logic->RemoveFilePlayList();
}

void GUI::sSetSongTime()
{
	unsigned int time;
	this->logic->mySys.channel->getPosition(&time, FMOD_TIMEUNIT_MS);

	if(time != ui.timeSlider->value())
	{
		this->logic->mySys.channel->setPosition(ui.timeSlider->value(), FMOD_TIMEUNIT_MS);
	}

}

void GUI::sAddCollection()
{
	QUrl url = QFileDialog::getOpenFileUrl(this, "Choisir un fichier...", QDir::homePath(), tr("Playlist Files (*.m3u)"));
	logic->AddCollection(url);
}

void GUI::sRemoveCollection()
{
	logic->RemoveCollection();
}

void GUI::sShowSelectedCollection(int r, int c)
{
	logic->ShowSelectedCollection(r);
}

void GUI::sChangeSampleSize()
{
	this->logic->mySys.SetSampleSize((this->ui.cboxSample->currentText()).toInt());

	this->sfmlViewHome->SetSpec(this->logic->mySys.spec);
	this->sfmlViewVis->SetSpec(this->logic->mySys.spec);

	this->sfmlViewHome->SetSampleSize(((this->ui.cboxSample->currentText()).toInt()) * 0.8); //80% du real sample
	this->sfmlViewVis->SetSampleSize(((this->ui.cboxSample->currentText()).toInt()) * 0.8);	
}

void GUI::sChangeSoundBarsColor()
{
	QColor newColor = QColorDialog::getColor();

	if (newColor.isValid())
	{
		this->sfmlViewHome->SetSoundBarsColor(newColor.red(), newColor.green(), newColor.blue());
		this->sfmlViewVis->SetSoundBarsColor(newColor.red(), newColor.green(), newColor.blue());
	}	

	icon->fill(newColor);
	this->ui.pbtnSoundBars->setIcon(QIcon(*icon));
}

void GUI::sChangeJumpersColor()
{
	QColor newColor = QColorDialog::getColor();

	if (newColor.isValid())
	{
		this->sfmlViewHome->SetJumpersColor(newColor.red(), newColor.green(), newColor.blue());
		this->sfmlViewVis->SetJumpersColor(newColor.red(), newColor.green(), newColor.blue());
	}	

	icon->fill(newColor);
	this->ui.pbtnJumpers->setIcon(QIcon(*icon));
}

void GUI::sChangeBGColor()
{
	QColor newColor = QColorDialog::getColor();

	if (newColor.isValid())
	{
		this->sfmlViewHome->SetBackGroundColor(newColor.red(), newColor.green(), newColor.blue());
		this->sfmlViewVis->SetBackGroundColor(newColor.red(), newColor.green(), newColor.blue());
	}	

	icon->fill(newColor);
	this->ui.pbtnBackground->setIcon(QIcon(*icon));
}

void GUI::sAddCollectionToCurrent()
{
	logic->AddCollectionToCurrent();
}

void GUI::sAddToDirectory()
{
	QList<QUrl> urls = QFileDialog::getOpenFileUrls(this, "Choisir un fichier...", QDir::homePath(), tr("Fichier Audio (*.mp3)"));
	logic->AddFileDirectory(urls);
}

void GUI::sRemoveFromDirectory()
{
	logic->RemoveSongFromDirectory();
}

void GUI::sChangeToNextMusic()
{
	if(this->logic->ChangeSong(true))
	{
		this->timer->stop();
		bool isPlaying;
		while(this->logic->mySys.channel->isPlaying(&isPlaying) == FMOD_OK && isPlaying){}
		this->sPlayMusic();
	}
	else
	{
		this->timer->stop();
		MessageWindow mW("Attention", "Il n'y a plus de chansons dans la liste d'attente.");
		mW.Execute();
	}
}

void GUI::sChangeToPrevMusic()
{
	if(this->logic->ChangeSong(false))
	{
		this->timer->stop();
		bool isPlaying;
		while(this->logic->mySys.channel->isPlaying(&isPlaying) == FMOD_OK && isPlaying){}
		this->sPlayMusic();
	}
	else
	{
		MessageWindow mW("Attention", "Il n'y a plus de chansons dans la liste d'attente.");
		mW.Execute();
	}
}

void GUI::sEmptyCurrent()
{
	this->logic->mySys.StopMusic();
	this->logic->SetIsPlaying(false);
	logic->EmptyCurrent();
}

void GUI::sAddDirectoryToCurrent()
{
	logic->AddSongToCurrentFromDirectory();
}

void GUI::sRemoveFromCurrent()
{
	logic->RemoveSongFromCurrent();
}

void GUI::sUpSongCurrent()
{
	logic->UpSong();
}

void GUI::sDownSongCurrent()
{
	logic->DownSong();
}

void GUI::sCurrentListOptionSecurity(int r , int c)
{
	logic->CurrentListSecurity(r);
}

void GUI::sShuffle()
{
	logic->ShuffleCurrent();
}

void GUI::sPutNext()
{
	logic->PutNext();
}

void GUI::ConnectAll()
{
	connect(ui.pBtnPlayPause, SIGNAL(clicked()), this, SLOT(sPlayMusic()));
	connect(ui.btnAjouterChansonCollection, SIGNAL(clicked()), this, SLOT(sAddFilePlaylist()));
	connect(ui.btnSupprimerChansonCollection, SIGNAL(clicked()), this, SLOT(sRemoveFilePlayList()));
	connect(ui.btnSauvegarderCollection, SIGNAL(clicked()), this, SLOT(sSavePlayList()));
	connect(ui.volSlider, SIGNAL(valueChanged(int)), this, SLOT(sSetVolume()));
	connect(ui.timeSlider, SIGNAL(valueChanged(int)), this, SLOT(sSetSongTime()));
	connect(timer, SIGNAL(timeout()), this, SLOT(sSetTime()));
	connect(ui.btnAjouterCollection, SIGNAL(clicked()), this, SLOT(sAddCollection()));
	connect(ui.btnSupprimerCollection, SIGNAL(clicked()), this , SLOT(sRemoveCollection()));
	connect(ui.collectionTable, SIGNAL(cellClicked(int,int)), this, SLOT(sShowSelectedCollection(int, int)));
	connect(ui.cboxSample, SIGNAL(currentIndexChanged(int)), this, SLOT(sChangeSampleSize()));
	connect(ui.pbtnSoundBars, SIGNAL(clicked()), this, SLOT(sChangeSoundBarsColor()));
	connect(ui.pbtnJumpers, SIGNAL(clicked()), this, SLOT(sChangeJumpersColor()));
	connect(ui.pbtnBackground, SIGNAL(clicked()), this, SLOT(sChangeBGColor()));
	connect(ui.btnAjouterChansonBiblio, SIGNAL(clicked()), this, SLOT(sAddToDirectory()));
	connect(ui.btnJouerCollection, SIGNAL(clicked()), this, SLOT(sAddCollectionToCurrent()));
	connect(ui.btnSupprimerChansonBiblio, SIGNAL(clicked()), this, SLOT(sRemoveFromDirectory()));
	connect(ui.pBtnNext, SIGNAL(clicked()), this, SLOT(sChangeToNextMusic()));
	connect(ui.pBtnPrev, SIGNAL(clicked()), this, SLOT(sChangeToPrevMusic()));
	connect(ui.btnViderCurrent, SIGNAL(clicked()), this, SLOT(sEmptyCurrent()));
	connect(ui.btnRetirerCurrentList, SIGNAL(clicked()), this, SLOT(sRemoveFromCurrent()));
	connect(ui.btnAjouterCurrentBiblio, SIGNAL(clicked()), this, SLOT(sAddDirectoryToCurrent()));
	connect(ui.currentListTable, SIGNAL(cellClicked(int,int)), this, SLOT(sCurrentListOptionSecurity(int, int)));
	connect(ui.btnMonterCurrentList, SIGNAL(clicked()), this, SLOT(sUpSongCurrent()));
	connect(ui.btnDescendreCurrentList, SIGNAL(clicked()), this, SLOT(sDownSongCurrent()));
	connect(ui.pbtnShuffle, SIGNAL(clicked()), this, SLOT(sShuffle()));
	connect(ui.pbtnPutNext, SIGNAL(clicked()), this, SLOT(sPutNext()));
	connect(ui.vSlider_Volume, SIGNAL(valueChanged(int)), this, SLOT(sSetVolumeFromEq()));
	connect(ui.vSlider_Speed, SIGNAL(valueChanged(int)), this, SLOT(sSetSpeedFromEq()));
	connect(ui.vSlider_Echo, SIGNAL(valueChanged(int)), this, SLOT(sSetEchoFromEq()));
	connect(ui.vSlider_Pitch, SIGNAL(valueChanged(int)), this, SLOT(sSetPitchFromEq()));
	connect(ui.vSlider_Flange, SIGNAL(valueChanged(int)), this, SLOT(sSetFlangeFromEq()));
	connect(ui.vSlider_Tremolo, SIGNAL(valueChanged(int)), this, SLOT(sSetTremoloFromEq()));
	connect(ui.vSlider_Distortion, SIGNAL(valueChanged(int)), this, SLOT(sSetDistortionFromEq()));
	connect(ui.pBtnReset, SIGNAL(clicked()), this, SLOT(sRemoveEffectsFromEq()));
}

void GUI::InitAll()
{
	ui.setupUi(this);
	ui.volSlider->setSliderPosition(99);
	logic->Load();

	QString key[] = {"Q", "W", "E", "R", "T", "Y", "A", "S", "D", "F", "G", "H"};
	this->keys = key;
	this->nbKeys = 6;

	SetColumnWidth(ui.collectionTable, 1);
	SetColumnWidth(ui.directoryTable, 4, 110);
	SetColumnWidth(ui.affichageCollectionTable, 4, 91);
	SetColumnWidth(ui.createCollectionTable, 4, 91);
	SetColumnWidth(ui.currentListTable, 3);

	InitIcons();
	InitKeyboard();
}

void GUI::SetColumnWidth(QTableWidget* table, int nbRow)
{
	int width = table->width();

	int indWidth = width / nbRow;
	for(int i = 0; i < nbRow; i++)
	{
		table->setColumnWidth(i, indWidth);
	}
}

void GUI::SetColumnWidth(QTableWidget* table, int nbRow, int lastRowSize)
{
	int width = table->width();
	int indWidth = (width - lastRowSize) / (nbRow - 1);
	for(int i = 0; i < nbRow - 1; i++)
	{
		table->setColumnWidth(i, indWidth);
	}
	table->setColumnWidth(nbRow, lastRowSize);
}

void GUI::CheckValid(bool valid, string titleError, string messageError)
{
	if(!valid)
	{
		MessageWindow mw(titleError, messageError);
		mw.Execute();
	}
}

void GUI::CheckValid(bool valid, string titleError, string messageError, string titleSuccess, string messageSuccess)
{
	if(!valid)
	{
		MessageWindow mw(titleError, messageError);
		mw.Execute();
	}
	else
	{
		MessageWindow mw(titleSuccess, messageSuccess);
		mw.Execute();
	}
}

void GUI::ClearKeyboard()
{
	if(!this->keyboard.empty())
	{
		vector<KeyboardFacade*>::iterator it;

		for (it = this->keyboard.begin() ; it != this->keyboard.end(); it++)
		{
			delete *it;
		}

		this->keyboard.clear();
	}
}
