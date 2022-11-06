#include <string>

class hashitem
{
    public:
        int key;

        void setHashitem(int inKey, std::string inLastname);
        std::string getLastname();
    private:
        std::string lastname;
};

class hashtable
{
    public:
        hashitem *t;
        int primaryHashFunction(int inKey);
        int secondaryHashFunction(int inKey);
        bool insert(int inKey, std::string inLastname);
        bool search(int inKey);
        bool del(int inKey);
        size_t getSize();

        hashtable(size_t inm);
        ~hashtable();
    private:
        size_t m;
};

