#include "graphs.hpp"

#include <iostream>
#include <fstream>

int main ()
{
    std::string cmd;
    int a, b, w;

    Graph collab;

    while (std::cin >> cmd)
    {
        if (cmd == "load")
        {
            std::ifstream fin("paperCollabWeighted.txt");
            while (fin >> a >> b >> w)
            {
                collab.addVertex(a);
                collab.addVertex(b);
                collab.addEdge(a, w, collab.map[b]);
            }

            std::cout << "success" << std::endl;
        }
        else if (cmd == "i")
        {
            std::cin >> a >> b >> w;

            collab.addVertex(a);
            collab.addVertex(b);
            collab.addEdge(a, w, collab.map[b]);
        }
        else if (cmd == "p")
        {
            std::cin >> a;
            collab.print(a);
        }
        else if (cmd == "d")
        {
            std::cin >> a;
            collab.remove(a);
        }
        else if (cmd == "mst")
        {

        }
        else if (cmd == "size")
        {
            std::cout << "number of vertices is " << collab.graphSize() << std::endl;
        }
        else if (cmd == "exit")
        {
            break;
        }
    }
    return 0;
}

