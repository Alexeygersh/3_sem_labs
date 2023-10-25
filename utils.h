#pragma once
#include <string>
#include <iostream>
#include <limits>

template <typename T>
T InputNum()
{
    T param;
    if (std::string(typeid(param).name()) == "b")
    {
        while (!(std::cin >> param) || (std::cin.peek() != '\n'))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "incorrect data\n"
                      << "__> ";
        }
    }
    else
    {
        while (!(std::cin >> param) || (std::cin.peek() != '\n') || (param == 0))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "incorrect data\n"
                      << "__> ";
        }
    }

    return param;
};