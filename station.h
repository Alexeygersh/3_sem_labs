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

    friend std::ofstream &operator<<(std::ofstream &outf, const station &s);
    friend std::ifstream &operator>>(std::ifstream &fin, station &s);

public:
    station() : ID(newID++) {}

    void InputKS(station &s);
    void EditKS(std::unordered_map<int, station> &ss, station &s);
    void delKS(std::unordered_map<int, station> &ss, station &s);

    int get_ID() const { return ID; }
    std::string get_name_s() const { return this->name_s; }
    int get_cex() const { return this->cex; }
    int get_workingcex() const { return this->workingcex; }
    double get_k() const { return this->k; }

    station get_KS() { return *this; }

    void set_KS(std::string name_s, int cex, int workingcex, double k)
    {
        this->name_s = name_s;
        this->cex = cex;
        this->workingcex = workingcex;
        this->k = k;
    }
    void set_workingcex(int workingcex) { this->workingcex = workingcex; }
    void set_ID(int ID) { this->ID = ID; }
    static int get_newID() { return newID; }

    void set_newID(int newID) { this->newID = newID; }
};