#include "./include/playlistdriver.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <map>

// For hashmap approach
// std::map<std::string, bool> hashmap;

song::song()
{
    name = "";
    artist = "";
}

song::song(std::string inName, std::string inArtist)
{
    name = inName;
    artist = inArtist;
}

song::~song()
{
    name = "";
    artist = "";
}

void song::set(std::string inName, std::string inArtist)
{
    name = inName;
    artist = inArtist;
}

std::string song::getName() const
{
    return name;
}

std::string song::getArtist() const
{
    return artist;
}

playlist::playlist(size_t inN)
{
    N = inN;
    id = 0;
    arr = new song[N];
}

playlist::~playlist()
{
    delete [] arr;
    arr = nullptr;
}

errCode playlist::addSong(std::string inName, std::string inArtist)
{
    // Check if song is a banned song
    if ((inName == "Muskrat Love" && inArtist == "Captain and Tennille") || (inName == "My Heart Will Go On") || (id >= N))
    {
        return ERR_T
    }

    // Check if song is in list
    for (size_t i = 0; i < N; ++i)
    {
        if (arr[i].getName() == inName && arr[i].getArtist() == inArtist)
        {
            return ERR_T;
        }
    }
    
    arr[id].set(inName, inArtist);
    ++id;
    return NOERR_T;

    // Check if song is already inside the array (hashmap method)
    // if (hashmap.find(inName + inArtist) != hashmap.end())
    // {
    //     // Duplicate song
    //     return ERR_T
    // }
    // else 
    // {
    //     arr[id].set(inName, inArtist);
    //     ++id;
    //     hashmap[inName + inArtist] = 1;
    //     return NOERR_T;
    // }
}

errCode playlist::removeSong(size_t inID)
{
    // if we were using a hashmap
    // hashmap.erase(arr[inID].name + arr[inID].artist);

    // Move all down by 1
    for (size_t i = inID; i < N - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    arr[N - 1].set("", "");

    // Reduce index 
    --id;
    return NOERR_T;
}

void playlist::playSong(size_t inID)
{
    // Check if there is a song at inID
    if (!arr[inID].getName().empty() && !arr[inID].getArtist().empty())
    {
        std::cout << "played " << inID << " " << arr[inID].getName() << ";" << arr[inID].getArtist() << std::endl;
    }
    else
    {
        std::cout << "can not play " << inID << "\n";
    }
}

