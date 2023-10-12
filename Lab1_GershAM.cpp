#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct truba
{
    string name_t;
    double len;
    int d;
    bool remont;

    // friend ostream& operator<<(ostream& out, const truba& t);
    // friend istream& operator>>(istream& in, truba& t);
};
struct station
{
    string name_s;
    int cex;
    int workingcex;
    double k;

    // friend ostream& operator<<(ostream& out, const station& s);
    // friend istream& operator>>(istream& in, station& s);
};

// void InputPipe(truba &);
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
int InputNum_NotNULL()
{
    int p;
    while (!(cin >> p) || (cin.peek() != '\n') || (p == 0))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
    }
    return p;
};
double InputNum_NotNULL()
{
    double p;
    while (!(cin >> p) || (cin.peek() != '\n') || (p == 0))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
    }
    return p;
};

bool InputBool()
{
    bool p;
    while (!(cin >> p) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
    }
    return p;
};

void Input_workingcex(station &s)
{
    while ((!(cin >> s.workingcex) || (cin.peek() != '\n')) || (s.workingcex > s.cex))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data, input int<=" << s.cex << endl
             << "__> ";
        // cin >> s.workingcex;
    }
};

//================================================== input/output file ===============================================

ostream &operator<<(ofstream &out, truba &t)
{

    out << "t" << endl
        << t.name_t << endl
        << t.len << endl
        << t.d << endl
        << t.remont << endl;

    return out;
}

ostream &operator<<(ofstream &out, station &s)
{
    out << "s" << endl
        << s.name_s << endl
        << s.cex << endl
        << s.workingcex << endl
        << s.k << endl;

    return out;
};
/*void foutPipes(const vector<truba> &ts)
{
    ofstream out("base.txt");
    for (const auto &t : ts)
    {
        foutPipe(out, t);
    }
    out.close();
}
*/

//----------------------

istream &operator>>(istream &in, truba &t)
{

    getline(in, t.name_t);
    in >> t.len >> t.d >> t.remont;
    return in;
}

istream &operator>>(istream &in, station &s)
{

    getline(in, s.name_s);
    in >> s.cex >> s.workingcex >> s.k;
    return in;
}

/*
vector<truba> finPipes()
{
    ifstream in("base.txt");
    vector<truba> ts;
    truba t;
    while (in >> t)
    {
        ts.push_back(t);
    }

    in.close();
    return ts;
}
*/

void fout(truba &t, station &s)
{
    ofstream out;
    out.open("base.txt");
    if (out.is_open())
    {
        if (t.len > 0)
            out << t;
        if (s.cex > 0)
            out << s;
    }
    out.close();
}

// ifstream &GotoLine(ifstream &file, unsigned int num)
// {
//     file.seekg(ios::beg);
//     for (unsigned int i = 0; i < num - 1; ++i)
//     {
//         file.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
//     return file;
// }
void fin(truba &t, station &s)
{
    ifstream in("base.txt");
    string id;
    if (in.is_open())
    {
        while (getline(in, id))
        {
            if (id == "t")
            {
                in >> t;
                cout << "pipe loaded\n";
            }
            else if (id == "s")
            {
                in >> s;
                cout << "station loaded\n";
            }
            else
            {
                cout << "no pipe data\n";
            }
        }
        // in.peek();
    }
    in.close();
}

void clsFile()
{
    ofstream cl;
    cl.open("base.txt"); //, std::ofstream::out | std::ofstream::trunc);
    cl.close();
}
//================================================== input/output ===============================================
void InputPipe(truba &t)
{
    cout << "Input name pipe\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t.name_t);

    cout << "Input length pipe\n"
         << "__> ";
    t.len = InputNum_NotNULL();

    cout << "Input diameter pipe\n"
         << "__> ";
    t.d = InputNum_NotNULL();

    cout << "Input mending(1/0)\n"
         << "__> ";
    t.remont = InputBool();
}
void InputKS(station &s)
{
    cout << "Input name KS\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name_s);

    cout << "\nInput number of workshops\n"
         << "__> ";
    s.cex = InputNum_NotNULL();

    cout << "Input number of workshops in work\n"
         << "__> ";
    Input_workingcex(s);

    cout << "Input ratio\n"
         << "__> ";
    s.k = InputNum_NotNULL();
};
//-------------------------------------------------------
void OutputPipe(const truba &t)
{
    if (t.name_t == "_" || t.d == 0 || t.len == 0)
    {
        cout << "Pipe statements doesnt exist\n";
    }
    else
    {
        cout << "Name pipe:  " << t.name_t << "\n"
             << "Length pipe:  " << t.len << "\n"
             << "Diameter pipe:  " << t.d << "\n"
             << "Mending:  " << t.remont << "\n";
    }
};
void OutputKS(const station &s)
{
    if (s.cex == 0 || s.name_s == "_")
    {
        cout << "Station statements doesnt exist\n";
    }
    else
    {
        cout << "Name KS:  " << s.name_s << "\n"
             << "Number of workshops:  " << s.cex << "\n"
             << "Number of workshops in work:  " << s.workingcex << "\n"
             << "Ratio:  " << s.k << "\n";
    }
};

//============================================  edits  ==============================================

void EditPipe(truba &t)
{
    if (t.name_t == "_" || t.d == 0 || t.len == 0)
    {
        cout << "input statements doesnt exist !!!\n";
    }
    else
    {
        cout << "Input mending(0/1)\n"
             << "__> ";
        t.remont = InputBool();
    }
};
void EditKS(station &s)
{
    if (s.k == 0 || s.cex == 0 || s.name_s == "_")
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

//=============================================================================================================
int main()
{
    truba t = {};
    station s = {};
    t.name_t = "_";
    s.name_s = "_";

    while (1)
    {
        menu();
        switch (InputInt_07())
        {
        case (1):
        {
            system("CLS");
            InputPipe(t);
            break;
        }
        case (2):
        {
            system("CLS");
            InputKS(s);
            break;
        }
        case (3):
        {
            system("CLS");
            OutputPipe(t);
            OutputKS(s);
            break;
        }
        case (4):
        {
            system("CLS");
            EditPipe(t);
            break;
        }
        case (5):
        {
            system("CLS");
            EditKS(s);
            break;
        }
        case (6):
        {
            system("CLS");
            // clsFile();
            fout(t, s);
            break;
        }
        case (7):
        {
            system("CLS");
            fin(t, s);
            break;
        }
        case (0):
        {
            system("CLS");
            exit(0);
            break;
        }
        default:
            cout << "Wrong action\n";
            return 0;
        };
    }
}