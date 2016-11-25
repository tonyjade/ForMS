// Source : https://leetcode.com/problems/two-sum/
// Author : Jaden
// Data   : 2016-11-25 

/**********************************************************************************************************************
 * 1. Two Sum
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * The return format had been changed to zero-based indices.
 *
 **********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>  
#include <algorithm>      // sort(begin, end) 

using namespace std;

// The wrong implement of twoSum():
// 1) Sort the array. 
// 2) Set two indices: i and j. i goes through the array from left to right, versus j from right to left.
// 
// ErrorOutput: the i and j are not the initial i and j anymore. 
//
vector<int> twoSumError(vector<int> nums, int target)
{
    vector<int> ret;
    if (nums.size() <= 1)
    {
        ret.push_back(-1);
	ret.push_back(-1);
        return ret;
    }
    sort(begin(nums), end(nums));
    for (int i = 0, j = nums.size() -1; i != j; )
    {
        int two_sum = nums[i] + nums[j]; 
        if (two_sum == target)
        {
            ret.push_back(i);
            ret.push_back(j);
            return ret;
        }
        if (two_sum > target)
            --j;
        else
            ++i;
    }
    ret.push_back(-1);
    ret.push_back(-1);
    return ret;
}

// The implementation: 
// 1) Use unordered_map<key, value> construct a hash map <value, index>.
// 2) Traverse the array and pick up the responding value that matches the target.
//    A bit tricky is here, if we find the index, we should first check whether the 2 indices are the same index.
// 
vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> ret;
    unordered_map<int, int> map;
    if (nums.size() <= 1)
    {
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
    for (int i = 0; i < nums.size(); ++i)
        map[nums[i]] = i;   // ERROR: map.insert(nums[i], i) is wrong.
    for (int i = 0; i < nums.size(); ++i)
    {
        int r_value = target - nums[i];
        if (map.find(r_value) != end(map) && map[r_value] != i)     
        {
            if (i < map[r_value])
            {
                ret.push_back(i);
                ret.push_back(map[r_value]);  // ERROR: ret.push_back(nums[r_value]);
            } 
            else
            {    
                ret.push_back(map[r_value]); // ERROR: ret.push_back(nums[r_value]);
                ret.push_back(i); 
            }
            return ret;	
	}     
    }
    ret.push_back(-1);
    ret.push_back(-1);
    return ret;
}

// 
//
//
vector<int> twoSumBest(vector<int> nums, int target)
{
    vector<int> ret(2, -1);
    unordered_map<int, int> map;
    if (nums.size() <= 1)
        return ret;
    for (int i = 0; i < nums.size(); ++i)
    {
        int r_value = target - nums[i];
        if (map.find(r_value) == end(map))    
            map[nums[i]] = i;
        else
        {
            ret[0] = map[r_value];
            ret[1] = i;
            return ret;
        }	
    }
    return ret;
}

int main()
{
    return 1;
}


