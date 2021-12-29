#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

class Monster
{
public:
	int range=0;
	float power=0;
public:
;
	Monster() {};
	~Monster() {};
};
	

template<typename T>
class AdQueue
{
private:
	vector<Monster> monsterArray;
public:
	void maxQueue(const std::vector<T> &data)
	{
		std::priority_queue<int> maxQueue;
		for (int i = 0; i < data.size(); i++)
		{
			maxQueue.push(data.at(i));
		}
		while (!maxQueue.empty())
		{
			std::cout << maxQueue.top() << std::endl;
			maxQueue.pop();
		}
		cout << "=======================" << endl;
	}
	void MinQueue(const std::vector<T> &data)
	{

		std::priority_queue<int,vector<T>,greater<T>> maxQueue;
		for (int i = 0; i < data.size(); i++)
		{
			maxQueue.push(data.at(i));
		}
		while (!maxQueue.empty())
		{
			std::cout << maxQueue.top() << std::endl;
			maxQueue.pop();
		}
		cout << "=======================" << endl;
	}
	void custom()
	{
	
		int maxMonster = 5;
		vector<int> ranges = { 11,22,2,3,4 };
		vector<float> powers = { 11.22,22.11,112.22,3,4 };
		for (int i = 0; i < maxMonster; i++)
		{
			
			Monster monster;
			monster.power = powers.at(i);
			monster.range = ranges.at(i);
			
			monsterArray.push_back(monster);
			
		}
	}
	
	void customSolution()
	{
		
		custom();
		auto comparer = [](const Monster& a, const Monster& b) {
			return a.power < b.power;
		};
		std::priority_queue < Monster, vector<Monster>, decltype(comparer)> monsterQueue(comparer);
		for (auto monster : monsterArray)
		{
			monsterQueue.push(monster);
		}
		while (!monsterQueue.empty())
		{
			Monster _monster = monsterQueue.top();
			cout << _monster.power << endl;
			monsterQueue.pop();
		}
	}

};

