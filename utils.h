#pragma once
#include <string>
#include <iostream>
#include <limits>

template <typename T>
T InputNum(T start, T end)
{
    T param;
    while (!(std::cin >> param) || (std::cin.peek() != '\n') || (param < start) || (param > end))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "incorrect data\n"
                  << "__> ";
    }
    return param;
};
