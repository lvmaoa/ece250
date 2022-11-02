#include <cstdlib>
#include <iostream>
#include <string>
#include "./include/playlistdriver.h"

int main()
{
    char input;
    std::string name;

    playlist myPlaylist = playlist(1);
    song mySong = song();
    size_t delimit;

    errCode ret_code;

    while (std::cin >> input >> name)
    {
        switch (input)
        {
            case 'e':
                myPlaylist.eraseSong(std::stoi(name));
                break;
            case 'i':
                // add song
                delimit = name.find(";");
                mySong.name = name.substr(0, delimit);
                mySong.artist = name.substr(delimit, name.length());
                ret_code = myPlaylist.addSong(mySong);
                break;
            case 'm':
                // change size
                myPlaylist.changePlaylistSize(std::stoi(name));
                break;
            default:
            case 'p':
                // play song
                myPlaylist.playSong(std::stoi(name));
                break;
        }
        myPlaylist.printSong();
    }

}

