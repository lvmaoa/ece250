#include <string>

class Node
{
    public:
        bool getEOW();
        bool getVisited();
        Node *getParent();

        void setParent(Node* inParent);
        void setEOW(bool inEOW);
        void setVisited(bool isVisited);

        Node *children[26];

        Node();
        ~Node();
    private:
        bool isEOW;
        bool visited;
        Node *parent;
};


class Trie
{
    public:
        bool insert(std::string inKey);
        bool search(std::string inKey);
        void clearVisited(Node *inNode);
        void print(std::string out, std::string base, Node* inNode);
        void printt();
        bool erase(std::string inKey);
        bool empty();
        void spellcheck(std::string inWord);
        void clear(Node *inNode);

        Node* getHead();
        int getN();

        Trie();
        ~Trie();
    private:
        Node *head;
        int N;
};

class illegal_exception
{
    public:
        illegal_exception() : msg_("illegal argument") {}
        ~illegal_exception() {}

        std::string what() const {return(msg_);}
    private:
        std::string msg_;
};

