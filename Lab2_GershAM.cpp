#include "utils.h"
#include "pipe.h"
#include "station.h"
#include <vector>
// #include <chrono>

using namespace std;

void menu()
{
    std::cout << "\n============================================\n"
              << "__________________Menu______________________\n\n"
              << "select one of the following items:\n"
              << "Add :[ 1. pipe | 2. KS ]\n"
              << "Edit:[ 4. pipe | 5. KS ]\n"
              << "Del :[ 6. pipe | 7. KS ]\n"
              << "Find:[ 10. pipes | 11. KSs ]\n"
              << "3. View all objects\n"
              << "8. Save\n"
              << "9. Load\n"
              << "0. Exit\n";
};

//================================================== input/output file ===============================================

void fileOut(const string &file, const unordered_map<int, pipe> &ps, const unordered_map<int, station> &ss)
{
    ofstream outf(file);
    if (outf.is_open())
    {
        outf << pipe::get_newID() << "\n"
             << station::get_newID() << "\n";
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

void fileIn(const string &file, unordered_map<int, pipe> &ps, unordered_map<int, station> &ss)
{
    ifstream fin(file);
    string flag;
    if (fin.is_open())
    {
        pipe p;
        station s;
        int a, b;
        fin >> a >> b;
        p.set_newID(a);
        s.set_newID(b);
        while (getline(fin, flag))
        {
            if (flag == "p")
            {
                fin >> p;
                ps.insert(make_pair(p.get_ID(), p));
            }
            if (flag == "s")
            {
                fin >> s;
                ss.insert(make_pair(s.get_ID(), s));
            }
        }
    }
    fin.close();
}

template <typename T>
using Filter = bool (*)(const pipe &p, T param);

bool CheckByName(const pipe &p, string param)
{
    if ((p.get_name_p()).find(param) == std::string::npos)
        return 0;
    else
        return 1;
}
bool CheckByRemont(const pipe &p, bool param)
{
    return p.get_remont() == param;
}

template <typename S>
using Filter2 = bool (*)(const station &s, S param);
bool CheckByName2(const station &s, string param)
{
    if ((s.get_name_s()).find(param) == std::string::npos)
        return 0;
    else
        return 1;
}
bool CheckByWCex(const station &s, int param)
{
    return (s.get_cex() / s.get_workingcex()) * 100 == param;
}

template <typename T>
vector<int> find(unordered_map<int, pipe> &ps, Filter<T> f, T param)
{
    vector<int> res;
    for (auto &[id, p] : ps)
    {
        if (f(p, param))
            res.push_back(id);
    }
    return res;
}

template <typename S>
vector<int> find(unordered_map<int, station> &ss, Filter2<S> f, S param)
{
    vector<int> res;
    for (auto &[id, s] : ss)
    {
        if (f(s, param))
            res.push_back(id);
    }
    return res;
}

void findPipes(std::unordered_map<int, pipe> &ps)
{
    std::cout << "select variable to find:\n"
              << "1. name pipe\n"
              << "2. remont pipe\n"
              << "__> ";
    int choice = InputNum<int>(1, 2);
    if (choice == 1)
    {
        std::cout << "Input name pipe\n"
                  << "__> ";
        std::string name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, name);
        std::cerr << name;
        for (int i : find(ps, CheckByName, name))
        {
            std::cout << ps.at(i);
        }
        if (find(ps, CheckByName, name).size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
    }
    else if (choice == 2)
    {
        std::cout << "Input remont pipe\n"
                  << "__> ";
        bool remont = InputNum<bool>(0, 1);
        for (int i : find(ps, CheckByRemont, remont))
        {
            std::cout << ps.at(i);
        }
        if (find(ps, CheckByRemont, remont).size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
    }
}

void findKSs(unordered_map<int, station> &ss)
{
    cout << "select variable to find:\n"
         << "1. name KS\n"
         << "2. persent not working cex KS\n"
         << "__> ";
    int choice = InputNum<int>(1, 2);
    if (choice == 1)
    {
        cout << "Input name KS\n"
             << "__> ";
        string name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        std::cerr << name;
        for (int i : find(ss, CheckByName2, name))
        {
            cout << ss.at(i);
        }
        if (find(ss, CheckByName2, name).size() == 0)
        {
            cout << "Not found \\_(._.)_/ \n";
        }
    }
    else if (choice == 2)
    {
        cout << "Input persent not working cex KS\n"
             << "__> ";
        int persent = InputNum<int>(0, 100);
        for (int i : find(ss, CheckByWCex, persent))
        {
            cout << ss.at(i);
        }
        if (find(ss, CheckByWCex, persent).size() == 0)
        {
            cout << "Not found \\_(._.)_/ \n";
        }
    }
}
//=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=---=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=    MAIN   -=-=-=-=---=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=---=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main()
{
    redirect_output_wrapper cerr_out(cerr);
    // string time = std::format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
    ofstream logfile("log_" /*+ time*/);
    if (logfile)
        cerr_out.redirect(logfile);

    unordered_map<int, pipe> ps;
    unordered_map<int, station> ss;
    while (1)
    {
        menu();
        switch (InputNum<int>(0, 11))
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
            cout << "Input name file like 'something.txt'\n"
                 << "__> ";
            cin >> file;
            fileOut(file, ps, ss);
            break;
        }
        case (9):
        {
            string file;
            cout << "Input name file like 'something.txt'\n"
                 << "__> ";
            cin >> file;
            fileIn(file, ps, ss);
            break;
        }
        case (10):
        {
            findPipes(ps);
            break;
        }
        case (11):
        {
            findKSs(ss);
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