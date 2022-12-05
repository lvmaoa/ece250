#include "triedriver.hpp"
#include <iostream>
#include <fstream>

int main ()
{
    std::string cmd, addword;

    Trie myTrie;

    while (std::cin >> cmd)
    {
        if (cmd == "load")
        {
            std::ifstream fin("corpus.txt");
            while (fin >> addword)
            {
                myTrie.insert(addword);
            }
            std::cout << "success" << std::endl;
        }
        else if (cmd == "i")
        {
            std::cin >> addword;
            try
            {
                for (int i = 0; i < addword.length(); ++i)
                {
                    if (addword[i] < 'a' || addword[i] > 'z')
                    {
                        throw illegal_exception();
                    }
                }
                if (myTrie.insert(addword))
                {
                    std::cout << "success" << std::endl;
                }
                else 
                {
                    std::cout << "failure" << std::endl;
                }
            }
            catch (illegal_exception e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (cmd == "s")
        {
            std::cin >> addword;
            try
            {
                for (int i = 0; i < addword.length(); ++i)
                {
                    if (addword[i] < 'a' || addword[i] > 'z')
                    {
                        throw illegal_exception();
                    }
                }
                if (myTrie.search(addword))
                {
                    std::cout << "found " << addword << std::endl;
                }
                else 
                {
                    std::cout << "not found" << std::endl;
                }
            }
            catch (illegal_exception e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (cmd == "e")
        {
            std::cin >> addword;
            try
            {
                for (int i = 0; i < addword.length(); ++i)
                {
                    if (addword[i] < 'a' || addword[i] > 'z')
                    {
                        throw illegal_exception();
                    }
                }
                if (myTrie.erase(addword))
                {
                    std::cout << "success" << std::endl;
                }
                else 
                {
                    std::cout << "failure" << std::endl;
                }
            }
            catch (illegal_exception e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (cmd == "p")
        {
            myTrie.printt();
        }
        else if (cmd == "spellcheck")
        {
            std::cin >> addword;
            myTrie.spellcheck(addword);
        }
        else if (cmd == "empty")
        {
            std::cout << "empty " << myTrie.empty() << std::endl; 
        }
        else if (cmd == "clear")
        {
            myTrie.clear(myTrie.getHead());
            std::cout << "success" << std::endl;
        }
        else if (cmd == "size")
        {
            std::cout << "number of words is: " << myTrie.getN() << std::endl;
        }
        else if (cmd == "exit")
        {
            break;
        }
    }

    return 0;
}

