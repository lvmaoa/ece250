#include <string>

class hashitem
{
    public:
        int getKey();
        void setKey(int inKey);
        void setHashitem(int inKey, std::string inLastname);
        std::string getLastname();
    private:
        int key;
        std::string lastname;
};

class hashtable
{
    public:
        hashitem *t;
        int primaryHashFunction(int inKey);
        int secondaryHashFunction(int inKey);
        void insert(int inKey, std::string inLastname);
        void search(int inKey);
        void del(int inKey);
        size_t getSize();

        hashtable(size_t inm);
        ~hashtable();
    private:
        size_t m;
};

