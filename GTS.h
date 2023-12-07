#pragma once
#include <unordered_set>
#include <vector>
#include "pipe.h"
#include "station.h"

struct path
{
    int id_in;
    int id_out;
    double weight;

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
    std::unordered_map<int,path> graph;

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

    void MaxFlow();

    std::vector<std::vector <int>> make_graph_no_weight();
    void min_path();

    void del_or_edit_ps(std::unordered_set <int> &found_ids);
    void del_or_edit_ss(std::unordered_set <int> &found_ids);


};
