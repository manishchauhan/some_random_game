#pragma once
#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
class RecursionAndMemo
{
	
public:

	RecursionAndMemo() {};
	~RecursionAndMemo() {};
	long long int  fibRecur(int number);
	long long int  powRecur(int number,int power);
	long long int  fibRecurMemo(long long number,  std::unordered_map<long long, long long> &memoMap);
	void displayfibRecur(long long number);
	int LongestSubSeq(const std::string &first,const std::string &second,int indexA,int indexB);
	int LongestSubStr(const std::string& first, const std::string& second, int indexA, int indexB,int count);
	void displayLongestSubSeq();
	void displayLongestSubStr();
	//substring
	//sub sequence
	int LongestSubSeqDynamic(const std::string& first, const std::string& second, int indexA, int indexB);
};

