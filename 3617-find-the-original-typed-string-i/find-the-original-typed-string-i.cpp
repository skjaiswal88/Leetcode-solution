#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int c = 0;

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                c++;
            }
        }
        
        return c+1;
    }
};
