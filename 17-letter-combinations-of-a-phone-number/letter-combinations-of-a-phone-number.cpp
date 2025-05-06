class Solution {
public:

    void fun(string d,unordered_map<char, string> mp,vector<string> &v,string s,int an){
        if(s.size()==d.size()){
            v.push_back(s);
            return;
        }

        for(char f: mp[d[an]]){
            s.push_back(f);
            fun(d,mp,v,s,an+1);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}   };

     vector<string> v;

    if(digits.empty()) {return v;}


   
    string s;

    fun(digits,mp,v,s,0);

    return v;
        
    }
};