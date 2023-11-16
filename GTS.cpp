#include "GTS.h"

#include "pipe.h"
#include "station.h"
#include "utils.h"

#include <sstream>

void GTS::addPipe()
{
    pipe pipe;
    std::cin>>pipe;
    ps.insert(std::make_pair(pipe.get_ID(), pipe));
}

void GTS::addKS()
{
    station station;
    std::cin>>station;
    ss.insert(std::make_pair(station.get_ID(), station));
}

void GTS::out_data()
{
    for (auto &[id, p] : ps)
        std::cout << p;
    for (auto &[id, s] : ss)
        std::cout << s;
}



bool ID_is_Present(std::unordered_set<int> &unordered_set,int value)
{
    int k=0;
    for(auto kv : unordered_set)
    {    
        if (kv == value)
            ++k;
    }
    if (k == 0)
        return false;
    else
        return true;
}

//================================================== find & del or edit ===============================================

std::unordered_set<int> select_ids(std::unordered_set<int> &found_ids)
{
    // select ids in found pipes
    //
    std::stringstream ss;
    std::string str;
    int id;
    std::unordered_set<int> selected_ids;
    std::unordered_set<int> notfound_ids;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, str);
    std::cerr << str;
    ss << str;
    while(ss >> id)
    {
        if(ID_is_Present(found_ids, id))
        {
            selected_ids.insert(id);
        }
        else
        {
            notfound_ids.insert(id);
        }
    }
    std::cout<<"selected ids\n";
    for(auto el : selected_ids) std::cout << el << ' ';
    std::cout<<"\n";
    std::cout<<"not found ids\n";
    for(auto el : notfound_ids) std::cout << el << ' ';
    std::cout<<"\n";

    return selected_ids;
}

void del_or_edit_ps(std::unordered_set <int> &found_ids, std::unordered_map<int, pipe> &ps)
{
    for (int id : found_ids)
    {
        std::cout << ps.at(id);
    }
    std::cout<<"\nids\n";
    for (int id : found_ids)
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
    
    //pipe& p = p;

    std::unordered_set<int> selected_ids;
    int id;

    if (choice2 == 1)
    {
        return;
    }
    else if (choice2 == 2)
    {
        
        std::cout << "select ids pipe to edit\n";
        selected_ids=select_ids(found_ids);
        std::cout<< "\nInput mending(0/1) for pipes\n"
            <<"__> ";
        bool rem=InputNum<bool>(0,1);

        for(int id : selected_ids)
        {
            ps.at(id).set_remont(rem);
        }
    }
    else
    {
        std::cout << "select ids pipe to delete\n";
        selected_ids=select_ids(found_ids);

        for(int id : selected_ids)
        {
            ps.erase(id);
        }
    
    }
}

void del_or_edit_ss(std::unordered_set <int> &found_ids, std::unordered_map<int, station> &ss)
{
    for (int id : found_ids)
    {
        std::cout << ss.at(id);
    }
    std::cout<<"\nids\n";
    for (int id : found_ids)
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
    
    //station& s = s;
    std::unordered_set<int> selected_ids;
    int id;

    if (choice2 == 1)
    {
        return;
    }
    else if (choice2 == 2)
    {
        
        std::cout << "select ids station to edit\n";
        selected_ids=select_ids(found_ids);
        std::cout<< "\nInput working cex for stations\n"
            <<"__> ";
        int workcex=InputNum<int>(0,100000);


        for(int id : selected_ids)
        {
            
            ss.at(id).set_workingcex(workcex);
        }
    }
    else
    {
        std::cout << "select ids pipe to delete\n";
        selected_ids=select_ids(found_ids);

        for(int id : selected_ids)
        {
            ss.erase(id);
        }
    
    }
}

//================================================== filters ===============================================

template <typename T>
using Filter = bool (*)(const pipe &p, T param);

bool CheckByName(const pipe &p, std::string param)
{
    if ((p.get_name_p()).find(param) == std::string::npos)
        return false;
    else
        return true;
}
bool CheckByRemont(const pipe &p, bool param)
{
    if (p.get_remont() == param)
        return true;
    else
        return false;
}

template <typename S>
using Filter2 = bool (*)(const station &s, S param);
bool CheckByName2(const station &s, std::string param)
{
    if ((s.get_name_s()).find(param) == std::string::npos)
        return false;
    else
        return true;
}
bool CheckByWCex(const station &s, int param)
{
    if ( ((int)(s.get_workingcex() / s.get_cex())) * 100 <= param)
    {
        return true;
    }
    else
        return false;
}

template <typename T>
std::unordered_set<int> find(std::unordered_map<int, pipe> &ps, Filter<T> f, T param)
{
    std::unordered_set<int> found_ids;
    for (auto &[id, p] : ps)
    {
        if (f(p, param))
            found_ids.insert(id);
    }
    return found_ids;
}

template <typename S>
std::unordered_set<int> find(std::unordered_map<int, station> &ss, Filter2<S> f, S param)
{
    std::unordered_set<int> found_ids;
    for (auto &[id, s] : ss)
    {
        if (f(s, param))
            found_ids.insert(id);
    }
    return found_ids;
}

void GTS::findPipes()
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
        std::unordered_set<int> found_ids=find(ps, CheckByName, name);
        if (found_ids.size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ps(found_ids, ps); 
        }
    }
    else if (choice == 2)
    {
        std::cout << "Input remont pipe\n"
        << "__> ";
        bool remont = InputNum<bool>(0, 1);
        std::unordered_set<int> found_ids=find(ps, CheckByRemont, remont);
        if (found_ids.size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ps(found_ids, ps);
        }
    }
}


void GTS::findKSs()
{
    std::cout << "select variable to find:\n"
         << "1. name KS\n"
         << "2. persent not working cex KS\n"
         << "__> ";
    int choice = InputNum<int>(1, 2);
    if (choice == 1)
    {
        std::cout << "Input name KS\n"
             << "__> ";
        std::string name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, name);
        std::cerr << name;
        std::unordered_set <int> found_ids = find(ss, CheckByName2, name);
        if (found_ids.size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ss(found_ids, ss);
        }
    }
    else if (choice == 2)
    {
        std::cout << "Input persent not working cex KS\n"
             << "__> ";
        int persent = InputNum<int>(0, 100);
        std::unordered_set <int> found_ids = find(ss, CheckByWCex, persent);
        if (found_ids.size() == 0)
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ss(found_ids, ss);
        }
    }
}


//================================================== input/output file ===============================================

void GTS::fileOut()
{
    std::string file;
    std::cout<< "Input name file like 'something.txt'\n"<< "__> ";
    std::cin >> file;
    std::ofstream outf(file);
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

void GTS::fileIn()
{
    std::string file;
    std::cout<< "Input name file like 'something.txt'\n"<< "__> ";
    std::cin >> file;
    std::ifstream fin(file);
    std::string flag;
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
                ps.insert(std::make_pair(p.get_ID(), p));
            }
            if (flag == "s")
            {
                fin >> s;
                ss.insert(std::make_pair(s.get_ID(), s));
            }
        }
    }
    fin.close();
}





