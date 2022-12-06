#include "graphs.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>

int ans = 0;

int main ()
{
    std::string cmd;
    int a, b, realAns = 0, index = 0;
    double w;

    Graph collab;

    std::ifstream fin("paperCollabWeighted.txt");
    while (fin >> a >> b >> w)
    {
        collab.insert(a, b, w);
    }


    for (int i = 1 ; i < 23133; ++i)
    {
        if (collab.map[i] != nullptr)
        {
            if (collab.visit[i] == false)
            {
                // DFS will compute the # of edges in the MST
                collab.DFS(i);
                if (ans > realAns)
                {
                    realAns = ans;
                    index = i;
                }
                ans = 0;
            }

        }
    }

    std::cout << realAns << std::endl;

    return 0;
}

void Graph::DFS(int inid)
{
    Vertex* temp = map[inid - 1];
    
    ++ans;
    visit[inid - 1] = true;
    ignore.push_back(temp);

    for (std::size_t i = 0; i < temp->edges.size(); ++i)
    {
        if (visit[temp->edges[i]->nextVertex->id - 1] == false)
        {
            DFS(temp->edges[i]->nextVertex->id);
        }
    }
}