#include <string>

class Trie
{
    private:
        bool isEOW;
        char data;
    public:
        bool visited;
        Trie* children[26];

        void setEOW(bool inEOW);
        bool getEOW();
        void setData(char inData);
        char getData();

        bool isEmpty();
        void insert(std::string inKey);
        bool search(std::string inKey);
        Trie* erase(Trie *inTrie, std::string inKey, int depth);
        void print();
        void DFS(Trie *inTrie, std::string out, int depth);

        Trie();
        ~Trie();
};

