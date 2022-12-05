#include "graphs.hpp"

#include <cstddef>
#include <iostream>

Graph::Graph()
{
    for (std::size_t i = 0; i < 23133; ++i)
    {
        map[i] = nullptr;
    }
    numOfVertex = 0;
}

Graph::~Graph()
{
    for (std::size_t i = 0; i < 23133; ++i)
    {
        if (map[i] != nullptr)
        {
            delete map[i];
        }
    }
}

Edge::~Edge()
{
    nextVertex = nullptr;
}

Vertex::~Vertex()
{
    for (std::size_t i = 0; i < pointed.size(); ++i)
    {
        for (std::size_t j = 0; j < pointed[i]->edges.size(); ++j)
        {
            if (pointed[i]->edges[j]->nextVertex == this)
            {
                std::swap(pointed[i]->edges[j], pointed[i]->edges.back());
                delete pointed[i]->edges.back();
                pointed[i]->edges.pop_back();
                // delete pointed[i]->edges[j];
                // pointed[i]->edges.erase(edges.begin() + j);
                break;
            }
        }
    }

    for (std::size_t i = 0; i < edges.size(); ++i)
    {
        for (std::size_t j = 0; j < edges[i]->nextVertex->pointed.size(); ++j)
        {
            if (edges[i]->nextVertex->pointed[j] == this)
            {
                edges[i]->nextVertex->pointed.erase(edges[i]->nextVertex->pointed.begin() + j);
            }
        }
    }

    while (!edges.empty())
    {
        delete edges.back();
        edges.pop_back();
    }
}

bool Graph::addVertex(int inid)
{
    if (map[inid] == nullptr)
    {
        map[inid] = new Vertex(inid);
        ++numOfVertex;
        return true;
    }
    return false;
}

bool Graph::addEdge(int inid, double inWeight, Vertex *inNextVertex)
{
    std::size_t i = 0;
    for (; i < map[inid]->edges.size(); ++i)
    {
        if (map[inid]->edges[i]->nextVertex == inNextVertex)
        {
            return false;
        }
    }
    map[inid]->edges.push_back(new Edge(inWeight, inNextVertex));
    map[inid]->edges[i]->nextVertex->pointed.push_back(map[inid]);
    return true;
}

void Graph::print(int inid)
{
    for(std::size_t i = 0; i < map[inid]->edges.size(); ++i)
    {
        std::cout << map[inid]->edges[i]->nextVertex->id << " ";
    }
    std::cout << std::endl;
}

bool Graph::remove(int inid)
{
    if (map[inid] == nullptr)
    {
        return false;
    }
    --numOfVertex;
    delete map[inid];
    map[inid] = nullptr;
    return true;
}

int Graph::graphSize()
{
    return numOfVertex;
}

int Graph::mst(int inid)
{
    std::vector<Heap> maxHeap(23133);
    int j = 0;
    for (int i = 0; i < 23133; ++i)
    {
        if (map[i] != nullptr)
        {
            maxHeap[j].vertex = map[i];
            if (inid == i)
            {
                maxHeap[j].key = 0;
            }
            ++j;
        }
    }

}

