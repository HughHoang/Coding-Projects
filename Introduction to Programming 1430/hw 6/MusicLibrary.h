#pragma once

#include <string>
#include "Song.h"

using namespace std;

class MusicLibrary
{
private:
	int maxSongs;
	int numSongs;    // number of Songs in library
	Song* mySongs;   // dynamic array storing all Songs

	int numSongsPlayList; // number of Songs in Playlist
	Song** playList;      // dynamic array of pointers to Songs
	
public:
	MusicLibrary(int maxsongs);
	MusicLibrary(MusicLibrary& other);
	~MusicLibrary();

   int getnumSongs();
   int getmaxSongs();
   int getnumSongsPlayList();
   
	bool addSong(string title, string artist, string album, int year, int time);
	bool addSong(Song& song);
	void readSongsFromFile(string filename);
	
	bool addSongToPlayList(int pos);
	void playRandom();
	void playPlaylist();
	
};
