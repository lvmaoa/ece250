#include <string>
#include <vector>

class hashitem
{
    public:
        int getKey();
        void setKey(int inKey);
        void setHashitem(int inKey, std::string inLastname);
        std::string getLastname();

        hashitem(int inKey, std::string inLastname);
        ~hashitem();
    private:
        int key;
        std::string lastname;
};

class hashtable
{
    public:
        std::vector<class hashitem *> *t;
        int primaryHashFunction(int inKey);
        void insert(int inKey, std::string inLastname);
        void search(int inKey);
        void del(int inKey);
        void print(size_t p);

        hashtable(size_t inm);
        ~hashtable();
    private:
        size_t m;
};

