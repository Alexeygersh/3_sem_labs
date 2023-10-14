#pragma once
#include <string>
#include <fstream>
class station
{
    int id;
    static int NextId;

public:
    std::string name_s;
    int cex;
    int workingcex;
    double k;

    friend std::ostream &operator<<(std::ostream &out, const station &s);
    friend std::istream &operator>>(std::istream &in, station &s);
};

std::ostream &operator<<(std::ofstream &out, station &s)
{
    out << "s"
        << "\n"
        << s.name_s << "\n"
        << s.cex << "\n"
        << s.workingcex << "\n"
        << s.k << "\n";

    return out;
};
std::istream &operator>>(std::istream &in, station &s)
{
    getline(in, s.name_s);
    in >> s.cex >> s.workingcex >> s.k;
    return in;
}
std::ostream &operator<<(std::ostream &out, const station &s)
{
    out << "Name KS:  " << s.name_s << "\n"
        << "Number of workshops:  " << s.cex << "\n"
        << "Number of workshops in work:  " << s.workingcex << "\n"
        << "Ratio:  " << s.k << "\n";
    return out;
}