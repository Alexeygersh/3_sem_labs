#include "utils.h"
#include "pipe.h"
#include "station.h"
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
              << "6. Delete pipe\n"
              << "7. Delete KS\n"
              << "8. Save\n"
              << "9. Load\n"
              << "10. Find\n"
              << "0. Exit\n";
};

//================================================== input/output file ===============================================

void fout(const string &file, const unordered_map<int, pipe> &ps, const unordered_map<int, station> &ss)
{
    ofstream outf(file);
    if (outf.is_open())
    {
        for (auto &[id, p] : ps)
        {
            // if (p.len > 0)
            outf << p;
        }
        for (auto &[id, s] : ss)
        {

            // if (station::s.cex > 0)
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
                pipe p;
                fin >> p;
                ps.insert(make_pair(p.get_ID(), p));
            }
            if (flag == "s")
            {
                station s;
                fin >> s;
                ss.insert(make_pair(s.get_ID(), s));
            }
        }
    }
    in.close();
}

int find(unordered_map<int, pipe> &ps, unordered_map<int, station> &ss)
{
    /*
    string occurrence;
    cout << "Input occurrence\n";
    cin >> occurrence;
    cout << "what do you want to find?\n"
         << "1. Pipe(s)\n"
         << "2. Station(s)\n"
         << "0. exit to menu\n";
    int choice = InputInt_10();
    if (choice == 1)
    {
        std::istringstream iss(std::move(occurrence));
        std::vector<std::string> found;

        int max_count = 0;

        // now simply extract strings until you reach end-of-file.
        while (iss >> occurrence)
        {
            int tmp = ++ss[occurrence];
            if (tmp == max_count)
            {
                found.push_back(occurrence);
            }
            else if (tmp > max_count)
            {
                max_count = tmp;
                found.clear();
                found.push_back(occurrence);
            }
        }

        for (auto &[id, s] : ss)
            std::cout << s.first << " : " << s.second << "\n";
    }
    else if (choise == 2)
    {
    }
    else
    {
        return 0;
    }
    */
    return 0;
}

int main()
{
    unordered_map<int, pipe> ps;
    unordered_map<int, station> ss;
    while (1)
    {
        menu();
        switch (InputNum<int>(0, 10))
        {
        case (1):
        {
            // system("CLS");
            pipe p;
            p.InputPipe(p);
            ps.insert(make_pair(p.get_ID(), p.get_Pipe()));
            break;
        }
        case (2):
        {
            station s;
            s.InputKS(s);
            ss.insert(make_pair(s.get_ID(), s.get_KS()));
            break;
        }
        case (3):
        {
            for (auto &[id, p] : ps)
                cout << p;
            for (auto &[id, s] : ss)
                cout << s;
            break;
        }
        case (4):
        {
            pipe p;
            p.EditPipe(ps);
            break;
        }
        case (5):
        {
            station s;
            s.EditKS(ss);
            break;
        }
        case (6):
        {
            pipe p;
            p.delPipe(ps);
            break;
        }
        case (7):
        {
            station s;
            s.delKS(ss);
            break;
        }
        case (8):
        {
            string file;
            cout << "Input name file like 'something.txt'\n";
            cin >> file;
            fout(file, ps, ss);
            break;
        }
        case (9):
        {
            string file;
            cout << "Input name file like 'something.txt'\n";
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // getline(cin, file);
            cin >> file;
            fin(file, ps, ss);
            break;
        }
        case (10):
        {

            // find(ps, ss);
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