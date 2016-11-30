// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Jaden
// Data   : 2016-11-27 

/***********************************************************************************************************************
 * 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Expample:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a 
 * subsequence and not a substring.
 *
 **********************************************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Refers to HaoChen's github, I still don't understand the implementation yet.
// Just recite the programme. 
// 
// Solution:
// 1) Set two integers: max_len to record the max length of substring, repeat_pos to the closest repeated character
//    that stored in the map.
// 2) Iterate through the array, update repeat_pos and max_len. 
//    If we found the repeated, check its index value, and update repeat_pos if possible.
//    If (i - repeat_pos) greater than max_len, update max_len. 
int lengthOfLongestSubstring(string s)
{
    if (s.length() <= 1)  return s.length();
    unordered_map<char, int> map;
    int max_len = 0;
    int repeat_pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (map.find(s[i]) != map.end() && repeat_pos < map[s[i]]) {
            repeat_pos = map[s[i]];	
        }
        if (max_len < i - repeat_pos) {
            max_len = i - repeat_pos;
        }
        map[s[i]] = i;
    }
    return max_len;
}


int main()
{
    string s = "dsvasdfdsfsdfvvfddbdgbg";
    int len = lengthOfLongestSubstring(s);
    cout << "Length of the string is: " << len << endl;
    return 0;
}
