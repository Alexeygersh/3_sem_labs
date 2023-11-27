#include "GTS.h"
#include "pipe.h"
#include "station.h"
#include "utils.h"
#include <sstream>
#include <stack>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

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

void Remove_link(std::vector<path> & paths, int id)
{
    for (auto it = paths.begin(); it != paths.end(); ++it)
    {
        if (it->id_link == id)
        {
            paths.erase(it);
            break;
        }
    }
}



void GTS::del_or_edit_ps(std::unordered_set <int> &found_ids, std::unordered_map<int, pipe> &pipes)
{
    for (int id : found_ids)
    {
        std::cout << pipes.at(id);
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
        bool rem=InputNum<bool>(false,true);

        for(int id : selected_ids)
        {
            pipes.at(id).set_remont(rem);
        }
    }
    else
    {
        std::cout << "select ids pipe to delete\n";
        selected_ids=select_ids(found_ids);


        std::unordered_set<int> used(selected_ids.size()+id_used_edges.size());
        for (int i : selected_ids)
        {
            if (id_used_edges.count(i))
            {
                used.insert(i);
            }
        }

        //проверка на то что труба состоит в графе
        if (!used.empty())
        {
            std::cout<<"Celected pipe(s) with id(s):  ";
            for (int i : used) std::cout<<i<<" ";
            std::cout<<"  used in GTS !\n";
            std::cout<<"Do you rly want to delete pipe(s)?\n(Y=1/n=0)\n"<<"__>";
            int a= InputNum(0,1);
            if (a)
            {
                for(int id : selected_ids)
                    pipes.erase(id);
                // удалить связ
                for(int id : used)
                {
                    id_used_edges.erase(id);

                    for (auto it = paths.begin(); it != paths.end();)
                    {
                        if (it->id_link == id)
                        {
                            it = paths.erase(it);
                        }
                        else
                        {
                            it++;
                        }
                    }


                    for (auto el : id_used_edges) std::cout<<el<<" ";
                    std::cout<<"\n";
                    for (auto el : paths) std::cout<<el.id_link<<" ";
                    std::cout<<"\n";

                    //  if (path.id_link == id)
                    //  {
                    //      Remove(vector_of_path, id);
                    //  }


                }
                // пересоздать граф
                GTS::Graph_and_Topsort();

            }
            else
            {
                return;
            }

        }
        else
        {
            for(int id : selected_ids)
                pipes.erase(id);
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
        if (found_ids.empty())
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
        bool rem= InputNum<bool>(false, true);
        std::unordered_set<int> found_ids=find(ps, CheckByRemont, rem);
        if (found_ids.empty())
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
        if (found_ids.empty())
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
        if (found_ids.empty())
        {
            std::cout << "Not found \\_(._.)_/ \n";
        }
        else
        {
            del_or_edit_ss(found_ids, ss);
        }
    }
}

void GTS::link()
{
    path path{};

    std::cout << "Input id first station\n" << "__> ";
    path.id_in=InputNum(1,station::get_newID());
    id_used_vertexes.insert(path.id_in);

    std::cout << "Input id second station\n" << "__> ";
    path.id_out=InputNum(1,station::get_newID());
    id_used_vertexes.insert(path.id_out);

    std::cout << "Input diameter pipe\n" << "__> "; 

    int dia=InputNum(500,1400);//500 700 1000 1400

    std::unordered_set<int> found_ids=find(ps, CheckByD, dia);

    if (found_ids.empty()) //Если трубы с таким диаметром нет
    {
        std::cout<<"Pipe not found\nPlease create it\n";
        GTS::addPipe();

        //берём Id созданной трубы
        int id=(pipe::get_newID())-1;

        id_used_edges.insert(id);
        path.id_link = id;

        //path.id_link = *(found_ids.begin());

    }
    else
    {
        std::cout<<"found ids:  \n";
        for(auto el : found_ids) std::cout << el << ' ';
        std::cout<<"\n";

        for (auto el : found_ids) //ищем трубу с таким диаметром
        {
            if (!ID_is_Present(id_used_edges, el)) //если труба не используется
            {
                id_used_edges.insert(el);
                path.id_link = el;
                break;
            }
        }


        //Если найденная труба с данным диаметром есть, но используется
        if (path.id_link == 0)
        {
            std::cout<<"All pipes with this diameter are used\nPlease create it\n";
            GTS::addPipe();

            //берём Id созданной трубы
            int id=(pipe::get_newID())-1;

            id_used_edges.insert(id);
            path.id_link = id;
        }
    }

    paths.push_back(path);/////

    std::cout<<"Your path is:\n"<<"KS:(id:"<<path.id_in<<")  ---Pipe:(id:"<<path.id_link<<")--->  KS:(id:"<<path.id_out<<")\n";

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

        for (auto el : paths)
        {
            outf << el<<"\n";
        }

        for (auto el : id_used_edges)
        {
            outf <<"e\n"<< el<<"\n";
        }

        for (auto el : id_used_vertexes)
        {
            outf <<"v\n"<< el<<"\n";
        }

    }
    outf.close();
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
        path path{};
        int id_edge, id_vertex, a, b;

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
                paths.push_back(path);
            }
            if (flag == "e")
            {
                fin >> id_edge;
                id_used_edges.insert(id_edge);
            }
            if (flag == "v")
            {
                fin >> id_vertex;
                id_used_vertexes.insert(id_vertex);
            }

        }
    }
    fin.close();
}




void printGraph(Graph const &graph, int n)
{
    std::cout << "\n(in,out,weight)\n";
    for (int i = 0; i < n; i++)
    {
        for (Pair v: graph.adjList[i])
        {
            std::cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        std::cout << "\n";
    }
}


void dfs(std::vector<std::vector <int>> &graph, int v, std::vector<int> &visited, std::vector <int> &order)
{
    visited[v] = 1;
    for (int to: graph[v])
        if(!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
}

void topologicalSort(int vertex_count,int edge_count,Graph const &graph)
{
    std::vector<std::vector <int>> gh(vertex_count);

    //Отсеивваем веса для удобной работы с графом
    for (int i = 0; i < edge_count; i++)
    {
        for (Pair v: graph.adjList[i])
        {
            int from, to;
            from=i-1;
            to=v.first-1;

            gh[from].push_back(to);
        }
    }

    std::vector<int> visited(vertex_count, 0);
    std::vector<int> order;
    for (int i = 0; i < vertex_count; i++)
    {
        if (!visited[i]) {
            dfs(gh, i, visited, order);

        }
    }
    reverse(order.begin(), order.end());

    for (int i:order)
        std::cout<<i+1<<" ";

}


void GTS::Graph_and_Topsort()
{
    //int n = 8;
    int edge_count = id_used_edges.size();
    int n=id_used_vertexes.size();

    // построить граф
    Graph graph(paths, n);

    printGraph(graph, n);

    // Топологическая сортировка
    //topsort(graph, n);
    topologicalSort(n, edge_count, graph);

}




