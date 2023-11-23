#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

class station
{
private:
    int ID;
    static int newID;

    std::string name_s;
    int cex;
    int workingcex;
    double k;

    friend std::ostream &operator<<(std::ostream &out, const station &s);
    friend std::istream &operator>>(std::istream &in, station &s);

    friend std::ofstream &operator<<(std::ofstream &outf, const station &s);
    friend std::ifstream &operator>>(std::ifstream &fin, station &s);

public:
    station() : ID(newID++) {}

    int get_ID() const { return ID; }
    std::string get_name_s() const { return this->name_s; }
    int get_cex() const { return this->cex; }
    int get_workingcex() const { return this->workingcex; }
    double get_k() const { return this->k; }

    station get_KS() { return *this; }

    void set_KS(std::string name_s_, int cex_, int workingcex_, double k_)
    {
        this->name_s = name_s_;
        this->cex = cex_;
        this->workingcex = workingcex_;
        this->k = k_;
    }
    void set_workingcex(int workingcex_) { this->workingcex = workingcex_; }
    void set_ID(int ID_) { this->ID = ID_; }
    static int get_newID() { return newID; }

    void set_newID(int newID_) { this->newID = newID_; }
};