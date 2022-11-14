#include <iostream>
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

int hashitem::getKey()
{
    return key;
}

void hashitem::setKey(int inKey)
{
    key = inKey;
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

void hashtable::insert(int inKey, std::string inLastname)
{
    int newSN = primaryHashFunction(inKey);
    hashitem *temp = new hashitem(inKey, inLastname);

    for (size_t i = 0; i < t[newSN].size(); ++i)
    {
        if (inKey > t[newSN][i]->getKey())
        {
            t[newSN].insert(t[newSN].begin() + i, temp);
            std::cout << "success" << std::endl;
            return;
        }
        else if (inKey == t[newSN][i]->getKey())
        {
            delete temp;
            std::cout << "failure" << std::endl;
            return;
        }
    }
    t[newSN].push_back(temp);
    std::cout << "success" << std::endl;
}

void hashtable::search(int inKey)
{
    int newSN = primaryHashFunction(inKey);
    for (size_t it = 0; it < t[newSN].size(); ++it)
    {
        if(t[newSN].at(it)->getKey() == inKey)
        {
            std::cout << "found " << t[newSN].at(it)->getLastname() << " in " << newSN << std::endl;
            return;
        }
    }
    std::cout << "not found" << std::endl;
}

void hashtable::del(int inKey)
{
    int newSN = primaryHashFunction(inKey);
    size_t i = 0;
    for (i = 0; i < t[newSN].size(); ++i)
    {
        if(t[newSN][i]->getKey() == inKey)
        {
            std::cout << "success" << std::endl;
            hashitem* temp = t[newSN][i];
            t[newSN].erase(t[newSN].begin() + i);
            delete temp;
            return;
        }
    }
    std::cout << "failure" << std::endl;
}

void hashtable::print(size_t p)
{
    if (t[p].size() == 0)
    {
        std::cout << "chain is empty" << std::endl;
        return;
    }

    for (size_t i = 0; i < t[p].size(); ++i)
    {
        std::cout << t[p].at(i)->getKey() << " ";
    }
    std::cout << std::endl;
}

hashtable::hashtable(size_t inm)
{
    t = new std::vector<class hashitem *>[inm];
    m = inm;
}

hashtable::~hashtable()
{
    for (size_t i = 0; i < m; ++i)
    {
        for (int j = 0; j > t[i].size(); ++j)
        {
            delete &t[i][j];
        }
    }
    delete [] t;
}

