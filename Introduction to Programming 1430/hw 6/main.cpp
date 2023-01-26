#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"

using namespace std;

int main()
{
	
	string filename;
	int numsongs;
   char mode;
   
	cout << "Enter number of Songs " << endl;
	cin >> numsongs;

	cout << "Enter filename with information about the songs" << endl;
	cin >> filename;
	
	cout << "Enter mode of operation  (r : play Random, l: play PlayList, b: play both ) " <<endl;
	cin >> mode;

	MusicLibrary mylibrary(numsongs);
	mylibrary.readSongsFromFile(filename);

   if ( mode == 'r' || mode == 'b' ) {
	   mylibrary.playRandom(); 
   }
   
   if ( mode == 'l' || mode == 'b' ) {
    	for (int i = numsongs-1; i >= 0; i--) {
	    	mylibrary.addSongToPlayList(i);
	   }

    	mylibrary.playPlaylist();
   }

	return 0;
}