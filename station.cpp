#include "station.h"
#include "utils.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <unordered_map>

int station::newID = 0;

std::ofstream &operator<<(std::ofstream &outf, const station &s)
{
    outf << "s\n"
         << s.get_ID() << "\n"
         << s.get_name_s() << "\n"
         << s.get_cex() << "\n"
         << s.get_workingcex() << "\n"
         << s.get_k() << "\n";

    return outf;
};
// std::ifstream &operator>>(std::ifstream &inf, station &s)
// {
//     getline(inf, s.name_s);
//     inf >> s.ID >> s.cex >> s.workingcex >> s.k;
//     return inf;
// }
std::ostream &operator<<(std::ostream &out, const station &s)
{
    out << "ID " << s.get_ID() << "\n"
        << "Name KS:  " << s.get_name_s() << "\n"
        << "Number of workshops:  " << s.get_cex() << "\n"
        << "Number of workshops in work:  " << s.get_workingcex() << "\n"
        << "Ratio:  " << s.get_k() << "\n";
    return out;
}

int inputWcex(int cexx, int wcex)
{
    while ((!(std::cin >> wcex) || (std::cin.peek() != '\n')) || (wcex > cexx))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "incorrect data, input int<=" << wcex << "\n"
                  << "__> ";
    }
    return wcex;
}

void station::InputKS(station &s)
{
    std::string name;
    std::cout << "Input name KS\n"
              << "__> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name);

    std::cout << "\nInput number of workshops\n"
              << "__> ";
    int cexx;
    cexx = InputNum<int>(1, 100000);

    std::cout << "Input number of workshops in work\n"
              << "__> ";
    int wcex = inputWcex(cexx, wcex);

    std::cout << "Input ratio\n"
              << "__> ";
    bool kf;
    kf = InputNum<int>(0, 100);

    s.set_KS(name, cexx, wcex, kf);
};

// void station::EditKS(std::unordered_map<int, station> &ss)
// {
//     station s = {};
//     int id;
//     std::cout << "select id station to edit\n";
//     std::cin >> id;
//     s.set_KS(ss.at(id).get_name_s(), ss.at(id).get_cex(), ss.at(id).get_workingcex(), ss.at(id).get_k());
//     std::cout << "Input number of workshops in work\n"
//               << "__> ";
//     s.set_workingcex(inputWcex(s.get_cex(), s.get_workingcex()));
//     ss.erase(id);
//     ss.insert(std::make_pair(id, s));
// };

void station::delKS(std::unordered_map<int, station> &ss)
{
    station s = {};
    std::cout << "select id station to delete\n";
    int id;
    std::cin >> id;
    s = ss.at(id);
    ss.erase(id);
}