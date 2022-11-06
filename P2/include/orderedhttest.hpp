#include <string>
#include <vector>

class hashitem
{
    public:
        int key;

        void setHashitem(int inKey, std::string inLastname);
        std::string getLastname();

        hashitem(int inKey, std::string inLastname);
        ~hashitem();
    private:
        std::string lastname;
};

class hashtable
{
    public:
        std::vector<class hashitem> *t;
        int primaryHashFunction(int inKey);
        bool insert(int inKey, std::string inLastname);
        bool search(int inKey);
        bool del(int inKey);
        void print(size_t p);

        hashtable(size_t inm);
        ~hashtable();
    private:
        size_t m;
};

