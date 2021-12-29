#include<iostream>
#include<memory>
#include "BinarySearchNameSpace.h"
#include "AdQueue.h"
#include<utility>
#include<vector>
using namespace std;
using namespace BinarySearchNameSpace;
int main()
{
	vector<int> vec = { 11,2,133,7,9 };
	unique_ptr<AdQueue<int>> adQueue = std::make_unique < AdQueue<int>>();
	//adQueue->maxQueue(vec);
	//adQueue->MinQueue(vec);
	adQueue->customSolution();
	return 0;
}