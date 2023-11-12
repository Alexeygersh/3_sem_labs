#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

class pipe
{
private:
    int ID;
    static int newID;

    std::string name_p;
    double len;
    int d;
    bool remont;

    friend std::ostream &operator<<(std::ostream &out, pipe &p);
    friend std::istream &operator>>(std::istream &in, pipe &p);

    friend std::ofstream &operator<<(std::ofstream &outf, const pipe &p);
    friend std::ifstream &operator>>(std::ifstream &fin, pipe &p);
    
    friend void addPipe(std::unordered_map<int, pipe> &ps);

public:
    
    pipe() : ID(newID++) {}

    int get_ID() const { return ID; }
    std::string get_name_p() const { return this->name_p; }
    double get_len() const { return this->len; }
    int get_d() const { return this->d; }
    bool get_remont() const { return this->remont; }

    pipe get_Pipe()
    {
        return *this;
    }

    void set_Pipe(std::string name_p, double len, int d, bool remont)
    {
        this->name_p = name_p;
        this->len = len;
        this->d = d;
        this->remont = remont;
    }
    void set_remont(bool remont) { this->remont = remont; }
    void set_ID(int ID) { this->ID = ID; }
    static int get_newID() { return newID; }

    void set_newID(int newID) { this->newID = newID; }
};
