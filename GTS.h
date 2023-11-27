#pragma once
#include <unordered_set>
#include <vector>
#include "pipe.h"
#include "station.h"

struct path
{
    int id_in;
    int id_out;
    int id_link;

    friend std::ofstream &operator<<(std::ofstream &outf, const path &path);
    friend std::ifstream &operator>>(std::ifstream &fin, path &path);
};


class GTS
{
private:
	std::unordered_map<int, pipe> ps;
	std::unordered_map<int, station> ss;
	std::unordered_set<int> id_used_edges;
    std::unordered_set<int> id_used_vertexes;
    std::vector<path> paths;

public:
	void addPipe();
	void addKS();

	void out_data();

    void findPipes();
    void findKSs();

    void fileIn();
    void fileOut();

	void link();
	void Graph_and_Topsort();


    void del_or_edit_ps(std::unordered_set <int> &found_ids, std::unordered_map<int, pipe> &map);
};


typedef std::pair<int, int> Pair;

class Graph
{
public:
    std::vector<std::vector<Pair>> adjList; // список смежности

    Graph(std::vector<path> const &paths, int n) //Создать граф
    {
        //adjList.clear();
        adjList.resize(n); // n элементов path ()-->()

        // добавляем paths
        for (auto &path : paths)
        {
            int src = path.id_in;
            int dest = path.id_out;
            int weight = path.id_link;

            adjList[src].emplace_back(dest, weight);

        }
    }

//    void addEdge(int src, int dest, int weight)
//    {
//        adjList[src].emplace_back(dest, weight);
//    }
};