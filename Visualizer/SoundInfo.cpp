#include "SoundInfo.h"
#include <id3\tag.h>




SoundInfo::SoundInfo(string path)
{
	filePath = path;
	InitTag();
}


SoundInfo::~SoundInfo()
{
	
}

void SoundInfo::InitTag()
{
	ID3_Tag tag;
	tag.Link(filePath.c_str());

	ID3_Field* myField;
	ID3_Frame* myFrame = tag.Find(ID3FID_ALBUM);

   if (NULL != myFrame)
   {
	  myField = myFrame->GetField(ID3FN_TEXT);
	  album = myField->GetRawText();
   }
   else
   {
	   album = "Album inconnu";
   }

   myFrame = tag.Find(ID3FID_TITLE);
   if (NULL != myFrame)
   {
	  myField = myFrame->GetField(ID3FN_TEXT);
	  title = myField->GetRawText();
   }
   else
   {
	   title = filePath.substr(filePath.rfind('/')+1, filePath.length());
   }

   myFrame = tag.Find(ID3FID_LEADARTIST);
   if (NULL != myFrame)
   {
	  myField = myFrame->GetField(ID3FN_TEXT);
	  artist = myField->GetRawText();
   }
   else
   {
	   artist = "Artiste inconnu";
   }
   tag.Clear();
}

string SoundInfo::GetTitle()
{
	return title;
}

string SoundInfo::GetAlbum()
{
	return album;
}

string SoundInfo::GetArtist()
{
	return artist;
}

string SoundInfo::GetPath()
{
	return filePath;
}
