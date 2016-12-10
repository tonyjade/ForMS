// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Jaden
// Data   : 2016-12-10

/***********************************************************************************************************************
 * 5. Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 *
 * Example:
 * Input: "cbbd"    Output: "bb"
 * Input: "babad"   Output: "bab" (Note: "aba" is also a valid answer)
 *
 **********************************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

// Refers to HaoChen's github, just recite it. 
// There're many solutions, I'll list all of them belows.


/** Solution 1: common solution.                                                 */
/* ----------------------------------------------------------------------------- */

// Jaden: this utility function may be useful in other senario. 
string findPalindrome(string s, int left, int right) {
    if (s.size() <= 1)  return s;
    while (left > -1 && right < s.size() && s[left] == s[right]) {
        --left; 
        ++right;
    }
    return s.substr(left+1, right-left-1); // NOTE: substr(pos, len)
}

// Common solution: a for loop.  
string findLongestPalindrome1(string s) {
    string longest; // ERROR: string longest = nullptr; causing core dump. 
    if (s.size() <= 1)
        return s;
    for (int i = 0; i < s.size(); ++i) {
        string sub_str; 
        sub_str = findPalindrome(s, i, i);    // Jaden: for the odd number of elements.
        if (sub_str.size() > longest.size())
            longest = sub_str;
        sub_str = findPalindrome(s, i, i+1);  // Jaden: Key point, for the even number of elements. 
        if (sub_str.size() > longest.size())
            longest = sub_str;
    }
    return longest;
}









int main()
{
    string s = "1234543311";
    string longest = findLongestPalindrome1(s);
    cout << longest << endl;
}

