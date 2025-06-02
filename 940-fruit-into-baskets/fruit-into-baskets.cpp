class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int n=fruits.size();
        unordered_map<int,int> mp;
        int an=0;
        int a=fruits[0];
        int b;
        int x;

        for(int r=0;r<n;r++){
            if(mp.size()<2 || mp.find(fruits[r])!=mp.end() ){
                if(fruits[r]!=a) b=fruits[r];
                mp[fruits[r]]=r;
                an=max(an,r-l+1);
            }
            else{
                if(mp[a]<mp[b]){
                    l=mp[a]+1;
                    mp.erase(a);
                    a=fruits[r];
                }
                else{
                    l=mp[b]+1;
                    mp.erase(b);
                    b=fruits[r];
                }

                mp[fruits[r]]=r;
                an=max(an,r-l+1);
            }
        }
        return an;
    }
};