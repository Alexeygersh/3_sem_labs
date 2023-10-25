// #include <fstream>
// #include <stdlib.h>
// #include <limits>
#include <unordered_map>
// #include <string>
#include <typeinfo>
#include "pipe.h"
#include "station.h"

// #include <algorithm>
// #include <iterator>
using namespace std;

void menu()
{
    std::cout << "\n============================================\n"
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

//================================================== input/output file ===============================================

void fout(const string &file, const unordered_map<int, pipe> &ps, const unordered_map<int, station> &ss)
{
    ofstream outf(file);
    if (outf.is_open())
    {
        for (auto &[id, p] : ps)
        {
            if (p.len > 0)
            {
                outf << p;
            }
        }
        for (auto &[id, s] : ss)
        {

            if (s.cex > 0)
                outf << s;
        }
    }
}

void fin(const string &file, unordered_map<int, pipe> &ps, unordered_map<int, station> &ss)
{
    ifstream in(file);
    string flag;
    if (in.is_open())
    {
        while (getline(in, flag))
        {
            if (flag == "p")
            {
                pipe p = {};
                ps.insert(make_pair(p.ID, p));
            }
            if (flag == "s")
            {
                station s = {};
                ss.insert(make_pair(s.ID, s));
            }
        }
    }
    in.close();
}

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

/* void clsFile(const string &file)
{
    ofstream cl(file, ofstream::trunc);
} */

int main()
{
    unordered_map<int, pipe> ps;
    unordered_map<int, station> ss;
    while (1)
    {
        menu();
        switch (InputInt_07())
        {
        case (1):
        {
            // system("CLS");
            pipe p = {};
            InputPipe(p);
            ps.insert(make_pair(p.ID, p));
            break;
        }
        case (2):
        {
            station s = {};
            InputKS(s);
            ss.insert(make_pair(s.ID, s));
            break;
        }
        case (3):
        {
            for (auto &[id, p] : ps)
                OutPipe(p);
            for (auto &[id, s] : ss)
                OutKS(s);
            // for_each(ss.begin(), ss.end(), OutKS);
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
            string file;
            cout << "Input name file like 'something.txt'\n";
            cin >> file;
            // fout(file, ps, ss);
            break;
        }
        case (7):
        {
            string file;
            cout << "Input name file like 'something.txt'\n";
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // getline(cin, file);
            cin >> file;
            // fin(file, ps, ss);
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