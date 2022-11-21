#include "trie.h"
#include <iostream>
#include <fstream>

int main ()
{
    std::ifstream fin("corpus.txt");
    std::string cmd, addword;

    Trie *myTrie = new Trie();

    while (std::cin >> cmd)
    {
        if (cmd == "load")
        {
            while (fin >> addword)
            {
                myTrie->insert(addword);
            }
            std::cout << "success" << std::endl;
        }
        else if (cmd == "i")
        {
            std::cin >> addword;
            myTrie->insert(addword);
        }
        else if (cmd == "e")
        {
            std::cin >> addword;
            myTrie->erase(myTrie, addword, 0);
        }
        else if (cmd == "p")
        {
            myTrie->print();
        }
        else if (cmd == "exit")
        {
            break;
        }
    }

    delete myTrie;
    return 0;
}
