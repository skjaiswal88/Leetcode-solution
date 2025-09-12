class Solution {
public:
    bool doesAliceWin(string s) {
        auto isVowel = [](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        
        int countV = 0;
        for (char c : s) {
            if (isVowel(c)) countV++;
        }
        
        return countV > 0; 
    }
};
