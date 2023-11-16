#pragma once
#include <unordered_set>

#include "pipe.h"
#include "station.h"

class GTS
{
private:
	std::unordered_map<int, pipe> ps;
	std::unordered_map<int, station> ss;

public:
	void addPipe();
	void addKS();

	void out_data();

    void findPipes();
    void findKSs();

    void fileIn();
    void fileOut();

};