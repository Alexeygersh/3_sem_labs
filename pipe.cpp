#include "pipe.h"
#include "utils.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>

int pipe::newID = 0;

std::ofstream &operator<<(std::ofstream &outf, const pipe &p)
{

    outf << "p"
         << "\n"
         << p.name_p << "\n"
         << p.len << "\n"
         << p.d << "\n"
         << p.remont << "\n";

    return outf;
}
std::ifstream &operator>>(std::ifstream &inf, pipe &p)
{
    getline(inf, p.name_p);
    inf >> p.len >> p.d >> p.remont;
    return inf;
}
std::ostream &operator<<(std::ostream &out, const pipe &p)
{
    out << "Name pipe:  " << p.name_p << "\n"
        << "Length pipe:  " << p.len << "\n"
        << "Diameter pipe:  " << p.d << "\n"
        << "Mending:  " << p.remont << "\n";
    return out;
}

void InputPipe(pipe &p)
{
    std::cout << "Input name pipe\n"
              << "__> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, p.name_p);

    std::cout << "Input length pipe\n"
              << "__> ";
    p.len = InputNum<double>();

    std::cout << "Input diameter pipe\n"
              << "__> ";
    p.d = InputNum<int>();

    std::cout << "Input mending(1/0)\n"
              << "__> ";
    p.remont = InputNum<bool>();
}

void OutPipe(const pipe &p)
{
    /*if (p.len == 0)
        std::cout << "No Pipe\n";
    else*/
    std::cout << p << "\n";
};

void EditPipe(pipe &p)
{
    if (p.len == 0)
    {
        std::cout << "input statements doesnt exist !!!\n";
    }
    else
    {
        std::cout << "Input mending(0/1)\n"
                  << "__> ";
        p.remont = InputNum<bool>();
    }
};