#pragma once
#include <string>
#include <fstream>
#include <iostream>

class station
{
private:
    static int newID;

public:
    int ID;
    std::string name_s;
    int cex;
    int workingcex;
    double k;

    station() : ID(newID++) {}
    int getID()
    {
        return ID;
    }

    friend std::ostream &operator<<(std::ostream &out, const station &s);
    friend std::istream &operator>>(std::istream &in, station &s);
    friend std::ofstream &operator<<(std::ofstream &outf, const station &s);
    friend std::ifstream &operator>>(std::ifstream &inf, station &s);
};

void InputKS(station &s);
void OutKS(const station &s);
void EditKS(station &s);