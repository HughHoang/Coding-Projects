#include <iostream>
#include "Song.h"
using namespace std;
void Song::Play()
{
	cout << "Playing "<< Title << " by " << Artist << " " << PlayTime << " seconds" << endl;
}

Song::Song() {
	PlayTime = 0;
	Year = 0;
}
Song::Song(string TITLE, string ARTIST, string ALBUM, int YEAR, int PLAYTIME){
	Title = TITLE;
	Artist = ARTIST;
	Album = ALBUM;
	Year = YEAR;
	PlayTime = PLAYTIME;
}
void Song::setTitle(string TITLE) {
	Title = TITLE;
}
void Song::setArtist(string ARTIST) {
	Artist = ARTIST;
}
void Song::setAlbum(string ALBUM) {
	Album = ALBUM;
}
void Song::setYear(int YEAR) {
	Year = YEAR;
}
void Song::setPlayTime(int PLAYTIME) {
	PlayTime = PLAYTIME;
}
string Song::getTitle() const {
	return Title;
}
string Song::getArtist() const {
	return Artist;
}
string Song::getAlbum() const {
	return Album;
}
int Song::getYear() const {
	return Year;
}
int Song::getPlayTime() const {
	return PlayTime;
}

bool Song::operator==(const Song& other) {
	return (other.getTitle() == Title) &&
		(other.getArtist() == Artist) &&
		(other.getAlbum() == Album);
}
