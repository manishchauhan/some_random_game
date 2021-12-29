#pragma once
#include<iostream>
#include<utility>
#include<vector>
#include"BinarySearchSoution.h"
using namespace std;
namespace BinarySearchNameSpace
{
	

	void PrintforBinary(pair<bool, int> pair);
	//normal----------------------------------------
	void b_search(const std::vector<int>& vectors);

	//last and first search-----------------------------------------
	void b_searchFirstAndLast(const std::vector<int>& vectors);


	//ceil value
	void ceil(const std::vector<int>& vectors);
	
	//ceil value
	void floor(const std::vector<int>& vectors);
	
	void howManyTimesArrayRotated();
	void Search_in_rotatedArray();
};

