#include "pipe.h"
#include "utils.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

int pipe::newID = 0;

std::ofstream &operator<<(std::ofstream &outf, const pipe &p)
{
    outf << "p\n"
         << p.get_ID() << "\n"
         << p.get_name_p() << "\n"
         << p.get_len() << "\n"
         << p.get_d() << "\n"
         << p.get_remont() << "\n";
    return outf;
}
std::ifstream &operator>>(std::ifstream &fin, pipe &p)
{
    std::string name;
    int id;
    double len;
    int d;
    bool remont;
    fin >> id >> name >> len >> d >> remont;
    p.set_ID(id);
    p.set_Pipe(name, len, d, remont);

    return fin;
}
std::ostream &operator<<(std::ostream &out, pipe &p)
{
    out << "ID " << p.get_ID() << "\n"
        << "Name pipe:  " << p.get_name_p() << "\n"
        << "Length pipe:  " << p.get_len() << "\n"
        << "Diameter pipe:  " << p.get_d() << "\n"
        << "Mending:  " << p.get_remont() << "\n";
    return out;
}

void pipe::InputPipe(pipe &p)
{
    std::string name;
    std::cout << "Input name pipe\n"
              << "__> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name);
    std::cerr << name << "\n";

    std::cout << "Input length pipe\n"
              << "__> ";
    double l;
    l = InputNum<double>(1, 1000000000);

    std::cout << "Input diameter pipe\n"
              << "__> ";
    int di;
    di = InputNum<int>(1, 100000);

    std::cout << "Input mending(1/0)\n"
              << "__> ";
    bool r;
    r = InputNum<bool>(0, 1);

    p.set_Pipe(name, l, di, r);
}

void pipe::EditPipe(std::unordered_map<int, pipe> &ps,pipe &p)
{
    if(ps.empty())
    {
        std::cout<<"No pipe!";
    }
    else
    {
    int id;
    std::cout << "select id pipe to edit\n";
    std::cin >> id;
    std::cerr << id << "\n";
    if(ID_IsPresent(ps, id) && std::cin.good())
    {
    //InputNum<int>(0,id);
    
    p.set_ID(id);
    p.set_Pipe(ps.at(id).get_name_p(), ps.at(id).get_len(), ps.at(id).get_d(), ps.at(id).get_remont());
    std::cout << "Input mending(0/1)\n"
              << "__> ";
    p.set_remont(InputNum<bool>(0, 2));
    ps[id] = p.get_Pipe();
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Not found \\_(._.)_/ \n";
    }
    }
};

void pipe::delPipe(std::unordered_map<int, pipe> &ps,pipe &p)
{
    if(ps.empty())
    {
        std::cout<<"No pipe!";
    }
    else
    {
        std::cout << "select id pipe to delete\n";
        int id;
        std::cin>>id;
        std::cerr << id << "\n";
        if(ID_IsPresent(ps, id) && std::cin.good())
        {
            p = ps.at(id);
            ps.erase(id);
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Not found \\_(._.)_/ \n";
        }
    }
}
