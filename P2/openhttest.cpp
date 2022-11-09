#include <iostream>
#include "./include/openhttest.hpp"

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
            int SN, newSN;
            std::string inLastname;
            std::cin >> SN;
            std::cin >> inLastname;
            ht->insert(SN, inLastname);
        }
        else if (command == "s")
        {
            int SN;
            std::cin >> SN;
            ht->search(SN);
        }
        else if (command == "d")
        {
            bool failure = 0;
            int SN, newSN;
            std::cin >> SN;
            ht->del(SN);
        }
        else if (command == "p")
        {
            for (int i = 0; i < ht->getSize(); ++i)
            {
                std::cout << "\"" << ht->t[i].getKey() << ", " << ht->t[i].getLastname() << "\" ";
            }
            std::cout << std::endl;
        }
    }
    delete ht;
}

