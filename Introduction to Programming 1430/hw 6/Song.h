#pragma once

#include <string>
using namespace std;

class Song {
private:
	string Title;
	string Artist;
	string Album;
	int Year;
	int PlayTime;

public:
   // Add declaration for constructors, accessors and mutators
	Song();
	Song(string Title, string Artist, string Album, int Year, int PlayTime);
	void setTitle(string TITLE);
	void setArtist(string ARTIST);
	void setAlbum(string ALBUM);
	void setYear(int YEAR);
	void setPlayTime(int PLAYTIME);
	string getTitle() const;
	string getArtist() const;
	string getAlbum() const;
	int getYear() const;
	int getPlayTime() const;
	void Play();
	bool operator==(const Song& song);
   // Add declaration for overloading the == operator
};