#include<iostream>
#include<memory>
#include "BinarySearchNameSpace.h"
#include "AdQueue.h"
#include<utility>
#include<vector>
#include "RecursionAndMemo.h"
using namespace std;
using namespace BinarySearchNameSpace;
int main()
{
	unique_ptr<RecursionAndMemo> recursionAndMemo = std::make_unique<RecursionAndMemo>();
	recursionAndMemo->displayLongestSubSeq();
	recursionAndMemo->displayLongestSubSeqDynamic();
	cout << recursionAndMemo->checkCommonSubstring("x","hell") << endl;
	//vector<int> vec = { 11,2,133,7,9 };
	//unique_ptr<AdQueue<int>> adQueue = std::make_unique < AdQueue<int>>();
	//adQueue->maxQueue(vec);
	//adQueue->MinQueue(vec);
	//adQueue->customSolution();
	return 0;
}