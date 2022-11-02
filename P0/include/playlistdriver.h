#pragma once
#include <string>

#define ERR_T 0;
#define NOERR_T 1;

typedef bool errCode;

class song
{
    public:
        std::string getName() const;
        std::string getArtist() const;

        void set(std::string inName, std::string inArtist);
        song();
        song(std::string inName, std::string inArtist);
        ~song();
    private:
        std::string name;
        std::string artist;
};

class playlist
{
    public:
        errCode addSong(std::string inName, std::string inArtist);
        errCode removeSong(size_t inID);
        void playSong(size_t inID);

        playlist(size_t inN);
        ~playlist();
    private:
        size_t N;
        size_t id;
        song* arr;
};
