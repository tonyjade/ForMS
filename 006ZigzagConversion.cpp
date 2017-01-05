// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Jaden
// Data   : 2017-1-5

/***********************************************************************************************************************
 *
 * 6. ZigZag Conversion
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 **********************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Solution:                                                                */
/* Just find the law, and the operation could be down repeatedly.           */
/* The key point should be nRows*2 -2, we just modulo it.                   */
/* Two conditions be concerned :                                            */
/* 1) Less than (nRows-1);   2) More than (nRows-1);                        */
vector<string> convert(string s, int nRows) {
    vector<string> v(nRows);
    if (s.size() <= 1) {
        return v;
    }
    for (int i = 0; i < s.size(); ++i) {
        int pos = i % (nRows*2 -2); 
        if (pos < nRows)  // 0 ~ (nRows-1) 
            v[pos].push_back(s[i]);
        else              // The index should be {(nRows-1)-[pos-(nRows-1)]}. 
            v[2*(nRows-1)-pos].push_back(s[i]);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
    cout << endl;
    return v;
}


int main() {
    string s = "PAYPALISHIRING";
    vector<string> v = convert(s, 3);
    return 0;
}



