#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <iomanip>
using namespace std;

struct truba
{
    string name_t;
    double len;
    int d;
    bool remont;
};
struct station
{
    string name_s;
    int cex;
    int workingcex;
    double k;
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
void fout(truba &t, station &s)
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
            out << "t" << endl
                << t.name_t << endl
                << t.len << endl
                << t.d << endl
                << t.remont << endl;
            cout << "\npipe saved successfully\n";
        }
    }
    if (s.name_s == "_" || s.cex == 0)
    {
        cout << "\nno station\n";
    }
    else
    {
        if (out.is_open())
        {
            out << "s" << endl
                << s.name_s << endl
                << s.cex << endl
                << s.workingcex << endl
                << s.k << endl;
            cout << "\nstation saved successfully\n";
        }
    }
    out.close();
};

//----------------------------------------------------------

void fin(truba &t, station &s)
{
    string id;
    ifstream in("base.txt");
    if (in.is_open())
    {
        in >> id;
        if (id == "")
        {
            cout << "\nno data\n";
        }
        else if (id == "t")
        {
            // getline(str, sizeof(str))
            /*getline(file,p.name);

            getline(file, line);
            p.length = stod(line);

            getline(file, line);
            p.diameter = stod(line);

            getline(file, line);
            p.inRepair = stoi(line);

            getline(file,line);*/
            in >> t.name_t >> t.len >> t.d >> t.remont;
            cout << "\npipe loaded successfully\n";
            in >> id;
            if (id == "s")
            {
                in >> s.name_s >> s.cex >> s.workingcex >> s.k;
                cout << "\nstation loaded successfully\n";
            }
        }
        else if (id == "s")
        {
            in >> s.name_s >> s.cex >> s.workingcex >> s.k;
            cout << "\nstation loaded successfully\n";
        }
    }
    in.close();
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
            system("CLS");
            exit(0);
            break;
        default:
            cout << "Wrong action\n";
            return 0;
        };
    }
}