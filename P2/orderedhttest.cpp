#include <iostream>
#include "./include/orderedhttest.hpp"

int main ()
{
    std::string command = "";
    std::cin >> command;
    if (command == "m") { }
    int N;
    std::cin >> N;
    hashtable *ht = new hashtable(N);
    std::cout << "success" << std::endl;

    while (1)
    {
        std::cin >> command;
        if (std::cin.eof())
        {
            break;
        }
        if (command == "i")
        {
            int inSN;
            std::string inLastname;
            std::cin >> inSN;
            std::cin >> inLastname;
            ht->insert(inSN, inLastname);
        }
        else if (command == "s")
        {
            int inSN;
            std::cin >> inSN;
            ht->search(inSN);
        }
        else if (command == "d")
        {
            int inSN;
            std::cin >> inSN;
            ht->del(inSN);
        }
        else if (command == "p")
        {
            size_t p;
            std::cin >> p;
            ht->print(p);
        }
    }
    delete ht;
}

