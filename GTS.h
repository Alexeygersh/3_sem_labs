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
	std::vector<path> vector_of_path;
	std::unordered_set<int> id_used_edges;
	int count_nodes;

public:
	void addPipe();
	void addKS();

	void out_data();

    void findPipes();
    void findKSs();

    void fileIn();
    void fileOut();

	void find_link();

	void Print_and_Topsort();
};



typedef std::pair<int, int> Pair;

class Graph
{
public:
    std::vector<std::vector<Pair>> adjList; // список смежности

    Graph(std::vector<path> const &paths, int n)
    {
        adjList.resize(n); // n элементов path

        // добавляем ребра
        for (auto &path : paths)
        {
            int src = path.id_in;
            int dest = path.id_out;
            int weight = path.id_link;

            // вставляем в конце
            adjList[src].push_back(std::make_pair(dest, weight));


            //неор adjList[dest].push_back(make_pair(src, weight));
        }
    }
};