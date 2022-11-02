#pragma once
#include <string>

#define ERR_T 0
#define NO_ERR_T 1

typedef bool errCode;

class song 
{
    public:
        std::string name;
        std::string artist;

        song copy();

        song();
        song(std::string inName, std::string inArtist);
        ~song();
    private:
};

class playlist
{
    public:
        size_t N;
        size_t id;
        song* arr;

        size_t size();
        errCode addSong(song inSong);
        errCode changePlaylistSize(size_t inN);
        void eraseSong(size_t inID);
        song playSong(size_t inID);
        void printSong();

        playlist(size_t inN);
        ~playlist();
        // Create a cpy func
        // https://stackoverflow.com/questions/3021333/can-i-use-memcpy-in-c-to-copy-classes-that-have-no-pointers-or-virtual-functio
        // memcpy( a1, a2, count * sizeof(Data) );
    private:
};
