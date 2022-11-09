#include <iostream>
#include "./include/openhttest.hpp"

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

void hashtable::insert(int inKey, std::string inLastname)
{
    size_t i = 0;
    bool found = 0;
    int SN = inKey;
    int newSN = primaryHashFunction(SN);

    // Search first to see if it already exists
    while (t[newSN].getKey() == -1 || t[newSN].getKey() != 0)
    {
        if (t[newSN].getKey() == inKey)
        {
            found = 1;
            break;
        }
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        ++i;
        if (i == m)
        {
            found = 0;
            break;
        }
    }

    if (found == 1)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    SN = inKey;
    newSN = primaryHashFunction(SN);

    while (t[newSN].getLastname() != "" && t[newSN].getKey() > 0)
    {
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        if (primaryHashFunction(SN) == newSN)
        {
            std::cout << "failure" << std::endl;
            return;
        }
    }
    t[newSN].setHashitem(SN, inLastname);
    std::cout << "success" << std::endl;
}

void hashtable::search(int inKey)
{
    size_t i = 0;
    int SN = inKey;
    int newSN = primaryHashFunction(SN);
    // while (t[newSN].getKey() != inKey)
    // {
    //     if (t[newSN].getKey() == 0)
    //     {
    //         std::cout << "failure" << std::endl;
    //         return;
    //     }
    //     newSN = (newSN + secondaryHashFunction(SN)) % getSize();
    //     if ((primaryHashFunction(SN)) == newSN)
    //     {
    //         std::cout << "not found" << std::endl;
    //         return;
    //     }
    // }
    // std::cout << "found " << t[newSN].getLastname() << " in " << newSN << std::endl;

    while (t[newSN].getKey() == -1 || t[newSN].getKey() != 0)
    {
        if (t[newSN].getKey() == inKey)
        {
            std::cout << "found " << t[newSN].getLastname() << " in " << newSN << std::endl;
            return;
        }
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        ++i;
        if (i == m)
        {
            std::cout << "not found" << std::endl;
            return;
        }
    }
    std::cout << "not found" << std::endl;
}

void hashtable::del(int inKey)
{
    int SN = inKey;
    int newSN = primaryHashFunction(SN);
    while (t[newSN].getKey() != inKey)
    {
        if (t[newSN].getKey() == 0)
        {
            std::cout << "failure" << std::endl;
            return;
        }
        newSN = (newSN + secondaryHashFunction(SN)) % getSize();
        if ((SN % getSize()) == newSN)
        {
            std::cout << "failure" << std::endl;
            return;
        }
    }
    // a negative key means it is deleted
    t[newSN].setHashitem(-1, "");
    std::cout << "success" << std::endl;
}

size_t hashtable::getSize()
{
    return m;
}

