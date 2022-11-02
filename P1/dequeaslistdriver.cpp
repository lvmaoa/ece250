#include "./include/dequeaslistdriver.hpp"
#include <iostream>

int main()
{
    size_t pos;
    std::string input, command;

    std::getline(std::cin, input);
    Deque deque(nullptr, nullptr, std::stoi(input.substr(2, input.length())));
    std::cout << "success" << std::endl;

    while (true)
    {
        std::getline(std::cin, input);
        pos = input.find(' ');
        command = input.substr(0, pos);
        if (command == "push_front")
        {
            input.erase(0, pos + 1);
            pos = input.find(' ');
            deque.push_front(new Node(input.substr(0, pos), input.substr(pos + 1, input.length() - pos - 1)));
        }
        else if (command == "push_back")
        {
            input.erase(0, pos + 1);
            pos = input.find(' ');
            deque.push_back(new Node(input.substr(0, pos), input.substr(pos + 1, input.length() - pos - 1)));
        }
        else if (command == "pop_front")
        {
            deque.pop_front();
        }
        else if (command == "pop_back")
        {
            deque.pop_back();
        }
        else if (command == "clear")
        {
            deque.clear();
        }
        else if (command == "size")
        {
            std::cout << "size is " << deque.size() << std::endl;
        }
        else if (command == "front")
        {
            Node* temp = deque.front();
            if (temp != nullptr)
            {
                std::cout << "front is " << temp->name << " " << temp->url << std::endl;
            }
        }
        else if (command == "back")
        {
            Node* temp = deque.back();
            if (temp != nullptr)
            {
                std::cout << "back is " << temp->name << " " << temp->url << std::endl;
            }
        }
        else if (command == "empty")
        {
            std::cout << "empty " << deque.empty() << std::endl;
        }
        else if (command == "find")
        {
            input.erase(0, pos + 1);
            deque.find(input.substr(0, input.length()));
        }
        else if (command == "print")
        {
            deque.print();
        }
        else if (command == "exit")
        {
            break;
        }
    }

    return 0;
}
