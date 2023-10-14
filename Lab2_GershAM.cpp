#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <string>
#include <typeinfo>
#include "pipe.h"
#include "station.h"
using namespace std;

// void InputPipe(pipe &);
// void InputKS(station &);

void menu()
{
    cout << "\n============================================\n"
         << "__________________Menu______________________\n\n"
         << "select one of the following items:\n"
         << "1. Add pipe\n"
         << "2. Add KS\n"
         << "3. View all objects\n"
         << "4. Edit pipe\n"
         << "5. Edit KS\n"
         << "6. Save\n"
         << "7. Load\n"
         << "0. Exit\n";
};

int InputInt_07()
{
    int p = 0;
    while (!(cin >> p) || (cin.peek() != '\n') || (p > 7) || (p < 0))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
    }
    return p;
};
template <typename T>
T InputNum()
{
    T param;
    if (string(typeid(param).name()) == "bool")
    {
        while (!(std::cin >> param) || (cin.peek() != '\n'))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "incorrect data\n"
                 << "__> ";
        }
    }
    else
    {
        while (!(cin >> param) || (cin.peek() != '\n') || (param == 0))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "incorrect data\n"
                      << "__> ";
        }
    }

    return param;
};

void Input_workingcex(station &s)
{
    while ((!(cin >> s.workingcex) || (cin.peek() != '\n')) || (s.workingcex > s.cex))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data, input int<=" << s.cex << endl
             << "__> ";
    }
};

//================================================== input/output file ===============================================

void fout(string file, pipe &p, station &s)
{
    ofstream out(file);
    if (out)
    {
        if (p.len > 0)
            out << p;
        if (s.cex > 0)
            out << s;
    }
}

void fin(string file, pipe &p, station &s)
{
    ifstream in(file);
    string id;
    if (in.is_open())
    {
        while (getline(in, id))
        {
            if (id == "p")
            {
                in >> p;
                cout << "pipe loaded\n";
            }
            else if (id == "s")
            {
                in >> s;
                cout << "station loaded\n";
            }
            else
            {
                cout << "no data\n";
            }
        }
    }
}
/*
void foutPipes(const string &file, const vector<pipe> &ts)
{
    ofstream out(file);
    for (const auto &t : ts)
    {
        foutPipe(out, t);
    }
    out.close();
}

//----------------------

vector<pipe> finPipes(const std::string &file)
{
    ifstream in(file);
    vector<pipe> ts;
    pipe t;
    while (in >> t)
    {
        ts.push_back(t);
    }

    in.close();
    return ts;
}
*/
// v.reserve(10)

// ifstream &GotoLine(ifstream &file, unsigned int num)
// {
//     file.seekg(ios::beg);
//     for (unsigned int i = 0; i < num - 1; ++i)
//     {
//         file.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
//     return file;
// }

void clsFile(const string &file)
{
    ofstream cl(file, ofstream::trunc);
}
//================================================== input/output ===============================================
void InputPipe(pipe &p)
{
    cout << "Input name pipe\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.name_p);

    cout << "Input length pipe\n"
         << "__> ";
    p.len = InputNum<double>();

    cout << "Input diameter pipe\n"
         << "__> ";
    p.d = InputNum<int>();

    cout << "Input mending(1/0)\n"
         << "__> ";
    p.remont = InputNum<bool>();
}
void InputKS(station &s)
{
    cout << "Input name KS\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name_s);

    cout << "\nInput number of workshops\n"
         << "__> ";
    s.cex = InputNum<int>();

    cout << "Input number of workshops in work\n"
         << "__> ";
    Input_workingcex(s);

    cout << "Input ratio\n"
         << "__> ";
    s.k = InputNum<int>();
};
//-------------------------------------------------------
void OutPipe(const pipe &p)
{
    if (p.len == 0)
        cout << "No Pipe\n";
    else
        cout << p << "\n";
};
void OutKS(const station &s)
{
    if (s.cex == 0)
    {
        cout << "No KS\n";
    }
    else
    {
        cout << s << "\n";
    }
};

//============================================  edits  ==============================================

void EditPipe(pipe &p)
{
    if (p.len == 0)
    {
        cout << "input statements doesnt exist !!!\n";
    }
    else
    {
        cout << "Input mending(0/1)\n"
             << "__> ";
        p.remont = InputNum<bool>();
    }
};
void EditKS(station &s)
{
    if (s.cex == 0)
    {
        cout << "input statements doesnt exist \n";
    }
    else
    {
        cout << "Input number of workshops in work\n"
             << "__> ";
        // cin >> s.workingcex;
        Input_workingcex(s);
    }
};

string InputNameFile()
{
    string file;
    cout << "Input name file like 'something.txt'\n"
         << "__> ";
    getline(cin, file);
    return file;
}
//=============================================================================================================
int main()
{
    vector<pipe> ps;
    vector<station> ss;
    ps.resize(5);
    ss.resize(5);
    while (1)
    {
        menu();
        switch (InputInt_07())
        {
        case (1):
        {
            // system("CLS");
            // cout << "Input number of pipes\n";
            // cin >> size;

            pipe p = {};
            InputPipe(p);
            ps.push_back(p);
            break;
        }
        case (2):
        {
            // cout << "Input number of stations\n";
            // cin >> size;

            station s = {};
            InputKS(s);
            ss.push_back(s);
            break;
        }
        case (3):
        {
            for (auto &p : ps)
            {
                OutPipe(p);
            }
            for (auto &s : ss)
            {
                OutKS(s);
            }
            break;
        }
        case (4):
        {
            // EditPipe(p);
            break;
        }
        case (5):
        {
            // EditKS(s);
            break;
        }
        case (6):
        {
            // clsFile();

            // fout(InputNameFile(), p, s);
            break;
        }
        case (7):
        {
            // fin(InputNameFile(), p, s);
            break;
        }
        case (0):
        {
            exit(0);
            break;
        }
        default:
            cout << "Wrong action\n";
            return 0;
        };
    }
}