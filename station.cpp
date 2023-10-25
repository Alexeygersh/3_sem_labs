#include "station.h"
#include "utils.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>

int station::newID = 0;

std::ofstream &operator<<(std::ofstream &outf, const station &s)
{
    outf << "s"
         << "\n"
         << s.name_s << "\n"
         << s.cex << "\n"
         << s.workingcex << "\n"
         << s.k << "\n";

    return outf;
};
std::ifstream &operator>>(std::ifstream &inf, station &s)
{
    getline(inf, s.name_s);
    inf >> s.cex >> s.workingcex >> s.k;
    return inf;
}
std::ostream &operator<<(std::ostream &out, const station &s)
{
    out << "Name KS:  " << s.name_s << "\n"
        << "Number of workshops:  " << s.cex << "\n"
        << "Number of workshops in work:  " << s.workingcex << "\n"
        << "Ratio:  " << s.k << "\n";
    return out;
}

void Input_workingcex(station &s)
{
    while ((!(std::cin >> s.workingcex) || (std::cin.peek() != '\n')) || (s.workingcex > s.cex))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "incorrect data, input int<=" << s.cex << "\n"
                  << "__> ";
    }
};

void InputKS(station &s)
{
    std::cout << "Input name KS\n"
              << "__> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, s.name_s);

    std::cout << "\nInput number of workshops\n"
              << "__> ";
    s.cex = InputNum<int>();

    std::cout << "Input number of workshops in work\n"
              << "__> ";
    Input_workingcex(s);

    std::cout << "Input ratio\n"
              << "__> ";
    s.k = InputNum<int>();
};

void OutKS(const station &s)
{
    /*if (s.cex == 0)
        std::cout << "No KS\n";
    else*/
    std::cout << s << "\n";
};

void EditKS(station &s)
{
    if (s.cex == 0)
    {
        std::cout << "input statements doesnt exist \n";
    }
    else
    {
        std::cout << "Input number of workshops in work\n"
                  << "__> ";
        // cin >> s.workingcex;
        Input_workingcex(s);
    }
};