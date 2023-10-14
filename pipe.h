#pragma once
#include <string>
#include <fstream>
class pipe
{
    int id;
    static int NextId;

public:
    std::string name_p;
    double len;
    int d;
    bool remont;

    friend std::ostream &operator<<(std::ostream &out, const pipe &p);
    friend std::istream &operator>>(std::istream &in, pipe &p);
};

std::ostream &operator<<(std::ofstream &out, pipe &p)
{

    out << "p"
        << "\n"
        << p.name_p << "\n"
        << p.len << "\n"
        << p.d << "\n"
        << p.remont << "\n";

    return out;
}
std::istream &operator>>(std::istream &in, pipe &p)
{
    getline(in, p.name_p);
    in >> p.len >> p.d >> p.remont;
    return in;
}
std::ostream &operator<<(std::ostream &out, const pipe &p)
{
    out << "Name pipe:  " << p.name_p << "\n"
        << "Length pipe:  " << p.len << "\n"
        << "Diameter pipe:  " << p.d << "\n"
        << "Mending:  " << p.remont << "\n";
    return out;
}