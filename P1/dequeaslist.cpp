#include "./include/dequeaslistdriver.hpp"

#include <iostream>

Node::Node(std::string inName, std::string inURL)
{
    name = inName;
    url = inURL;
    next = prev = nullptr;
}

Node::~Node()
{
    name = url = "";
    next = prev = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    head = tail = nullptr;
}

void Deque::push_front(Node* inFront)
{
    if (id >= N)
    {
        pop_back();
    }
    else
    {
        std::cout << "success" << std::endl;
    }
    if (head == nullptr)
    {
        head = tail = inFront;
    }
    else 
    {
        inFront->next = head;
        head->prev = inFront;
        head = inFront;
    }
    ++id;
}

void Deque::push_back(Node* inBack)
{
    if (id >= N)
    {
        pop_front();
    }
    else
    {
        std::cout << "success" << std::endl;
    }
    if (tail == nullptr)
    {
        head = tail = inBack;
    }
    else
    {
        inBack->prev = tail;
        tail->next = inBack;
        tail = inBack;
    }
    ++id;
}

void Deque::pop_front()
{
    if (id == 0)
    {
        std::cout << "failure" << std::endl;
        return;
    }
    else if (id == 1)
    {
        delete head;
        head = tail = nullptr;
        --id;
        std::cout << "success" << std::endl;
        return;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    --id;
    std::cout << "success" << std::endl;
}

void Deque::pop_back()
{
    if (id == 0)
    {
        std::cout << "failure" << std::endl;
        return;
    }
    else if (id == 1)
    {
        delete tail;
        head = tail = nullptr;
        --id;
        std::cout << "success" << std::endl;
        return;
    }

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    --id;
    std::cout << "success" << std::endl;
}

void Deque::clear()
{
    while(head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
    id = 0;
    std::cout << "success" << std::endl;
}

size_t Deque::size() const
{
    return id;
}

Node* Deque::front() const
{
    if(id == 0)
    {
        std::cout << "failure" << std::endl;
        return nullptr;
    }
    return head;
}

Node* Deque::back() const
{
    if(id == 0)
    {
        std::cout << "failure" << std::endl;
        return nullptr;
    }
    return tail;
}

bool Deque::empty()
{
    return id == 0;
}

void Deque::find(std::string inName)
{
    if (empty())
    {
        std::cout << "not found " << inName << std::endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr)
    {
        if (temp->name == inName)
        {
            std::cout << "found " << temp->name << " " << temp->url << std::endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    std::cout << "not found " << inName << std::endl;
}

void Deque::print()
{
    if (empty())
    {
        std::cout << "deque is empty" << std::endl;
        return;
    }

    Node* temp = tail;
    while (temp != nullptr)
    {
        std::cout << temp->name << " " << temp->url << std::endl;
        temp = temp->prev;
    }
}

Deque::~Deque()
{
    while(head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    id = 0;
}

