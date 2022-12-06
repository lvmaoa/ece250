#include "graphs.hpp"

#include <iostream>

Graph::Graph()
{
    numOfVertex = 0;
    for (std::size_t i = 0; i < 23133; ++i)
    {
        map[i] = nullptr;
    }
}

Graph::~Graph()
{
    for (std::size_t i = 0; i < 23133; ++i)
    {
        delete map[i];
        map[i] = nullptr;
    }
}

Edge::~Edge()
{
    nextVertex = nullptr;
}

double Vertex::getKey()
{
    return key;
}

Vertex::~Vertex()
{
    id = 0;
    key = 0.0;
    visited = false;
    parent = nullptr;
    for (std::size_t i = 0; i < edges.size(); ++i)
    {
        delete edges[i];
        edges[i] = nullptr;
    }
    edges.clear();
}

// bool Graph::addVertex(int inid)
// {
//     if (map[inid - 1] == nullptr)
//     {
//         map[inid - 1] = new Vertex(inid);
//         ++numOfVertex;
//         return true;
//     }
//     return false;
// }

// bool Graph::addEdge(int inid, double inWeight, Vertex *inNextVertex)
// {
//     std::size_t i = 0;
//     for (; i < map[inid - 1]->edges.size(); ++i)
//     {
//         if (map[inid - 1]->edges[i]->nextVertex == inNextVertex)
//         {
//             return false;
//         }
//     }
//     map[inid - 1]->edges.push_back(new Edge(inWeight, inNextVertex));
//     // map[inid - 1]->edges[i]->nextVertex->pointed.push_back(map[inid]);
//     return true;
// }

bool Graph::insert(int inidA, int inidB, double inWeight)
{
    // if (map[inidA - 1] != nullptr && map[inidB - 1] != nullptr)
    // {
    //     for (std::size_t i = 0; i < map[inidA - 1]->edges.size(); ++i)
    //     {
    //         if (map[inidA]->edges[i] != nullptr)
    //         {
    //             if (map[inidA]->edges[i]->nextVertex->id == inidB)
    //             {
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    // if we need to create A or B
    if (map[inidA - 1] == nullptr || map[inidB - 1] == nullptr)
    {
        if (map[inidA - 1] == nullptr)
        {
            map[inidA - 1] = new Vertex(inidA);
            ++numOfVertex;
        }

        if (map[inidB - 1] == nullptr)
        {
            map[inidB - 1] = new Vertex(inidB);
            ++numOfVertex;
        }

        map[inidA - 1]->edges.push_back(new Edge(inWeight, map[inidB - 1]));
        return true;
    }

    // if A and B both exist check if edge
    for (std::size_t i = 0; i < map[inidA - 1]->edges.size(); ++i)
    {
        if (map[inidA - 1]->edges[i] != nullptr)
        {
            if (map[inidA - 1]->edges[i]->nextVertex->id == inidB)
            {
                return false;
            }
        }
    }

    map[inidA - 1]->edges.push_back(new Edge(inWeight, map[inidB - 1]));
    return true;
}

void Graph::print(int inid)
{
    if (map[inid - 1] == nullptr)
    {
        std::cout << std::endl;
        return;
    }

    // iterate through edges
    for(std::size_t i = 0; i < map[inid - 1]->edges.size(); ++i)
    {
        std::cout << map[inid - 1]->edges[i]->nextVertex->id << " ";
    }
    std::cout << std::endl;
}

bool Graph::remove(int inid)
{
    if (!numOfVertex)
    {
        return false;
    }

    Vertex* temp = map[inid - 1];

    if (temp == nullptr)
    {
        return false;
    }

    for (int i = 0; i < 23133; ++i)
    {
        if (i != (inid - 1))
        {
            Vertex* tempLoop = map[i];
            if (tempLoop != nullptr)
            {
                for (std::size_t j = 0; j < tempLoop->edges.size(); ++j)
                {
                    if (tempLoop->edges[j]->nextVertex == temp)
                    {
                        delete tempLoop->edges[j];
                        tempLoop->edges.erase(tempLoop->edges.begin() + j);
                        break;
                    }
                }
            }
        }
    }

    for (std::size_t i = 0; i < temp->edges.size(); ++i)
    {
        delete temp->edges[i];
        temp->edges[i] = nullptr;
    }

    temp->edges.clear();
    delete temp;

    map[inid - 1] = nullptr;
    --numOfVertex;

    return true;
}

int Graph::graphSize()
{
    return numOfVertex;
}

int Graph::mst(int inid)
{
    std::vector<Vertex*> maxNodes;

    if (numOfVertex == 0)
    {
        return 0;
    }

    if (map[inid - 1] == nullptr)
    {
        return 0;
    }

    for (int i = 0; i < 23133; ++i)
    {
        if (map[i] != nullptr)
        {
            map[i]->key = -1;
            map[i]->parent = nullptr;
            map[i]->visited = false;
        }
    }
    // root
    map[inid - 1]->key = 0;
    Heap priorityQ(map);

    while(priorityQ.getSize() != 0)
    {
        Vertex* max = priorityQ.extractMax();

        max->visited = true;

        if (max->id != inid && max->parent == nullptr)
        {
            break;
        }

        maxNodes.push_back(max);

        for (std::size_t i = 0; i < max->edges.size(); ++i)
        {
            Vertex* node = max->edges[i]->nextVertex;

            if(node->visited == false && max->edges[i]->weight > node->key)
            {
                node->key = max->edges[i]->weight;

                for (int i = (priorityQ.getSize()/2); i > 0; --i)
                {
                    priorityQ.heapify(i);
                }

                node->parent = max;
            }
        }
    }

    map[inid - 1]->parent = nullptr;

    return maxNodes.size();
}

Heap::Heap(Vertex* inVertices[23133])
{
    size = 0;
    vertices[size] = nullptr;
    for (int i = 0; i < 23133; ++i)
    {
        if (inVertices[i] != nullptr)
        {
            vertices[size + 1] = inVertices[i];
            ++size;
        }
    }

    for (int i = size + 1; i < 23133; ++i)
    {
        vertices[i] = nullptr;
    }

    for (int i = (size/2); i > 0; --i)
    {
        heapify(i);
    }
}

Heap::~Heap()
{
    for (int i = 0; i < 23133; ++i)
    {
        vertices[i] = nullptr;
    }
}

void Heap::heapify(int ind)
{
    if (vertices[ind] == nullptr)
    {
        return;
    }
    if (ind == 0)
    {
        ++ind;
    }

    int lgst, left, right;
    lgst = ind;
    left = right = 2 * ind;
    ++right;

    if (left <= size && vertices[left] != nullptr && vertices[left]->getKey() > vertices[ind]->getKey())
    {
        lgst = left;
    }

    if (right <= size && vertices[right] != nullptr && vertices[right]->getKey() > vertices[lgst]->getKey())
    {
        lgst = right;
    }

    if (lgst != ind)
    {
        Vertex* temp = vertices[ind];

        vertices[ind] = vertices[lgst];
        vertices[lgst] = temp;

        heapify(lgst);
    }
}

Vertex* Heap::extractMax()
{
    Vertex* max = vertices[1];
    vertices[1] = vertices[size];

    vertices[size] = nullptr;
    --size;

    heapify(1);

    return max;
}

int Heap::getSize()
{
    return size;
}
