#include "./include/playlistdriver.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <pthread.h>

song song::copy()
{
    song temp = song();

    temp.name = name;
    temp.artist = artist;

    return temp;
}

song::song()
{
    name = "";
    artist = "";
}

song::song(std::string inName, std::string inArtist)
{
    name = inName;
    artist = inArtist;
};

song::~song()
{
};


size_t playlist::size()
{
    return (size_t)(sizeof *arr)/sizeof(class song);
}

errCode playlist::addSong(song inSong)
{
    if (id == N)
    {
        // full
        return ERR_T;
    }
    // check if song is a restricted entry
    for (size_t i = 0; i <= id; ++i)
    {
        // check if song is already in playlist
        if (inSong.name == arr[i].name || (inSong.name == "Muskrat Love" && inSong.artist == "Captain and Tennille") || inSong.name == "My Heart Will Go On")
        {
            return ERR_T;
        }
    }
    // add song to playlist
    arr[id] = inSong;
    ++id;
    return NO_ERR_T;
}

errCode playlist::changePlaylistSize(size_t inN)
{
    if (id >= inN)
    {
        // Must delete some songs first!
        return ERR_T;
    } else
    {
        // Change array size
        if (inN > N)
        {
            arr = (song *)realloc(arr, (sizeof(class song)) * inN);
            for (size_t i = N; i < inN - N; ++i)
            {
                new (arr + i) song();
            }
        } else
        {
            for (size_t i = inN; i < N; ++i)
            {
                arr[i].~song();
            }
            arr = (song *)realloc(arr, (sizeof(class song)) * inN);
        }
        return NO_ERR_T;
    }
}

void playlist::eraseSong(size_t inID)
{
    for (size_t i = inID + 1; i < N - 1; ++i)
    {
        arr[i] = arr[i+1];
    }
    arr[N - 1] = {"",""};
}

song playlist::playSong(size_t inID)
{
    return arr[inID];
}

void playlist::printSong()
{
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << i << ": name: " << arr[i].name << " artist: " << arr[i].artist << "\n";
    }
}

playlist::playlist(size_t inN)
{
    N = inN;
    id = 0;
    arr = (song *)malloc(sizeof(class song) *N);
    // handle exceptions or instead use new[]
    for (size_t i = 0; i < N; ++i)
    {
        new (arr + i) song();
    }
};

playlist::~playlist()
{
    // just good practice since I malloc a non POD type :)
    for (size_t i = 0; i < N; ++i)
    {
        arr[i].~song();
    }
    free(arr);
    arr = nullptr;
}

