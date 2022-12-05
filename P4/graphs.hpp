#include <vector>
#include <string>

class Vertex;

class Edge
{
public:
    double weight;
    Vertex* nextVertex;
    // need this ?
    /* Vertex* currVertex; */

    Edge(double inWeight, Vertex* inNextVertex) : weight(inWeight), nextVertex(inNextVertex) {}
    ~Edge();
};

class Vertex 
{
public:
    int id;
    std::vector<class Edge*> edges;
    std::vector<class Vertex*> pointed;

    Vertex(int inid) : id(inid) {}
    ~Vertex();
};

class Graph
{
public:
    Vertex* map[23133];
    int numOfVertex;

    bool addVertex(int inid);
    bool addEdge(int inid, double inWeight, Vertex* inNextVertex);
    void print(int inid);
    bool remove(int inid);
    int graphSize();
    int mst(int inid);


    Graph();
    ~Graph();
};

class Heap
{
public:
    Vertex* parent;
    Vertex* vertex;
    double key;
    bool visited;

    Heap() : parent(nullptr), vertex(nullptr), key(0.0), visited(false) {}
    ~Heap() {}
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

