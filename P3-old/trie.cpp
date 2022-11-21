#include <cctype>
#include <exception>
#include <iostream>
#include "trie.h"

Trie::Trie()
{
    isEOW = false;

    for (int i = 0; i < 26; i++)
    {
        children[i] = nullptr;
        visited = false;
    }
}

Trie::~Trie()
{
}

void Trie::setEOW(bool inEOW)
{
    isEOW = inEOW;
}

bool Trie::getEOW()
{
    return isEOW;
}

void Trie::setData(char inData)
{
    data = inData;
}

char Trie::getData()
{
    return data;
}

bool Trie::isEmpty()
{
    if (!std::isblank(data))
    {
        return false;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (children[i])
        {
            return false;
        }
    }
    return true;
}

void Trie::insert(std::string inKey)
{
    Trie *curr = this;
    for (int i = 0; i < inKey.length(); ++i)
    {
        if (curr->children[inKey[i] - 'a'] == nullptr)
        {
            curr->children[inKey[i] - 'a'] = new Trie();
        }

        curr = curr->children[inKey[i] - 'a'];
    }
    curr->isEOW = 1;
}

bool Trie::search(std::string inKey)
{
    if (this == nullptr)
    {
        return false;
    }

    Trie *curr = this;
    for (int i = 0; i < inKey.length(); ++i)
    {
        curr = curr->children[inKey[i] - 'a'];

        if (curr == nullptr)
        {
            return false;
        }
    }

    return curr->isEOW;
}

Trie* Trie::erase(Trie *inTrie, std::string inKey, int depth)
{
    if (!inKey.length())
    {
        // failure
    }

    if (depth == inKey.length())
    {
        // success
        delete inTrie;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (inTrie[i].data == inKey[depth])
        {
            // success
            erase(&inTrie[i], inKey, depth + 1);
        }
    }

    // failure

    return inTrie;
}

void Trie::DFS(Trie *inTrie, std::string out, int depth)
{
    if (!inTrie->visited)
    {
        inTrie->visited = 1;
        out += inTrie->data;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (!inTrie[i].isEmpty())
        {
            if (!inTrie[i].visited)
            {
                DFS(&inTrie[i], out, depth + 1);
            }
            else
            {
                std::cout << out << " ";
                out.pop_back();
            }
        }
    }
}

void Trie::print()
{
    std::string temp = "";
    Trie *curr = this;

    DFS(curr, temp, 0);
}

