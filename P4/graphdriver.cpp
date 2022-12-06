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

    // std::ifstream fin("paperCollabWeighted.txt");
    // while (fin >> a >> b >> w)
    // {
    //     collab.insert(a, b, w);
    // }


    while (std::cin >> cmd)
    {
        if (cmd == "load")
        {
            std::ifstream fin("paperCollabWeighted.txt");
            while (fin >> a >> b >> w)
            {
                collab.insert(a, b, w);
                // collab.addVertex(a);
                // collab.addVertex(b);
                // collab.addEdge(a, w, collab.map[b]);
            }

            std::cout << "success" << std::endl;
        }
        else if (cmd == "i")
        {
            std::cin >> a >> b >> w;

            try
            {
                if ( !((a > 0 && a <= 23133) && (b > 0 && b <= 23133) && (w >= 0 && w <= 1)) )
                {
                    throw illegal_exception();
                }
                if (collab.insert(a, b, w))
                {
                    std::cout << "success" << std::endl;
                }
                else
                {
                    std::cout << "failure" << std::endl;
                }
            }
            catch (illegal_exception &e)
            {

            }
        }
        else if (cmd == "exit")
        {
            break;
        }
    }

    for (int i = 1 ; i < 23133; ++i)
    {
        if (collab.map[i] != nullptr)
        {
            collab.DFS(i);
            if (ans > realAns && ans > 1)
            {
                realAns = ans - 1;
                index = i;
            }
            ans = 0;
        }
    }

    std::cout << realAns << std::endl;

    std::cout << collab.mst(index) << std::endl;

    return 0;
}

void Graph::DFS(int inid)
{
    Vertex* temp = map[inid - 1];
    if (std::find(ignore.begin(), ignore.end(), temp) != ignore.end())
    {
        return;
    }
    
    ++ans;
    temp->visited = true;
    ignore.push_back(temp);

    for (std::size_t i = 0; i < temp->edges.size(); ++i)
    {
        if (temp->edges[i]->nextVertex->visited == false)
        {
            DFS(temp->edges[i]->nextVertex->id);
        }
    }
}