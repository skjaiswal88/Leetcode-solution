class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r;
        int an=0;
        vector<int> v(26,0);
        int m=0;

        for(int r=0;r<s.size();r++){
            v[s[r]-'A']++;
            m=max(m,v[s[r]-'A']);

            if(r-l+1-m>k){
                v[s[l]-'A']--;
                l++;
            }

            an=max(an,r-l+1);

        }

        return an;

    }
};