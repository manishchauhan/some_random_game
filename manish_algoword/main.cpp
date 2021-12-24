#include<iostream>
#include<memory>
#include "BinarySearchNameSpace.h"
#include<utility>

using namespace std;
using namespace BinarySearchNameSpace;
int main()
{
	std::vector<int> range = { 0,8,25 };
	//b_search(range);
	//b_searchFirstAndLast(range);
	BinarySearchNameSpace::howManyTimesArrayRotated();
	return 0;
}