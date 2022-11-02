#pragma once

#include <string>

class Node
{
    public:
        std::string name;
        std::string url;
        Node* next;
        Node* prev;

        Node(std::string inName, std::string inURL);
        ~Node();
};

class DoublyLinkedList
{
    protected:
        Node* head;
        Node* tail;
        size_t id;
        size_t N;
    public:
        DoublyLinkedList(Node* inHead, Node* inTail, size_t inN) : head(inHead), tail(inTail), id(0), N(inN) {};
        ~DoublyLinkedList();
};

class Deque : public DoublyLinkedList
{
    public:
        void push_front(Node* inFront);
        void push_back(Node* inBack);
        void pop_front();
        void pop_back();
        void clear();
        size_t size() const;
        Node* front() const;
        Node* back() const;
        bool empty();
        void find(std::string inName);
        void print();
        Deque(Node* inHead, Node* inTail, size_t inN) : DoublyLinkedList(inHead, inTail, inN) {};
        ~Deque();
};

