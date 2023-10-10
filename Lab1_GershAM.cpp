#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;

struct truba
{
    string name_t;
    double len;
    int d;
    bool remont;

    friend ostream &operator<<(ostream &out, truba &t);
    friend istream &operator>>(istream &in, truba &t);
};
struct station
{
    string name_s;
    int cex;
    int workingcex;
    double k;

    friend ostream &operator<<(ostream &out, station &s);
    friend istream &operator>>(istream &in, station &s);
};

void InputPipe(truba &);
void InputKS(station &);

void menu()
{
    cout << "============================================\n"
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
void CheckInputInt_NotNULL(T p)
{
    while (!(cin) || (cin.peek() != '\n') || (p == 0))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> p;
    }
};

void CheckInputInt(bool p)
{
    while (!(cin) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> p;
    }
};

void CheckInput_workingcex(station &s)
{
    while ((!(cin) || (cin.peek() != '\n')) || (s.workingcex > s.cex))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data, input int<=" << s.cex << endl
             << "__> ";
        cin >> s.workingcex;
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
ostream &operator<<(ofstream &out, station &s)
{
    out << "s" << endl
        << s.name_s << endl
        << s.cex << endl
        << s.workingcex << endl
        << s.k << endl;

    return out;
};

//----------------------

istream &operator>>(istream &in, truba &t)
{
    string line;
    if (getline(in, line))
    {
        istringstream iss(line);
        string numStr;
        string id;

        getline(iss, id);

        getline(iss, t.name_t);

        getline(iss, numStr);
        t.len = stod(numStr);

        getline(iss, numStr);
        t.d = stoi(numStr);

        getline(iss, numStr);
        t.remont = stoi(numStr);
    }
    return in;
}

istream &operator>>(istream &in, station &s)
{
    string line;
    if (getline(in, line))
    {
        istringstream iss(line);
        string numStr;
        string id;

        getline(iss, id);

        getline(iss, s.name_s);

        getline(iss, numStr);
        s.cex = stoi(numStr);

        getline(iss, numStr);
        s.workingcex = stoi(numStr);

        getline(iss, numStr);
        s.k = stod(numStr);
    }
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

void foutPipe(truba &t)
{
    ofstream out("base.txt");
    if (t.name_t == "_" || t.d == 0 || t.len == 0)
    {
        cout << "\nno pipe\n";
    }
    else
    {
        if (out.is_open())
        {
            out << t;
            out.close();
            cout << "\npipe saved successfully\n";
        }
    }
}
void foutKS(station &s)
{
    ofstream out("base.txt");
    if (s.name_s == "_" || s.cex == 0)
    {
        cout << "\nno station\n";
    }
    else
    {
        if (out.is_open())
        {
            out << s;
            out.close();
            cout << "\nstation saved successfully\n";
        }
    }
}
void finPipe(truba &t)
{
    ifstream in("base.txt");
    string id;
    if (in.is_open())
    {
        getline(in, id);
        if (id == "t")
        {
            in >> t;
        }
        else if (id == "")
        {
            cout << "\nno pipe data\n";
        }
        in.close();
    }
}
void finKS(station &s)
{
    ifstream in("base.txt");
    string id;
    if (in.is_open())
    {
        getline(in, id);
        if (id == "s")
        {
            in >> s;
        }
        else if (id == "")
        {
            cout << "\nno station data\n";
        }
        in.close();
    }
}
//================================================== input/output ===============================================
void InputPipe(truba &t)
{
    cout << "Input name pipe\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t.name_t);

    cout << "\nInput length pipe\n"
         << "__> ";
    cin >> t.len;
    CheckInputInt_NotNULL(t.len);

    cout << "Input diameter pipe\n"
         << "__> ";
    cin >> t.d;
    CheckInputInt_NotNULL(t.d);

    cout << "Input mending(1/0)\n"
         << "__> ";
    cin >> t.remont;
    CheckInputInt(t.remont);
}
void InputKS(station &s)
{
    cout << "Input name KS\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name_s);

    cout << "\nInput number of workshops\n"
         << "__> ";
    cin >> s.cex;
    CheckInputInt_NotNULL(s.cex);

    cout << "Input number of workshops in work\n"
         << "__> ";
    cin >> s.workingcex;
    CheckInput_workingcex(s);

    cout << "Input ratio\n"
         << "__> ";
    cin >> s.k;
    CheckInputInt_NotNULL(s.k);
};
//-------------------------------------------------------
void OutputPipe(truba &t)
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
void OutputKS(station &s)
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
        cout << "\n input statements doesnt exist !!!\n";
    }
    else
    {
        cout << "Input mending(0/1)\n"
             << "__> ";
        cin >> t.remont;
        CheckInputInt(t.remont);
    }
};
void EditKS(station &s)
{
    if (s.k == 0 || s.cex == 0 || s.name_s == "_")
    {
        cout << "\n input statements doesnt exist \n";
    }
    else
    {
        cout << "Input number of workshops in work\n"
             << "__> ";
        cin >> s.workingcex;
        CheckInput_workingcex(s);
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
            system("CLS");
            InputPipe(t);
            break;

        case (2):
            system("CLS");
            InputKS(s);
            break;

        case (3):
            system("CLS");
            OutputPipe(t);
            OutputKS(s);
            break;

        case (4):
            system("CLS");
            EditPipe(t);
            break;

        case (5):
            system("CLS");
            EditKS(s);
            break;

        case (6):
            system("CLS");
            foutPipe(t);
            foutKS(s);
            break;

        case (7):
            system("CLS");
            finPipe(t);
            finKS(s);
            break;

        case (0):
            system("CLS");
            exit(0);
            break;

        default:
            cout << "Wrong action\n";
            return 0;
        };
    }
}