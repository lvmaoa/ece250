#include "triedriver.hpp"
#include <iostream>

Node::Node()
{
    parent = nullptr;
    visited = isEOW = 0;
    for (int i = 0; i < 26; ++i)
    {
        children[i] = nullptr;
    }
}

Node::~Node()
{
    if (parent != nullptr)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (parent->children[i] == this)
            {
                parent->children[i] = nullptr;
            }
        }
    }
    parent = nullptr;
    for (int i = 0; i < 26; ++i)
    {
        children[i] = nullptr;
    }
}

bool Node::getEOW()
{
    return isEOW;
}

bool Node::getVisited()
{
    return visited;
}

Node *Node::getParent()
{
    return parent;
}

void Node::setParent(Node* inParent)
{
    parent = inParent;
}

void Node::setEOW(bool inEOW)
{
    isEOW = inEOW;
}

void Node::setVisited(bool isVisited)
{
    visited = isVisited;
}

Trie::Trie()
{
    head = new Node();
    N = 0;
}

Trie::~Trie()
{
    clear(head);
    delete head;
}

bool Trie::insert(std::string inKey)
{
    if (search(inKey))
    {
        return 0;
    }

    Node *curr = head;
    for (int i = 0; i < inKey.length(); ++i)
    {
        if (curr->children[inKey[i] - 'a'] == nullptr)
        {
            curr->children[inKey[i] - 'a'] = new Node();
            curr->children[inKey[i] - 'a']->setParent(curr);
        }

        curr = curr->children[inKey[i] - 'a'];
    }
    curr->setEOW(1);
    N++;
    return 1;
}

bool Trie::search(std::string inKey)
{
    Node *curr = head;
    for (int i = 0; i < inKey.length(); ++i)
    {
        if (curr->children[inKey[i] - 'a'] != nullptr)
        {
            curr = curr->children[inKey[i] - 'a'];
        }
        else 
        {
            // std::cout << "not found" << std::endl;
            return false;
        }
    }
    if (curr->getEOW())
    {
        // std::cout << "found word" << std::endl;
        return true;
    }
    // std::cout << "not found" << std::endl;
    return false;
}

void Trie::clearVisited(Node *inNode)
{
    for (int i = 0; i < 26; ++i)
    {
        if (inNode->children[i] != nullptr)
        {
            inNode->children[i]->setVisited(0);
            clearVisited(inNode->children[i]);
        }
    }
}

void Trie::print(std::string out, std::string base, Node* inNode)
{
    for (int i = 0; i < 26; ++i)
    {
        if (inNode == nullptr)
        {
            return;
        }
        if (inNode->children[i] != nullptr && inNode->children[i]->getVisited() == 0)
        {
            inNode->children[i]->setVisited(1);
            out += 'a' + i;
            if (inNode->children[i]->getEOW())
            {
                std::cout << base << out << " ";
            }
            print(out, base, inNode->children[i]);
            out.pop_back();
        }
    }

    if (out.length() == 0 || out == "")
    {
        return;
    }
    out.pop_back();
    // print(out, inNode->parent);
}

void Trie::printt()
{
    if (empty())
    {
        return;
    }
    print("", "", head);
    clearVisited(head);
    std::cout << std::endl;
}

bool Trie::erase(std::string inKey)
{
    if (!search(inKey))
    {
        // failed
        return 0;
    }

    Node *curr = head;
    for (int i = 0; i < inKey.length(); ++i)
    {
        curr = curr->children[inKey[i] - 'a'];
    }
    curr->setEOW(0);

    for (int i = inKey.length() - 1; i >= 0; --i)
    {
        // if has children we can't delete it 
        for (int j = 0; j < 26; ++j)
        {
            if (curr->children[j] != nullptr)
            {
                --N;
                return 1;
            }
        }
        // if EOW then we stop
        if (curr->getEOW() && i != (inKey.length() - 1))
        {
            --N;
            return 1;
        }
        Node *temp = curr;
        curr = curr->getParent();
        delete temp;
    }
    --N;
    return 1;
}

bool Trie::empty()
{
    for (int i = 0; i < 26; ++i)
    {
        if (head->children[i] != nullptr)
        {
            return false;
        }
    }
    return true;
}

void Trie::spellcheck(std::string inWord)
{
    std::string word = "";
    if (search(inWord))
    {
        std::cout << "correct" << std::endl;
        return;
    }

    Node *curr = head;
    int i = 0;
    for (; i < inWord.length(); ++i)
    {
        if (curr->children[inWord[i] - 'a'] != nullptr)
        {
            word += inWord[i];
            curr = curr->children[inWord[i] - 'a'];
        }
        else
        {
            break;
        }
    }
    if (i >= inWord.length() - 1)
    {
        print("", word, curr);
        clearVisited(head);
    }
    std::cout << std::endl;
}

void Trie::clear(Node *inNode)
{
    N = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (inNode->children[i] != nullptr)
        {
            clear(inNode->children[i]);
        }
    }

    if (inNode != head)
    {
        delete inNode;
    }
}

Node* Trie::getHead()
{
    return head;
}

int Trie::getN()
{
    return N;
}
