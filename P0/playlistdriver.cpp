#include <iostream>
#include <ostream>
#include <string>
#include "./include/playlistdriver.h"

int main()
{
    std::string name;
    size_t delimit;

    // Set size
    // We are garunteed the first command will set a size
    getline(std::cin, name);
    name = name.substr(2, name.size() - 2);
    playlist *myPlaylist = new playlist(std::stoi(name));
    std::cout << "success" << std::endl;

    // Get the next command
    while (getline(std::cin, name))
    {
        // If new line (or invalid command), exit
        if (name.length() < 2)
        {
            break;
        }
        // Figure out which command was inputted
        switch (name[0]) {
            case 'e':
                // Erase song
                if (myPlaylist->removeSong(name[2] - '0'))
                    std::cout << "success" << std::endl;
                else
                    std::cout << "can not erase " << name[2] << std::endl;
                break;
            case 'i':
                // Add song
                name = name.substr(2, name.size() - 2);
                delimit = name.find(";");
                if (myPlaylist->addSong(name.substr(0, delimit), name.substr((delimit + 1))))
                    std::cout << "success\n";
                else
                    std::cout << "can not insert " << name << std::endl;
                break;
            case 'p':
                // Play song
                myPlaylist->playSong(name[2] - '0');
                break;
        }
    }
    return 0;
}

