class Solution {
public:
    string reverseWords(string s) {
        int left=0; int right=s.size()-1;

        while(left<right && s[left]==' '){left++;}
        while(left<right && s[right]==' '){right--;}

        reverse(s.begin()+left,s.begin()+right+1);

        int f=left; int l=left;
        while(l<=right){
            if(s[l]==' '){
                reverse(s.begin()+f,s.begin()+l);
                f=l+1;
            }
            l++;
        }

        reverse(s.begin()+f,s.begin()+l);

        string an;
        bool d=false;
        for(int i=left;i<=right;i++){
            if(s[i]!=' '){an=an+s[i]; d=false;}
            else{
                if(d==false){an=an+' '; d=true;}
            }
        }

        return an;
        
    }
};