#pragma once
#include <string>
#include <fstream>
#include <iostream>

class pipe
{
private:
    static int newID;

public:
    int ID;
    std::string name_p;
    double len;
    int d;
    bool remont;

    pipe() : ID(newID++) {}
    int getID()
    {
        return ID;
    }

    friend std::ifstream &operator<<(std::ifstream &inf, pipe &p);
    friend std::ofstream &operator<<(std::ofstream &outf, const pipe &p);
    friend std::ostream &operator<<(std::ostream &out, const pipe &p);
    friend std::istream &operator>>(std::istream &in, pipe &p);
};

void InputPipe(pipe &p);
void OutPipe(const pipe &p);
void EditPipe(pipe &p);