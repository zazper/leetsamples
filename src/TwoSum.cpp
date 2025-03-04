// myLeetCode.cpp : Defines the entry point for the application.
//

#include "myLeetCode.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <initializer_list>


// https://leetcode.com/problems/two-sum/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


template<class T>
class myVector : public std::vector<T> {

public:
	myVector<T>() : std::vector<T>()
	{
		std::cout << "vector ctor" << std::endl;
	};

	//myVector<T>(std::initializer_list<T> init, const Allocator& alloc = Allocator()) : std::vector<T>(init, alloc)
	myVector<T>(std::initializer_list<T> init) : std::vector<T>(init)
	{
		std::cout << "initialized vector ctor" << std::endl;
	};

	template <typename InputIterator>
	myVector<T>(InputIterator first, InputIterator last) : std::vector<T>(first, last) {
		std::cout << "iterator vector ctor" << std::endl;
	};
		
	//constexpr myVector<T>(std::from_range, R&& rg, const Allocator& alloc = Allocator()) : std::vector<T>(rg, alloc) {

	virtual ~myVector<T>()
	{
		std::cout << "vector dtor" << std::endl;
	};
};


class MyTwoSum {
public:
	myVector<int> myTwoSum(myVector<int>& nums, int target) {
		// first we lookup if goal - value is in hashmap. If so, we are done as we iterate of nums, 
		// iterate over vector, save position of vector as a hashmap index = lookup[value]
		std::unordered_map<int, int> twoHash;

		int index = 1;
		for (int num : nums) {
			twoHash[num] = index;
			int key = target - num;
			auto solution = twoHash.find(key);
			//std::cout << "key:" << key << " num:" << num << " index:" << index << std::endl;
			if (solution != twoHash.end()) {
				return myVector<int>{ twoHash[key], index };
			}
			index++;
		}
		myVector<int> v;
		v.push_back(0);
		v.push_back(0);
		return v;

		//return myVector<int>{ 0, 0 };
	}
};

std::ostream& operator<<(std::ostream& os, const myVector<int>& input)
{
	for (auto const& i : input) {
		os << i << " ";
	}
	return os;
}

class TwoSum {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
		// first we lookup if goal - value is in hashmap. If so, we are done as we iterate of nums, 
		// iterate over vector, save position of vector as a hashmap index = lookup[value]
		std::unordered_map<int, int> twoHash;

		int index = 1;
		for (int num : nums) {
			twoHash[num] = index;
			int key = target - num;
			auto solution = twoHash.find(key);
			//std::cout << "key:" << key << " num:" << num << " index:" << index << std::endl;
			if (solution != twoHash.end()) {
				return std::vector<int>{ twoHash[key], index };
			}
			index++;
		}
		return std::vector<int>{ 0, 0 };
    }
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& input)
{
	for (auto const& i : input) {
		os << i << " ";
	}
	return os;
}

int main()
{
	int input1[] { 1, 2, 3, 4 };
	int target1{ 5 };
	int input2[] { 4,3,2,1};
	int target2{ 5 };
	int input3[]{ 1, -2, 3, 4, 9, 22 };
	int target3{ 20 };
	
	TwoSum ts;

	std::vector<int> vec(std::begin(input1), std::end(input1));
	std::vector<int>& result = ts.twoSum(vec, target1);
	std::cout << "two sum: " << result << std::endl;

	std::vector<int> vec2(std::begin(input2), std::end(input2));
	result = ts.twoSum(vec2, target2);
	std::cout << "two sum: " << result << std::endl;

	std::vector<int> vec3(std::begin(input3), std::end(input3));
	result = ts.twoSum(vec3, target3);
	std::cout << "two sum: " << result << std::endl;

	MyTwoSum mts;

	myVector<int> myvec3(std::begin(input3), std::end(input3));
	result = mts.myTwoSum(myvec3, target3);
	std::cout << "two sum: " << result << std::endl;

	return 0;
}