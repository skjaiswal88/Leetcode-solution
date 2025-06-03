class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0; int r=0; int d=0;

        int a=0,b=0,c=0;

        while(l<n && r<n){
            if(s[r]=='a') a++;
            else if(s[r]=='b') b++;
            else{ c++; }

            while(a>0 && b>0 && c>0 ) {
                d=d+(n-r);

                if(s[l]=='a') a--;
                else if(s[l]=='b') b--;
                else{ c--; }
                l++;
            }
            r++;

        }
        return d;
    }
};