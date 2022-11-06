#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include "./include/openhttest.hpp"

void hashitem::setHashitem(int inKey, std::string inLastname)
{
    key = inKey;
    lastname = inLastname;
}

std::string hashitem::getLastname()
{
    return lastname;
}

hashtable::hashtable(size_t inm)
{
    m = inm;
    t = new hashitem[m];
}

hashtable::~hashtable()
{
    delete [] t;
}

int hashtable::primaryHashFunction(int inKey)
{
    return inKey % m;
}

int hashtable::secondaryHashFunction(int inKey)
{
    return (inKey / m) % 2 ? (inKey / m) % m : (inKey / m) % m + 1;
}

bool hashtable::insert(int inKey, std::string inLastname)
{
    int SN = inKey;
    int newSN = primaryHashFunction(SN);
    while (t[newSN].getLastname() != "" && t[newSN].key != 0)
    {
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        if ((SN % getSize()) == newSN)
        {
            std::cout << "failure" << std::endl;
            return 0;
        }
    }
    t[newSN].setHashitem(SN, inLastname);
    std::cout << "success" << std::endl;
    return 0;
}

bool hashtable::search(int inKey)
{
    int SN = inKey;
    int newSN = primaryHashFunction(SN);
    while (t[newSN].key != inKey)
    {
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        if ((primaryHashFunction(SN)) == newSN)
        {
            std::cout << "failure" << std::endl;
            return 0;
        }
    }
    std::cout << "found " << t[newSN].getLastname() << " in " << newSN << std::endl;
    return 0;
}

bool hashtable::del(int inKey)
{
    bool failure;
    int SN = inKey;
    int newSN = primaryHashFunction(SN);
    while (t[newSN].key != inKey)
    {
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        if ((SN % getSize()) == newSN)
        {
            std::cout << "failure" << std::endl;
            failure = 1;
            break;
        }
    }
    if (!failure)
    {
        t[newSN].setHashitem(0, "");
        std::cout << "success" << std::endl;
    }
    return 0;
}

size_t hashtable::getSize()
{
    return m;
}

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
    }
    delete ht;
}

