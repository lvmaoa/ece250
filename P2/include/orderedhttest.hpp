#include <string>

class hashtable
{
    public:
        int primaryHashFunction();
        int secondaryHashFunction();

        hashtable();
        ~hashtable();
    private:
        int* hasht;
};

class hashitem
{
    public:
        int key;

        void setLastname(std::string inLastname);
        std::string getLastname();
    private:
        std::string lastname;
};

