#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = sortDigits(n);
        for (int i = 0; i < 31; ++i) { 
            if (target == sortDigits(1 << i)) return true;
        }
        return false;
    }

private:
    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};
