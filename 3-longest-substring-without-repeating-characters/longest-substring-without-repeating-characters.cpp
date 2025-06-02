class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int an=0;
        int l=0;

        for(int r=0;r<n;r++){
            char c=s[r];

            if(mp.find(c)!=mp.end() && mp[c]>=l){
                l=mp[c]+1;
            }
            mp[c]=r;
            an=max(an,r-l+1);
        }

        return an;
    }
};