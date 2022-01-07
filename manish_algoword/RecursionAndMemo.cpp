#include "RecursionAndMemo.h"


long long int RecursionAndMemo::fibRecur(int number)
{
	if (number < 2)
		return 1;
	return fibRecur(number - 1) + fibRecur(number - 2);
}

long long int RecursionAndMemo::powRecur(int number,int power)
{
	if (power < 1)
		return 1;
	return number * powRecur(number, --power);
}


long long int RecursionAndMemo::fibRecurMemo(long long number,  std::unordered_map<long long, long long> &memoMap)
{
	if (number < 2)
		return 1;
	auto it = memoMap.find(number);
	if (it != memoMap.end())
	{
		
		return memoMap[number];
	}
	long long int value = fibRecurMemo(number - 1, memoMap) + fibRecurMemo(number - 2, memoMap);
	memoMap[number] = value;
	return value;
}

void RecursionAndMemo::displayfibRecur(long long number)
{
	std::unordered_map<long long, long long> tempMap;
	long long result=fibRecurMemo(number, tempMap);
	std::cout << result << std::endl;
}

int RecursionAndMemo::LongestSubSeq(const std::string &first, const std::string &second, int indexA, int indexB)
{
	if (indexA == 0 || indexB == 0)
		return 0;
	if (first[indexA-1] == second[indexB-1])
	{
		return 1 + LongestSubSeq(first, second,indexA-1,indexB-1);
	}
	return std::max(LongestSubSeq(first, second, indexA-1, indexB), LongestSubSeq(first, second, indexA, indexB-1));
}

int RecursionAndMemo::LongestSubStr(const std::string& first, const std::string& second, int indexA, int indexB, int count)
{
	if (indexA == 0 || indexB == 0)
		return count;
	if (first[indexA-1] == second[indexB-1])
	{
		count =  LongestSubStr(first, second, indexA-1, indexB-1,count+1);
	}
	return std::max(count,std::max(LongestSubStr(first, second, indexA-1, indexB,0), LongestSubStr(first, second, indexA, indexB-1,0)));
}


void RecursionAndMemo::displayLongestSubSeq()
{
	std::string first = "AGGTAB";
	std::string second = "GXTXAYB";
	int answer=LongestSubSeq(first, second, first.size(), second.size());
	std::cout<<"The final answer is " << answer << std::endl;
}

void RecursionAndMemo::displayLongestSubStr()
{
	//Input : X = “abcdxyz”, y = “xyzabcd” 
	std::string first = "zxabcdezy";
	std::string second = "yzabcdezx";
	int answer = LongestSubStr(first, second, first.size(), second.size(),0);
	std::cout << "The final answer is substr " << answer << std::endl;
}
void RecursionAndMemo::displayLongestSubSeqDynamic()
{
	//Input : X = “abcdxyz”, y = “xyzabcd” 
	std::string first = "AGGTAB";
	std::string second = "GXTXAYB";
	int answer = LongestSubSeqDynamic(first, second);
	std::cout << "The final answer is subseq dynamic " << answer << std::endl;
}

int RecursionAndMemo::LongestSubSeqDynamic(const std::string& first, const std::string& second)
{
	if (first.size() == 0 || second.size() == 0)
	{
		return 0;
	}
	std::vector<std::vector<int>> table(first.size() + 1, std::vector<int>(second.size() + 1));
	for (int i = 0; i < table.size(); i++)
	{

		for (int j = 0; j < table.at(0).size(); j++)
		{
			if (i == 0 || j == 0)
			{
				table.at(i).at(j) = 0;
			}
			else if (first.at(i - 1) == second.at(j - 1))
			{
				table.at(i).at(j) = 1 + table.at(i - 1).at(j - 1);
			}
			else
			{
				table.at(i).at(j) = std::max(table.at(i-1).at(j), table.at(i ).at(j-1));
			}

		}
	}

		return table.at(first.size()).at(second.size());
}

bool RecursionAndMemo::checkCommonSubstring(const std::string& first, const std::string& second)
{
	const int max_size = 26;
	std::vector<bool> statusTable(max_size);
	for (int i = 0; i < first.size(); i++)
	{
		statusTable.at(first.at(i) - 'a') = true;
	}
	for (int i = 0; i < second.size(); i++)
	{
		if (statusTable.at(second.at(i) - 'a'))
			return true;
	}
	return false;
}
