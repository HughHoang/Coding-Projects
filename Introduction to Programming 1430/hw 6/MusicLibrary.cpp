#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary(int numsongs):numSongs(numsongs)
{
	numSongs= 0;
	numSongsPlayList = 0;
	maxSongs = numsongs;
	Song* mySongs1 = new Song[maxSongs];
	Song** playList1 = new Song * [maxSongs];
	mySongs = mySongs1;
	playList = playList1;
}
MusicLibrary::MusicLibrary(MusicLibrary& other)
{
	maxSongs = other.maxSongs;
	numSongs = other.numSongs;
	numSongsPlayList = other.numSongsPlayList;
	mySongs = new Song[other.maxSongs];
	playList = new Song*[other.maxSongs];

	for (int i = 0; i < other.maxSongs; i++)  {
		mySongs[i] = other.mySongs[i];
	}
	for (int i = 0; i < other.maxSongs; i++) {
		playList[i] = other.playList[i];
	}
}

MusicLibrary::~MusicLibrary()
{
	delete[] mySongs;
	delete[] playList;
}

int MusicLibrary::getnumSongs()
{
   return numSongs;
}
int MusicLibrary::getmaxSongs()
{
   return maxSongs;
}
int MusicLibrary::getnumSongsPlayList()
{
   return numSongsPlayList;
}

bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
	if (numSongs == maxSongs) {
		cout << "Could not add song to library. Library is full" << endl;
		return false;
	}
	mySongs[numSongs].setTitle(title);
	mySongs[numSongs].setArtist(artist);
	mySongs[numSongs].setAlbum(album);
	mySongs[numSongs].setYear(year);
	mySongs[numSongs].setPlayTime(time);
	numSongs++;

	return true;
}
bool MusicLibrary::addSong(Song& song)
{
	if (numSongs == maxSongs) {
		cout << "Could not add Ssong to library. Library is full" << endl;
		return false;
	}
	mySongs[numSongs] = song;
	numSongs++;

	return true;
}

void MusicLibrary::readSongsFromFile(string filename)
{

	ifstream input;
	input.open(filename);
	bool cont = true;

	if (input.is_open()) {
		string line;
		while ( getline(input, line) && cont ) {
			string title, artist, album;
			string s_year, s_time;
			int year;
			int time;
			istringstream inSS(line);

			getline(inSS, title, ',');
			getline(inSS, artist, ',');
			getline(inSS, album, ',');
			getline(inSS, s_year, ',');
			getline(inSS, s_time);

			year = stoi(s_year);
			time = stoi(s_time);
			cont = addSong(title, artist, album, year, time);
		};
	}	
	else {
	   cout << "could not open file " << filename << endl;
	}
}

void MusicLibrary::playRandom() {
	int count = numSongs-1;
	int count2 = 0;
	for (int i = 0; i < numSongs-1; i++) {
		if (i % 2 == 0) {
			mySongs[count2].Play();
			count2++;
		}
		if (i % 2 == 0) {
			mySongs[count].Play();
			count--;
		}
	}
	if (count % 2 == 0) {
		mySongs[count].Play();
	}
}


bool MusicLibrary::addSongToPlayList(int pos)
{
	if (numSongsPlayList == maxSongs) {
		cout << "Could not add Song to library. Library is full" << endl;
		return false;
	}
	playList[numSongsPlayList] = &mySongs[pos];
	numSongsPlayList++;

	return true;
}

void MusicLibrary::playPlaylist(){
	for (int i = 0; i < numSongsPlayList; i++) {
		playList[i]->Play();
	}
}