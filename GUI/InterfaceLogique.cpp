#include "InterfaceLogique.h"
#define COLOR QColor(153,255,153)

InterfaceLogique::InterfaceLogique(Ui::mainWindow &ui)
{
	this->myUI = &ui;
	this->buildPList = new Playlist("newList", QDir::homePath().toLocal8Bit().constData());
	this->isPlaying = false;
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_ECHO, &DSPEcho);
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &DSPPitch);
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_FLANGE, &DSPFlange);
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &DSPTremolo);
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_DISTORTION, &DSPDistortion);
}

InterfaceLogique::~InterfaceLogique(void)
{
	dd.SaveConfig(directory, playlists);
	DeleteList();
}

void InterfaceLogique::Load()
{
	directory = dd.LoadDirectory();
	playlists = dd.LoadCollection();


	myUI->btnMonterCurrentList->setDisabled(true);
	myUI->btnDescendreCurrentList->setDisabled(true);
	myUI->btnRetirerCurrentList->setDisabled(true);
	myUI->pbtnPutNext->setDisabled(true);

	FillTable(myUI->collectionTable, playlists);
	FillTable(myUI->directoryTable, this->directory->GetPlayList());
}

void InterfaceLogique:: DeleteList()
{
	delete buildPList;
	delete directory;
	ClearPlaylists();
	currentList.clear();
}

bool InterfaceLogique::AddFilePlayList(QList<QUrl> urlList)
{
	if(!ValidateUrls(urlList))
	{
		return false;
	}
	ClearTable(myUI->createCollectionTable);
	FindFile(urlList, buildPList->GetPlayList());
	FillTable(myUI->createCollectionTable, buildPList->GetPlayList());
	return true;
}

bool InterfaceLogique::AddFileDirectory(QList<QUrl> urlList)
{
	if(!ValidateUrls(urlList))
	{
		return false;
	}
	ClearTable(myUI->directoryTable);
	FindFile(urlList, *directory);
	FillTable(myUI->directoryTable, directory->GetPlayList());
	return true;
}

bool InterfaceLogique::RemoveFilePlayList()
{
	QModelIndexList indexes = myUI->createCollectionTable->selectionModel()->selection().indexes();
	if(indexes.count() / 4 < 1)
	{
		return false;
	}
	for (int i = indexes.count() / 4; i > 0; i--)
	{
		QModelIndex index = indexes.at(i);
		buildPList->RemoveSong(index.row());
	}
	ClearTable(myUI->createCollectionTable); // Vide la table
	FillTable(myUI->createCollectionTable, buildPList->GetPlayList()); // Re-remplir avec le contenu mis à jour
	return true;
}

bool InterfaceLogique::RemoveSongFromDirectory()
{
	QModelIndexList indexes = myUI->directoryTable->selectionModel()->selection().indexes();
	int rowCount = myUI->directoryTable->rowCount();
	if(indexes.count() / 4 < 1)
	{
		return false;
	}
	for (int i = indexes.count() - 1; i >= 0; i-=4)
	{
		QModelIndex index = indexes.at(i);
		RemoveSong(directory->GetPlayList().at(index.row()));
		directory->RemoveSong(index.row());
	}
	ClearTable(myUI->directoryTable); // Vide la table
	FillTable(myUI->directoryTable, directory->GetPlayList()); // Re-remplir avec le contenu mis à jour
	ClearTable(myUI->currentListTable);
	FillTable(myUI->currentListTable, currentList);
	return true;
}

void InterfaceLogique::FindFile(QList<QUrl> urlList, vector<SoundInfo*>& list)
{
	LoadingDialog loading(urlList.length());
	for(int i = 0; i < urlList.length(); i++)
	{
		string url = urlList.at(i).toString().toLocal8Bit().constData();
		string path = url.substr(8, url.length());
		SoundInfo* info = new SoundInfo(path);
		list.push_back(info);
		loading.Update(i, info->GetTitle());
	}
	loading.Update(urlList.length());
}

void InterfaceLogique::FindFile(QList<QUrl> urlList, Playlist& list)
{
	LoadingDialog loading(urlList.length());

	for(int i = 0; i < urlList.length(); i++)
	{
		string url = urlList.at(i).toString().toLocal8Bit().constData();
		string path = url.substr(8, url.length());
		list.AddSong(path);

		loading.Update(i);
	}

	loading.Update(urlList.length());
}

bool InterfaceLogique::SavePlayList(QString name, QUrl url)
{
	if(!ValidateUrl(url))
	{
		return false;
	}
	if(buildPList->GetPlayList().size() < 0)
	{
		return false;
	}
	string path = url.toString().toLocal8Bit().constData();
	buildPList->SetPath(path.substr(8, path.length()));
	buildPList->SetName(name.toLocal8Bit().constData());
	buildPList->SavePlayList();
	return true;
}

bool InterfaceLogique::AddCollectionToCurrent() 
{
	QModelIndexList indexes = myUI->collectionTable->selectionModel()->selection().indexes();
	if(indexes.count() < 0 || playlists.size() == 0)
	{
		return false;
	}
	int no = myUI->currentListTable->rowCount();
	for (int i = 0; i < indexes.count(); ++i)
	{
		FillListFromVector(currentList, playlists[indexes.at(i).row()]->GetPlayList());
		FillTable(myUI->currentListTable, playlists[indexes.at(i).row()]->GetPlayList());
	}
	this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
	return true;
}

void InterfaceLogique::FillListFromVector(list<SoundInfo*>& cible, vector<SoundInfo*> source)
{
	for (vector<SoundInfo*>::iterator it = source.begin(); it < source.end(); it++)
	{
		cible.emplace_back(*it);
	}
}

bool InterfaceLogique::PlayThread()
{
	if(!this->isPlaying)
	{
		if(this->SelectSong())
		{
			std::thread music = std::thread(&InterfaceLogique::Task, this);
			music.detach();
			while(!this->mySys.channel->isPlaying(&this->isPlaying) == FMOD_OK && !this->isPlaying){}
			this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
		}
		else
		{
			MessageWindow mW("Attention", "Il n'y a plus de chansons dans l'application.");
			mW.Execute();
			return false;
		}
	}
	else
	{
		this->mySys.channel->setPaused(this->mySys.channel->getPaused(&isPaused) == FMOD_OK && !isPaused);
	}
	return true;
}

void InterfaceLogique::Task()
{
	mySys.PlayMusic(this->currentList.front()->GetPath());
	ExitThread(0);
}

bool InterfaceLogique::GetIsPlaying()
{
	return this->isPlaying;
}

void InterfaceLogique::FillTable(QTableWidget* table, std::vector<SoundInfo*> list)
{
	int no = table->rowCount();
	for(std::vector<SoundInfo*>::iterator it = list.begin(); it != list.end(); it++)
	{
		table->setRowCount(table->rowCount() + 1);
		QTableWidgetItem *itemTitle = new QTableWidgetItem((*it)->GetTitle().c_str());
		QTableWidgetItem *itemArtist = new QTableWidgetItem((*it)->GetArtist().c_str());
		QTableWidgetItem *itemAlbum = new QTableWidgetItem((*it)->GetAlbum().c_str());
		table->setItem(no, 0, itemTitle);
		table->setItem(no, 2, itemArtist);
		table->setItem(no, 1, itemAlbum);
		no++;

	}
}

void InterfaceLogique::FillTable(QTableWidget* table, std::list<SoundInfo*> list)
{
	int no = table->rowCount();
	for(std::list<SoundInfo*>::iterator it = list.begin(); it != list.end(); it++)
	{

		table->setRowCount(table->rowCount() + 1);
		QTableWidgetItem *itemTitle = new QTableWidgetItem((*it)->GetTitle().c_str());
		QTableWidgetItem *itemArtist = new QTableWidgetItem((*it)->GetArtist().c_str());
		QTableWidgetItem *itemAlbum = new QTableWidgetItem((*it)->GetAlbum().c_str());
		table->setItem(no, 0, itemTitle);
		table->setItem(no, 2, itemArtist);
		table->setItem(no, 1, itemAlbum);
		no++;

	}
}

void InterfaceLogique::FillTable(QTableWidget* table, std::vector<Playlist*> list)
{
	int no = table->rowCount();
	for(std::vector<Playlist*>::iterator it = list.begin(); it != list.end(); it++)
	{

		table->setRowCount(table->rowCount() + 1);
		QTableWidgetItem *itemTitle = new QTableWidgetItem((*it)->GetName().c_str());
		table->setItem(no, 0, itemTitle);
		no++;

	}
}

void InterfaceLogique::ClearTable(QTableWidget* table)
{
	table->clearContents();
	table->setRowCount(0);
}

bool InterfaceLogique::AddCollection(QUrl url)
{
	LoadingDialog loading(5);

	loading.Update(1, "Création de la liste");
	if(!ValidateUrl(url))
	{
		return false;
	}
	Playlist* mylist = new Playlist(url.toString().toLocal8Bit().constData());


	loading.Update(2, "Importation des fichiers");
	mylist->Load();	


	playlists.emplace_back(mylist);
	loading.Update(3);

	ClearTable(myUI->collectionTable);
	FillTable(myUI->collectionTable, playlists);
	loading.Update(4);

	ClearTable(myUI->affichageCollectionTable);
	FillTable(myUI->affichageCollectionTable, mylist->GetPlayList());
	loading.Update(5);

	return true;
}

bool InterfaceLogique::RemoveCollection()
{
	QModelIndexList indexes = myUI->collectionTable->selectionModel()->selection().indexes();
	if(indexes.count() < 0)
	{
		return false;
	}
	for (int i = 0; i < indexes.count(); i++)
	{
		QModelIndex index = indexes.at(i);
		if(playlists.size() == 1)
		{
			RemoveCollectionMember(playlists.at(0));
			delete playlists.at(0);
			playlists.erase(playlists.begin());
		}
		else
		{
			RemoveCollectionMember(playlists.at(index.row()));
			delete playlists.at(index.row());
			playlists.erase(playlists.begin() + index.row());

		}
		
	}
	ClearTable(myUI->affichageCollectionTable);
	ClearTable(myUI->collectionTable); 
	ClearTable(myUI->currentListTable);
	FillTable(myUI->collectionTable, playlists);
	FillTable(myUI->currentListTable, currentList);
	return true;
}

bool InterfaceLogique::ShowSelectedCollection(int r)
{
	if(r < 0)
	{
		return false;
	}
	ClearTable(myUI->affichageCollectionTable);
	FillTable(myUI->affichageCollectionTable, playlists[r]->GetPlayList());
	return true;
}

void InterfaceLogique::SetIsPlaying(bool play)
{
	this->isPlaying = play;
}

bool InterfaceLogique::ChangeSong(bool next)
{
	if(!this->currentList.empty())
	{
		this->myUI->pBtnNext->setEnabled(false);
		this->myUI->pBtnPrev->setEnabled(false);
		this->mySys.StopMusic();

		SoundInfo* tmp;
		if(next)
		{
			tmp = this->currentList.front();
			this->currentList.pop_front();
			this->currentList.emplace_back(tmp);
		}
		else
		{
			tmp = this->currentList.back();
			this->currentList.pop_back();
			this->currentList.emplace_front(tmp);
		}

		this->ClearTable(this->myUI->currentListTable);
		this->FillTable(this->myUI->currentListTable, this->currentList);
		this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
		this->isPlaying = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool InterfaceLogique::ValidateUrls(QList<QUrl> urlList)
{
	bool valid = false;
	for (int i = 0; i < urlList.length(); i++)
	{
		valid = ValidateUrl(urlList.at(i));
		if(!valid)
		{
			break;
		}
	}
	return valid;
}

bool InterfaceLogique::ValidateUrl(QUrl url)
{
	QString mylist = url.toString(QUrl::RemoveScheme);
	if(mylist == "")
	{
		return false;
	}
	return true;
}

bool InterfaceLogique::AddSongToCurrentFromDirectory()
{
	QModelIndexList indexes = myUI->directoryTable->selectionModel()->selection().indexes();
	if(indexes.count() < 1 || directory->GetPlayList().size() == 0)
	{
		return false;
	}
	for (int i = 0; i < indexes.count(); i+=4)
	{
		QModelIndex index = indexes.at(i);
		currentList.emplace_back(directory->GetPlayList().at(index.row()));
	}
	ClearTable(myUI->currentListTable);
	FillTable(myUI->currentListTable, currentList);
	this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
	return true;
}

void InterfaceLogique::EmptyCurrent()
{
	ClearTable(myUI->currentListTable);
	currentList.clear();
	this->myUI->label_3->setText("0:00");
}

void InterfaceLogique::ClearPlaylists()
{
	if(!this->playlists.empty())
	{
		vector<Playlist*>::iterator it;

		for (it = this->playlists.begin() ; it != this->playlists.end(); it++)
		{
			delete *it;
		}

		this->playlists.clear();
	}
}

void InterfaceLogique::ClearCurrentList()
{
	if(!this->currentList.empty())
	{
		list<SoundInfo*>::iterator it;

		for (it = this->currentList.begin() ; it != this->currentList.end(); it++)
		{
			delete *it;
		}

		this->currentList.clear();
	}
}

bool InterfaceLogique::RemoveSongFromCurrent()
{
	QModelIndexList indexes = myUI->currentListTable->selectionModel()->selection().indexes();
	if(indexes.count() / 3 < 1)
	{
		return false;
	}

	int i = 0;
	bool erased = false;
	for (list<SoundInfo*>::iterator it = currentList.begin(); it != currentList.end(); it++)
	{
		QModelIndex ind = indexes.at(0);
		if(ind.row() == i)
		{
			currentList.erase(it);
			break;
		}
		i++;
	}

	ClearTable(myUI->currentListTable); // Vide la table
	FillTable(myUI->currentListTable, currentList); // Re-remplir avec le contenu mis à jour
	this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
	return true;
}

void InterfaceLogique::CurrentListSecurity(int r)
{
	if(r < 2)
	{
		myUI->btnMonterCurrentList->setDisabled(true);
		myUI->pbtnPutNext->setDisabled(true);
	}
	else
	{
		myUI->btnMonterCurrentList->setDisabled(false);
		myUI->pbtnPutNext->setDisabled(false);
	}

	if(r == 0)
	{
		myUI->btnRetirerCurrentList->setDisabled(true);
	}
	else
	{
		myUI->btnRetirerCurrentList->setDisabled(false);
	}

	if(r == currentList.size() - 1 || r == 0)
	{
		myUI->btnDescendreCurrentList->setDisabled(true);
	}
	else
	{
		myUI->btnDescendreCurrentList->setDisabled(false);
	}
}

bool InterfaceLogique::UpSong()
{
	QModelIndexList indexes = myUI->currentListTable->selectionModel()->selection().indexes();
	if(indexes.count() / 3 < 1)
	{
		return false;
	}

	int i = 0;
	list<SoundInfo*>::iterator it2 = currentList.begin();
	bool first = true;
	for(list<SoundInfo*>::iterator it = currentList.begin(); it != currentList.end(); it++)
	{
		QModelIndex ind = indexes.at(0);
		if(ind.row() == i)
		{
			std::iter_swap(it, it2);
			break;
		}

		if(!first)
		{
			it2++;
		}
		else
		{
			first = false;
		}
		i++;
	}

	ClearTable(myUI->currentListTable); // Vide la table
	FillTable(myUI->currentListTable, currentList); // Re-remplir avec le contenu mis à jour
	this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
	return true;
}

bool InterfaceLogique::DownSong()
{
	QModelIndexList indexes = myUI->currentListTable->selectionModel()->selection().indexes();
	if(indexes.count() / 3 < 1)
	{
		return false;
	}

	int i = 0;
	list<SoundInfo*>::iterator it2 = currentList.begin();
	it2++;
	for(list<SoundInfo*>::iterator it = currentList.begin(); it != currentList.end(); it++)
	{
		QModelIndex ind = indexes.at(0);
		if(ind.row() == i)
		{
			std::iter_swap(it, it2);
			break;
		}
		if(it2 != currentList.end()--)
		{
			it2++;
		}
		i++;
	}

	ClearTable(myUI->currentListTable); // Vide la table
	FillTable(myUI->currentListTable, currentList); // Re-remplir avec le contenu mis à jour
	this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
	return true;
}

int InterfaceLogique::GetCurrentLength()
{
	return this->currentlength;
}

void InterfaceLogique::SetCurrentLength(int length)
{
	this->currentlength = length;
}

void InterfaceLogique::ColorTableLine(QTableWidget* table, int r, int nbCol, QColor color)
{
	int size = table->rowCount();
	if(size > r)
	{
		for(int i = 0; i < nbCol; i++)
		{
			table->item(r, i)->setBackgroundColor(color);
		}
	}
}

bool InterfaceLogique::SelectSong()
{
	if(!currentList.empty())
	{
		return true;
	}

	if(!directory->GetPlayList().empty())
	{
		FillFromDirectory(100);
		return true;
	}

	return FillFromCollection();
}

void InterfaceLogique::FillFromDirectory(int nb)
{
	int size = directory->GetPlayList().size();

	if(size > nb)
	{
		size = nb;
	}
	vector<SoundInfo*>::iterator it = directory->GetPlayList().begin();
	for (int i = 0; i < size; i++)
	{
		currentList.push_back(*it);
		it++;
	}
	FillTable(this->myUI->currentListTable, this->currentList);
}

bool InterfaceLogique::FillFromCollection()
{
	if(playlists.empty())
	{
		return false;
	}
	else
	{
		FillListFromVector(currentList, playlists.at(0)->GetPlayList());
		FillTable(this->myUI->currentListTable, this->currentList);
		return true;
	}
}

bool InterfaceLogique::ShuffleCurrent()
{
	if(currentList.size() < 3)
	{
		return false;
	}
	vector<SoundInfo*> myVector(currentList.size());
	copy(currentList.begin(), currentList.end(), myVector.begin());
	vector<SoundInfo*>::iterator begin = myVector.begin();
	begin++;
	random_shuffle(begin, myVector.end());
	list<SoundInfo*> myListShuffled(myVector.begin(), myVector.end());
	currentList = myListShuffled;
	ClearTable(myUI->currentListTable);
	FillTable(myUI->currentListTable, currentList);
	this->ColorTableLine(this->myUI->currentListTable,0, 3, QColor(COLOR));
	return true;
}

bool InterfaceLogique::PutNext()
{
	QModelIndexList indexes = myUI->currentListTable->selectionModel()->selection().indexes();
	if(indexes.count() / 3 < 1)
	{
		return false;
	}
	vector<SoundInfo*> myVector(currentList.size());
	copy(currentList.begin(), currentList.end(), myVector.begin());
	vector<SoundInfo*>::iterator it = myVector.begin();
	it++;
	int i = 0;
	QModelIndex ind = indexes.at(0);
	for(vector<SoundInfo*>::iterator it2 = myVector.begin(); it2 != myVector.end(); it2++)
	{
		if(ind.row() == i)
		{
			myVector.insert(it, myVector.at(i));
			myVector.erase(myVector.begin() + i + 1);
			break;
		}
		i++;
	}
	list<SoundInfo*> myList(myVector.begin(), myVector.end());
	currentList = myList;
	ClearTable(myUI->currentListTable); // Vide la table
	FillTable(myUI->currentListTable, currentList); // Re-remplir avec le contenu mis à jour
	this->ColorTableLine(this->myUI->currentListTable, 0, 3, QColor(COLOR));
	return true;
}

string InterfaceLogique::AddKeyboardSound(KeyboardButton* button, QUrl url)
{
	if (ValidateUrl(url))
	{
		string unValidePath = url.toString().toLocal8Bit().constData();
		string path = unValidePath.substr(8, unValidePath.length());

		button->SetSound(path, mySys);
		mySys.AddChannelToMaster(button->GetSound()->channel);

		return path;
	}

	return "";
}

void InterfaceLogique::SetCurrentFrequency(float f)
{
	this->currentFrequency = f;
}

void InterfaceLogique::RemoveEffects()
{
	this->SlidersToDefault();
	this->DSPEcho->remove();
	this->DSPPitch->remove();
	this->DSPFlange->remove();
	this->DSPDistortion->remove();
	this->DSPTremolo->remove();
}

void InterfaceLogique::SlidersToDefault()
{
	this->myUI->vSlider_Speed->setValue(this->currentFrequency);
	this->myUI->vSlider_Echo->setValue(0);
	this->myUI->vSlider_Pitch->setValue(50);
	this->myUI->vSlider_Flange->setValue(0);
	this->myUI->vSlider_Distortion->setValue(0);
	this->myUI->vSlider_Tremolo->setValue(0);
}

void InterfaceLogique::AdjustVolume(QSlider* slider, QSlider* slider2)
{
	float vol = slider->value();
	slider2->setValue(vol);
	this->mySys.channel->setVolume(vol/100);
}

void InterfaceLogique::SetSpeed()
{
	this->mySys.channel->setFrequency(this->myUI->vSlider_Speed->value());
}

void InterfaceLogique::SetEcho()
{
	this->DSPEcho->remove();
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_ECHO, &DSPEcho);
	this->mySys.channel->addDSP(DSPEcho, 0);
	DSPEcho->setParameter(FMOD_DSP_ECHO_DELAY, this->myUI->vSlider_Echo->value());
}

void InterfaceLogique::SetPitch()
{
	this->DSPPitch->remove();
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &DSPPitch);
	this->mySys.channel->addDSP(DSPPitch, 0);
	DSPPitch->setParameter(FMOD_DSP_PITCHSHIFT_PITCH, this->myUI->vSlider_Pitch->value()/50);
}

void InterfaceLogique::SetFlange()
{
	this->DSPFlange->remove();
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_FLANGE, &DSPFlange);
	this->mySys.channel->addDSP(DSPFlange, 0);
	this->DSPFlange->setParameter(FMOD_DSP_FLANGE_DEPTH, this->myUI->vSlider_Flange->value());
}

void InterfaceLogique::RemoveSong(SoundInfo* toRemove)
{
	this->mySys.StopMusic();
	this->isPlaying = false;
	for (list<SoundInfo*>::iterator it = currentList.begin(); it != currentList.end(); it++)
	{
		if(toRemove == *it)
		{
			currentList.erase(it);
			RemoveSong(toRemove);
			break;
		}
	}
}

void InterfaceLogique::RemoveCollectionMember(Playlist* toRemove)
{
	for (vector<SoundInfo*>::iterator it = toRemove->GetPlayList().begin(); it != toRemove->GetPlayList().end(); it++)
	{
		RemoveSong(*it);
	}
}
void InterfaceLogique::SetTremolo()
{
	this->DSPTremolo->remove();
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &DSPTremolo);
	this->mySys.channel->addDSP(DSPTremolo, 0);
	this->DSPTremolo->setParameter(FMOD_DSP_TREMOLO_DEPTH, (float)this->myUI->vSlider_Tremolo->value()/100);
}

void InterfaceLogique::SetDistortion()
{
	this->DSPDistortion->remove();
	this->mySys.GetFmodSys()->createDSPByType(FMOD_DSP_TYPE_DISTORTION, &DSPDistortion);
	this->mySys.channel->addDSP(DSPDistortion, 0);
	this->DSPDistortion->setParameter(FMOD_DSP_DISTORTION_LEVEL, (float)this->myUI->vSlider_Distortion->value()/100);
}