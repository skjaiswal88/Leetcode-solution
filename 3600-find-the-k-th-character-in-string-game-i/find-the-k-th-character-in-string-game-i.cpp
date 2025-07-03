class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            string next_part = "";
            for (char ch : word) {
                if (ch == 'z') {
                    next_part += 'a';
                } else {
                    next_part += ch + 1;
                }
            }
            word += next_part;
        }
        return word[k - 1];
    }
};
