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


/** Solution 2: DP solution.                                                     */
/* ----------------------------------------------------------------------------- */

// Note: 
// * A method to construct a two-dimensional matrix using vector.
// * For example: create an 3*4 matrix[3][4] of type int. 
// 
// vector<vector<int>> matrix(3);            <---- define a matrix with 3 members
// for (int i = 0; i < matrix.size(); ++i)
//     matrix[i].resize(4);                  <---- each member is resized to 4 elements
// OR:
// vector<vector<int>> matrix(3, vector<int>(4));  
// 

// DP analysis:
// Define a matrix of type bool, set matrix[i][j] true or false  
// considering s[i] -> s[j] is palindrome or not.
// For example, s = "abbc". matrix[i][j] means whether s[i] == s[j].
// matrix = { 1, 0, 0, 0,      
//            0, 1, 1, 0,    
//            0, 0, 1, 0,   
//            0, 0, 0, 1 };  
// 
// DP solution would be postponed to when I learn DP. 
// http://fisherlei.blogspot.com/2012/12/leetcode-longest-palindromic-substring.html
// http://bangbingsyb.blogspot.com/2014/11/leetcode-longest-palindromic-substring.html
// 














int main()
{
    string s = "1234543311";
    string longest = findLongestPalindrome1(s);
    cout << longest << endl;
}

