#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "./include/orderedhttest.hpp"

hashitem::hashitem(int inKey, std::string inLastname)
{
    key = inKey;
    lastname = inLastname;
}

hashitem::~hashitem()
{
    key = 0;
    lastname = "";
}

void hashitem::setHashitem(int inKey, std::string inLastname)
{
    key = inKey;
    lastname = inLastname;
}

std::string hashitem::getLastname()
{
    return lastname;
}

int hashtable::primaryHashFunction(int inKey)
{
    return inKey % m;
}

bool hashtable::insert(int inKey, std::string inLastname)
{
    int newSN = primaryHashFunction(inKey);
    hashitem *temp = new hashitem(inKey, inLastname);
    t[newSN].push_back(*temp);
    std::cout << "success" << std::endl;
    // Sort vector
    return 0;
}

bool hashtable::search(int inKey)
{
    int newSN = primaryHashFunction(inKey);
    for (size_t it = 0; it < t[newSN].size(); ++it)
    {
        if(t[newSN].at(it).key == inKey)
        {
            std::cout << "found " << t[newSN].at(it).getLastname() << " in " << newSN << std::endl;
            return 0;
        }
    }

    std::cout << "failure" << std::endl;
    return 0;
}

bool hashtable::del(int inKey)
{
    int newSN = primaryHashFunction(inKey);
    for (size_t it = 0; it < t[newSN].size(); ++it)
    {
        if(t[newSN].at(it).key == inKey)
        {
            t[newSN].at(it).setHashitem(0, "");
            std::cout << "success" << std::endl;
            return 0;
        }
        std::cout << "failure" << std::endl;
    }
    return 0;
}

void hashtable::print(size_t p)
{
    for (size_t i = 0; i < t[p].size(); ++i)
    {
        std::cout << t[p].at(i).key << " ";
    }
    std::cout << std::endl;
}

hashtable::hashtable(size_t inm)
{
    t = new std::vector<class hashitem>[inm];
    m = inm;
}

hashtable::~hashtable()
{
    for (size_t i = 0; i < m; ++i)
    {
        for (int j = t[i].size(); j > 0; --j)
        {
            delete &t[i].at(j);
        }
    }
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
