#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <limits>
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
    int kolvo_cex;
    int kolvo_cex_rabot;
    double k;
};

void InputPipe(truba &);
void InputStation(station &);

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
//============================================  errors  ====================================================
int err07(int per)
{
    while ((per > 7) || (per < 0) || !(cin) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> per;
    }
    return per;
};

template <typename T>
void err0(T per)
{
    while ((per == 0) || !(cin) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> per;
    }
};

template <typename T>
void err(T per)
{
    while (!(cin) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> per;
    }
};

void err_rabot(int cexrab, int cex)
{
    while ((!(cin) || (cin.peek() != '\n')) || (cex < cexrab))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> cexrab;
    }
};

int redact_pipe_err(int per)
{
    while (!(cin) || (cin.peek() != '\n') || (per > 2 || per < 1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> per;
    }
    return per;
};

int redact_station_err(int per)
{
    while (!(cin) || (cin.peek() != '\n') || (per > 3 && per < 1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "incorrect data" << endl
             << "__> ";
        cin >> per;
    }
    return per;
};
//================================================== input/output file ===============================================

void fout(truba &t, station &s)
{
    ofstream out;
    out.open("base.txt" /* ios::ate | ios::out | ios::app*/);
    if (out.is_open())
    {
        out << t.name_t << endl
            << t.len << endl
            << t.d << endl
            << t.remont << endl
            << s.name_s << endl
            << s.kolvo_cex << endl
            << s.kolvo_cex_rabot << endl
            << s.k;
    }

    out.close();
    if (t.name_t == "" || t.d == 0 || t.len == 0)
    {
        cout << "\ninput pipe statements doesnt exist !!!\n";
    }
    if (s.kolvo_cex == 0 || s.name_s == "")
    {
        cout << "\ninput station statements doesnt exist !!!\n";
    }
}

void fin(truba &tr, station &st)
{
    ifstream in;
    in.open("base.txt");
    /*cout << endl
        << in.rdbuf();
    */
    if (in.is_open() && !in.eof())
    {
        in >> tr.name_t;
        in >> tr.len;
        in >> tr.d;
        in >> tr.remont;
        in >> st.name_s;
        in >> st.kolvo_cex;
        in >> st.kolvo_cex_rabot;
        in >> st.k;
    }
    in.close();

    if (tr.name_t == "" || tr.d == 0 || tr.len == 0)
    {
        cout << "\ninput pipe statements doesnt exist !!!\n";
    }
    else if (st.kolvo_cex == 0 || st.name_s == "")
    {
        cout << "\ninput station statements doesnt exist !!!\n";
    }
    else
    {
        cout << "\nload successfully\n";
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
    err0(t.len);

    cout << "Input diameter pipe\n"
         << "__> ";
    cin >> t.d;
    err0(t.d);

    cout << "Input mending(1/0)\n"
         << "__> ";
    cin >> t.remont;
    err(t.remont);
}

void InputKS(station &s)
{
    cout << "Input name KS\n"
         << "__> ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name_s);

    cout << "\nInput number of workshops\n"
         << "__> ";
    cin >> s.kolvo_cex;
    err0(s.kolvo_cex);

    cout << "Input number of workshops in work\n"
         << "__> ";
    cin >> s.kolvo_cex_rabot;
    err_rabot(s.kolvo_cex_rabot, s.kolvo_cex);

    cout << "Input ratio\n"
         << "__> ";
    cin >> s.k;
    err0(s.k);
};
//-------------------------------------------------------
void OutputPipe(truba &tr)
{
    cout << "Name pipe:  " << tr.name_t << "\n"
         << "Length pipe:  " << tr.len << "\n"
         << "Diameter pipe:  " << tr.d << "\n"
         << "Mending:  " << tr.remont << "\n";
};
void OutputKS(station &st)
{
    station s;
    cout << "Name KS:  " << st.name_s << "\n"
         << "Number of workshops:  " << st.kolvo_cex << "\n"
         << "Number of workshops in work:  " << st.kolvo_cex_rabot << "\n"
         << "Ratio:  " << st.k << "\n";
};

void output(truba tr, station st)
{
    if (tr.name_t == "" && tr.d == 0 && tr.len == 0)
    {
        cout << "input pipe statements doesnt exist\n";
    }
    if (st.kolvo_cex == 0 && st.name_s == "")
    {
        cout << "input station statements doesnt exist\n";
    }
    if (tr.name_t != "" && tr.d != 0 && tr.len != 0)
    {
        OutputPipe(tr);
    }
    if (st.kolvo_cex != 0 && st.name_s != "")
    {
        OutputKS(st);
    }
}
//============================================  edits   ==============================================

void redact_pipe(truba &tr)
{
    int p = 0;

    if ((tr.name_t == "" && tr.d == 0 && tr.len == 0))
    {
        cout << "\n input statements doesnt exist !!!\n";
    }
    else
    {

        cout << "Choose parameter which you want to edit\n"
             << "1. Name pipe\n"
             << "2. mending(0/1)\n"
             << "__> ";
        cin >> p;
        switch (redact_pipe_err(p))
        {
        case (1):
        {
            cout << "Input name pipe\n"
                 << "__> ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, tr.name_t);
            break;
        }
        case (2):
        {
            cout << "Input mending(1/0)\n"
                 << "__> ";
            cin >> tr.remont;
            err(tr.remont);
            break;
        }
        }
    }
};

void redact_station(struct station st)
{
    int p = 0;

    if ((st.k == 0 || st.kolvo_cex == 0 || st.name_s == ""))
    {
        cout << "\n input statements doesnt exist \n";
    }
    else
    {
        cout << "Choose parameter which you want to edit\n"
             << "1. Name KS\n"
             << "2. Number of workshops in work\n"
             << "3. Ratio\n"
             << "__> ";
        cin >> p;
        switch (redact_station_err(p))
        {
        case (1):
        {
            cout << "Input Name KS\n"
                 << "__> ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, st.name_s);
            break;
        }
        case (2):
        {

            cout << "Input Number of workshops in work\n"
                 << "__> ";
            cin >> st.kolvo_cex_rabot;
            err_rabot(st.kolvo_cex_rabot, st.kolvo_cex);

            break;
        }
        case (3):
        {
            cout << "Ratio\n"
                 << "__> ";
            cin >> st.k;
            while (st.k == 0)
            {
                cout << "\nWrong ratio!!!\n";
                cout << "Input ratio\n"
                     << "__> ";
                cin >> st.k;
            }
            break;
        }
        }
    }
};

//=============================================================================================================
int main()
{
    truba t = {};
    station s = {};

    while (1)
    {
        menu();
        int p = 0;
        cin >> p;

        switch (err07(p))
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
            output(t, s);
            break;
        }
        case (4):
        {
            system("CLS");
            redact_pipe(t);
            break;
        }
        case (5):
        {
            system("CLS");
            redact_station(s);
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