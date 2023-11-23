#include "GTS.h"

#include "pipe.h"
#include "station.h"
#include "utils.h"

#include <sstream>

#include <stack>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>

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
    
    std::unordered_set<int> selected_ids;
    std::unordered_set<int> notfound_ids;

    int id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, str);
    std::cerr << str;
    ss << str;
    while(!ss.eof())
    {
        char c=(char) ss.peek();
        if (isdigit(c))
        {
            ss>>id;
            if(ID_is_Present(found_ids, id))
                selected_ids.insert(id);
            else
                notfound_ids.insert(id);
        }
        else
        {
            ss.ignore();
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

bool CheckByD(const pipe &p, int param)
{
    if (p.get_d() == param)
        return true;
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

void GTS::find_link()
{
    path path;
    station&s=s;

    std::cout << "Input id first station\n" << "__> ";
    path.id_in=InputNum(1,s.get_newID());

    std::cout << "Input id second station\n" << "__> ";
    path.id_out=InputNum(1,s.get_newID());

    std::cout << "Input diameter pipe\n" << "__> "; 
    int dia;
    dia=InputNum(500,1400);//500 700 1000 1400

    std::unordered_set<int> found_ids;
    found_ids=find(ps, CheckByD, dia);

    if (found_ids.size() == 0)
    {
        std::cout<<"Pipe not found\nPlease create it\n";
        GTS::addPipe();
    }
    else
    {
        std::cout<<"found ids:  \n";
        for(auto el : found_ids) std::cout << el << ' ';
        std::cout<<"\n";

        path.id_link = *(found_ids.begin());

        vector_of_path.push_back(path);

        count_nodes=count_nodes+2;
        id_used_edges.insert(path.id_link);

        //count nodes в файл

        std::cout<<"Your path is:\n"<<"KS:(id:"<<path.id_in<<")  ---Pipe:(id:"<<path.id_link<<")--->  KS:(id:"<<path.id_out<<")\n";

    }
}


//================================================== input/output file ===============================================

std::ofstream &operator<<(std::ofstream &outf, const path &path)
{
    outf << "-\n"
         << path.id_in << "\n"
         << path.id_out << "\n"
         << path.id_link << "\n";
    return outf;
}
std::ifstream &operator>>(std::ifstream &fin, path &path)
{
    fin >> path.id_in >> path.id_out >> path.id_link;
    return fin;
}


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

        for (auto el : vector_of_path)
        {
            outf << el;
        }

        for (auto el : id_used_edges)
        {
            outf <<"e\n"<< el;
        }

        outf <<"n\n"<< count_nodes;

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
        path path;
        int id_node, id_edge, a, b;

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
            if (flag == "-")
            {    
                fin >> path;
                vector_of_path.push_back(path);
            }
            if (flag == "e")
            { 
                fin >> id_edge;
                id_used_edges.insert(id_edge);
            }
            if (flag == "n")
            {   
                fin >> count_nodes;
            }

        }
    }
    fin.close();
}


void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (Pair v: graph.adjList[i])
        {
            std::cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        std::cout << "\n";
    }
}

#include <queue>

void topsort(Graph const &graph, int n)
{
    std::vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (Pair v: graph.adjList[i])
        {
            inDegree[v.first]++;
        }
    }
    std::queue <int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for (Pair v: graph.adjList[u])
        {
            inDegree[v.first]--;
            if (inDegree[v.first] == 0)
            {
                q.push(v.first);
            }
        }
    }

}

void GTS::Print_and_Topsort()
{
    //int n = 8;
    std::vector<path> paths;
    for (auto el : vector_of_path)  paths.push_back(el);

    // построить Graph
    Graph graph(paths, count_nodes);

    printGraph(graph, count_nodes);

    // Топологическая сортировка
    topsort(graph, count_nodes);

}




