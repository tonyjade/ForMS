#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* Solution: my version. */
int longestSubString(string s) {
    if (s.size() <= 1) {
        return s.size();
    }
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (maxLen >= s.size() - i) {
            break;
        }
        unordered_map<char, int> m;
        m[s[i]] = i;
        int curLen = 1;
        for (int j = i+1; j < s.size(); ++j) {
            if (m.find(s[j]) == m.end()) {
                m[s[j]] = j;
                ++curLen;
            }
            else {
                break;
            }
        }
        if (curLen >= maxLen) {
            maxLen = curLen;
        }
    }
    return maxLen;
}

/* Solution2: HaoChen */
int longestSubString2(string s) {
    if (s.size() <= 1) {
        return s.size();
    }
    unordered_map<char, int> map;
    int max_len = 0;
    int repeated_pos = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (map.find(s[i]) != map.end() && repeated_pos < map[s[i]]) { // s[repeated_pos] == s[i]
            repeated_pos = map[s[i]];
        }
        if (max_len < i - repeated_pos) {
            max_len = i - repeated_pos;
        }
        map[s[i]] = i;
    }
    return max_len;
}

int main() {
    string s = "asdfgvccxxsgb";
    cout << longestSubString(s) << endl;
    cout << longestSubString2(s) << endl;
    return 0;
}




