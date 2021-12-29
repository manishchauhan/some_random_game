#pragma once
#include<iostream>
#include<vector>
#include <utility>
#include<algorithm>
using namespace std;
template<typename T>
class BinarySearchSoution
{
public:
	BinarySearchSoution() {};
	~BinarySearchSoution() {
		std::cout << "all finish" << std::endl;
	};
	// Add a simple search

	pair<bool,int>  Search(const std::vector<T> &data,T value) {
		int start = 0;
		int end = data.size() - 1;
		while (start<=end)
		{
			int mid = (start + end) / 2;
			if (data[mid] == value)
			{
			
				return std::make_pair(true, mid);;
			}
			else if (data[mid] > value)
			{
				end = mid - 1;
			}
			else if (data[mid] < value)
			{
				start = mid + 1;
			}
		}
		return make_pair(false, -1);
	}
	//	Search first item
	pair<bool, int>  SearchFirst(const std::vector<T>& data, T value) {
		int start = 0;
		int end = data.size() - 1;
		pair<bool, int> result = std::make_pair(false, -1);
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (data[mid] == value)
			{
				result.first = true;
				result.second = mid;
				end = mid - 1;
				
			}
			else if (data[mid] > value)
			{
				end = mid - 1;
			}
			else if (data[mid] < value)
			{
				start = mid + 1;
			}
		}
		return result;
	}
	//	Search last item
	pair<bool, int>  SearchLast(const std::vector<T>& data, T value) {
		int start = 0;
		int end = data.size() - 1;
		pair<bool, int> result = std::make_pair(false, -1);
		
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (data[mid] == value)
			{
				result.first = true;
				result.second = mid;
				start = mid + 1;

			}
			else if (data[mid] > value)
			{
				end = mid - 1;
			}
			else if (data[mid] < value)
			{
				start = mid + 1;
			}
		}
		return result;
	}
	//	get ceil value 
	pair<bool, int>  Ceil(const std::vector<T>& data, T value) {
		pair<bool, int> result = std::make_pair(false, -1);
		int start = 0;
		int end = data.size() - 1;
		int index = -1;
		if (value > data[data.size() - 1])
		{
			return result;
		}
		
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (data[mid] == value || value < data.at(0))
			{
				return std::make_pair(true, data.at(mid));

			}
			else if (data[mid] > value)
			{
				index = mid;
				end = mid - 1;
			}
			else if (data[mid] < value)
			{
				start = mid + 1;
			}
		}
		result.first = false;
		result.second = data.at(index);

		return result;
	}

	//	get floor value 
	pair<bool, int>  floor(const std::vector<T>& data, T value) {
		pair<bool, int> result = std::make_pair(false, -1);
		int start = 0;
		int end = data.size() - 1;
		int index = -1;
		if (value > data[data.size() - 1] || value<data.at(0))
		{
			return result;
		}

		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (data[mid] == value)
			{
				return std::make_pair(true, data.at(mid));

			}
			else if (data[mid] > value)
			{
			
				end = mid - 1;
			}
			else if (data[mid] < value)
			{
				index = mid;
				start = mid + 1;

			}
		}
		result.first = false;
		result.second = data.at(index);

		return result;
	}
	//How many times is a sorted array rotated? url-https://www.youtube.com/watch?v=4qjprDkJrjY
	int howManyTimes(const std::vector<T> &input)
	{
		//check if array is already sorted
		if (is_sorted(input.begin(), input.end()))
		{
			std::cout<<"Array is already sorted"<<std::endl;
			return -1;
		}
		int size = input.size()-1;
		int start=0;
		int end=input.size()-1;
		while (start <= end)
		{
			int mid = (start +end) / 2;
			if (input[start] <= input[end])
			{
				return start;
			}

			// check before and after mid index, if it's true, mid is min index
			if (input[mid] <= input[mid - 1] && input[mid] <= input[mid + 1])
			{
				return mid;
			}
			else if (input[mid] <= input[end])
			{
				end = mid - 1;
			}
			else if (input[mid] >= input[start])
			{
				start = mid + 1;
			}
		}
		return -1;
	}
	//Search element in a circular sorted array very very important
	int Search_in_rotatedArray(const vector<int> &data,int value)
	{
		if (data.size() < 1)
		{
			return -1;
		}
		int low = 0;
		int high = data.size() - 1;
		while (low<=high)
		{
			int mid = (low + high) / 2;
			//base case
			if (data.at(mid) == value)
			{
				return mid;
			}
			//condition  11,12,13,14,15,1,2,3,4,5 
			else if (data.at(mid) <data.at(high))
			{
				if (value >= data.at(mid) && value <=data.at(high))
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			else
			{

				if (value >= data.at(low) && value <= data.at(mid))
				{
				
					
					
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
		}
		return -1;
	}
};

