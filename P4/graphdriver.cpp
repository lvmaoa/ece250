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

            // collab.addVertex(a);
            // collab.addVertex(b);
            // collab.addEdge(a, w, collab.map[b]);
        }
        else if (cmd == "p")
        {
            std::cin >> a;

            try
            {
                if ( !(a > 0 && a <= 23133) )
                {
                    throw illegal_exception();
                }
                collab.print(a);
            }
            catch (illegal_exception &e)
            {

            }
        }
        else if (cmd == "d")
        {
            std::cin >> a;
            try
            {
                if ( !(a > 0 && a <= 23133) )
                {
                    throw illegal_exception();
                }
                if (collab.remove(a))
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
        else if (cmd == "mst")
        {
            std::cin >> a;
            int temp = collab.mst(a);
            if (temp)
            {
                std::cout << temp << std::endl;
            }
            else
            {
                std::cout << "failure" << std::endl;
            }
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

