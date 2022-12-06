#include <vector>
#include <string>

class Vertex;

class Edge
{
public:
    Edge(double inWeight, Vertex* inNextVertex) : weight(inWeight), nextVertex(inNextVertex) {}
    ~Edge();

private:
    double weight;
    Vertex* nextVertex;

    friend class Graph;
};

class Vertex 
{
public:
    Vertex(int inid) : id(inid), key(0.0), visited(false), parent(nullptr) {}
    ~Vertex();

    double getKey();
private:
    int id;
    double key;
    bool visited;
    Vertex* parent;
    std::vector<class Edge*> edges;

    friend class Graph;
};

class Graph
{
public:
    // bool addVertex(int inid);
    // bool addEdge(int inid, double inWeight, Vertex* inNextVertex);
    bool insert(int inidA, int inidB, double inWeight);
    void print(int inid);
    bool remove(int inid);
    int graphSize();
    int mst(int inid);
    void DFS(int inid);

    Graph();
    ~Graph();

    bool visit[23133];
    std::vector<class Vertex*> ignore;
    Vertex* map[23133];
    int numOfVertex;
};

class Heap
{
private:
    Vertex* vertices[23134];
    int size;
public:
    Vertex* extractMax();
    void heapify(int ind);
    int getSize();

    Heap(Vertex* inVertices[23133]);
    ~Heap();
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

