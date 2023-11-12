#include "utils.h"
#include "pipe.h"
#include "station.h"
// #include <chrono>
#include <sstream>
using namespace std;

void menu()
{
    std::cout << "\n========================================================\n"
              << "________________________Menu____________________________\n\n"
              << "        select one of the following items:\n"
              << "1. Add pipe                         5. View all objects\n"
              << "2. Add KS                           6. Save\n"
              << "3. Find(edit/del) pipes             7. Load\n"
              << "4. Find(edit/del) stations          0. Exit\n"
              << "__> ";
}

bool ID_Present(std::vector<int> &vector,int value)
{
    int k=0;
    for(auto kv : vector)
    {    
        if (kv == value)
        {
            ++k;
        }
    }
    if (k == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

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

//================================================== find & del or edit ===============================================

vector<int> select_ids(std::vector<int> &res)
{
    // select ids in found pipes
    //
    stringstream ss;
    string str;
    int id;
    vector<int> selected;
    vector<int> notfound;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, str);
    std::cerr << str;
    ss << str;
    while(ss >> id)
    {
        if(ID_Present(res, id))
        {
            selected.push_back(id);
        }
        else
        {
            notfound.push_back(id);
        }
    }
    cout<<"selected ids\n";
    for(auto el : selected) cout << el << ' ';
    cout<<"\n";
    cout<<"not found ids\n";
    for(auto el : notfound) cout << el << ' ';
    cout<<"\n";

    return selected;
}

void del_or_edit_ps(vector <int> &res, unordered_map<int, pipe> &ps)
{
    for (int id : res)
    {
        std::cout << ps.at(id);
    }
    cout<<"\nids\n";
    for (int id : res)
    {
        std::cout << id<<", ";
    }
    std::cout << "\n";

    //choise select ids or exit

    std::cout << "select choise:\n"
        << "1. exit menu\n"
        << "2. edit pipes\n"
        << "3. del pipes\n"
        << "__> ";
    int choice2 = InputNum<int>(1, 3);
    
    pipe p;
    vector<int> selected;
    int id;

    if (choice2 == 1)
    {
        return;
    }
    else if (choice2 == 2)
    {
        
        std::cout << "select ids pipe to edit\n";
        selected=select_ids(res);

        for(int id : selected)
        {
            std::cout<< "\nInput mending(0/1) for "<<id<<" id pipe\n"
            <<"__> ";
            p=ps.at(id);
            p.set_remont(InputNum<bool>(0,1));
            ps[id]=p;
        }
    }
    else
    {
        std::cout << "select ids pipe to delete\n";
        selected=select_ids(res);

        for(int id : selected)
        {
            ps.erase(id);
        }
    
    }
}

void del_or_edit_ss(vector <int> &res, unordered_map<int, station> &ss)
{
    for (int id : res)
    {
        std::cout << ss.at(id);
    }
    cout<<"\nids\n";
    for (int id : res)
    {
        std::cout << id<<", ";
    }
    std::cout << "\n";

    //choise select ids or exit

    std::cout << "select choise:\n"
        << "1. exit menu\n"
        << "2. edit stations\n"
        << "3. del stations\n"
        << "__> ";
    int choice2 = InputNum<int>(1, 3);
    
    station s;
    vector<int> selected;
    int id;

    if (choice2 == 1)
    {
        return;
    }
    else if (choice2 == 2)
    {
        
        std::cout << "select ids station to edit\n";
        selected=select_ids(res);

        for(int id : selected)
        {
            std::cout<< "\nInput working cex for "<<id<<" id station\n"
            <<"__> ";
            s=ss.at(id);
            s.set_workingcex(InputNum<int>(0,100000));
            ss[id]=s;
        }
    }
    else
    {
        std::cout << "select ids pipe to delete\n";
        selected=select_ids(res);

        for(int id : selected)
        {
            ps.erase(id);
        }
    
    }
}

//================================================== filters ===============================================

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
        vector<int> res=find(ps, CheckByName, name);
        if (res.size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ps(res, ps); 
        }
    }
    else if (choice == 2)
    {
        std::cout << "Input remont pipe\n"
        << "__> ";
        bool remont = InputNum<bool>(0, 1);
        vector<int> res=find(ps, CheckByRemont, remont);
        if (res.size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ps(res, ps);
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
        vector <int> res = find(ss, CheckByName2, name);
        if (res.size() == 0)
        {
            cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ss(res, ss);
        }
    }
    else if (choice == 2)
    {
        cout << "Input persent not working cex KS\n"
             << "__> ";
        int persent = InputNum<int>(0, 100);
        vector <int> res = find(ss, CheckByWCex, persent);
        if (res.size() == 0)
        {
            cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ss(res, ss);
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
        switch (InputNum<int>(0, 7))
        {
            case (1):
            {
                addPipe(ps);
                break;
            }
            case (2):
            {
                addKS(ss);
                break;
            }
            case (3):
            {
                findPipes(ps);
                break;
            }
            case (4):
            {
                findKSs(ss);
                break;
            }
            case (5):
            {
                for (auto &[id, p] : ps)
                    cout << p;
                for (auto &[id, s] : ss)
                    cout << s;
                break;
            }
            case (6):
            {
                string file;
                cout<< "Input name file like 'something.txt'\n"
                    << "__> ";
                cin >> file;
                fileOut(file, ps, ss);
                break;
            }
            case (7):
            {
                string file;
                cout<< "Input name file like 'something.txt'\n"
                    << "__> ";
                cin >> file;
                fileIn(file, ps, ss);
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