#include "BinarySearchNameSpace.h"
void BinarySearchNameSpace::PrintforBinary(pair<bool, int> pair)
{
	std::cout << "status is " << pair.first << " " << "end is  " << pair.second << endl;
}

//normal----------------------------------------
void BinarySearchNameSpace:: b_search(const std::vector<int>& vectors)
{
	//for simple binary search
	std::vector<int> myVector = { 1,2,3,4,11,21,199 };

	for (int i = 0; i < vectors.size(); i++)
	{
		unique_ptr<BinarySearchSoution<int>> binarySearchSoution = std::make_unique < BinarySearchSoution<int>>();
		pair<bool, int> result = binarySearchSoution->Search(myVector, vectors.at(i));
		PrintforBinary(result);
	}

}
//last and first search-----------------------------------------
void BinarySearchNameSpace::b_searchFirstAndLast(const std::vector<int>& vectors)
{
	//for simple binary search
	std::vector<int> myVector = { 1,2,2,2,2,22,11,11,22,23 };

	for (int i = 0; i < vectors.size(); i++)
	{
		unique_ptr<BinarySearchSoution<int>> binarySearchSoution = std::make_unique < BinarySearchSoution<int>>();
		pair<bool, int> result = binarySearchSoution->SearchFirst(myVector, vectors.at(i));
		PrintforBinary(result);
	}
}

//ceil value
void BinarySearchNameSpace::ceil(const std::vector<int>& vectors)
{
	//for simple binary search
	std::vector<int> myVector = { 1,7,9,11,23,51,67,89 };

	for (int i = 0; i < vectors.size(); i++)
	{
		unique_ptr<BinarySearchSoution<int>> binarySearchSoution = std::make_unique < BinarySearchSoution<int>>();
		pair<bool, int> result = binarySearchSoution->Ceil(myVector, vectors.at(i));
		PrintforBinary(result);
	}
}
//ceil value
void BinarySearchNameSpace::floor(const std::vector<int>&vectors)
{
	//for simple binary search
	std::vector<int> myVector = { 1,7,9,11,23,51,67,89 };

	for (int i = 0; i < vectors.size(); i++)
	{
		unique_ptr<BinarySearchSoution<int>> binarySearchSoution = std::make_unique < BinarySearchSoution<int>>();
		pair<bool, int> result = binarySearchSoution->floor(myVector, vectors.at(i));
		PrintforBinary(result);
	}
}
void BinarySearchNameSpace::howManyTimesArrayRotated()
{
	std::vector<vector<int>> vector = { {15,22,1,2,3,4,5},{1,2,3,4,5},{21,22,1,2,3,4,5} };
	unique_ptr<BinarySearchSoution<int>> binarySearchSoution = std::make_unique < BinarySearchSoution<int>>();
	for (auto x : vector)
	{
	
		int index = binarySearchSoution->howManyTimes(x);
		std::cout << "Printed..." << index << "as many times..." << std::endl;
	}
	

}