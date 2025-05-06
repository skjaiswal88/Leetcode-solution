class Solution {
public:
    void fun(int n,vector<string> &v,int i,string f){
        if(i==n){
            v.push_back(f);
            return;
        }

        if (f.empty()) {
    fun(n, v, i + 1, f + '0');
    fun(n, v, i + 1, f + '1');
}
else if (f.back() == '1') {
    fun(n, v, i + 1, f + '0');
    fun(n, v, i + 1, f + '1');
}
else {
    fun(n, v, i + 1, f + '1');
}

    }

    vector<string> validStrings(int n) {

        vector<string> v;
        string f;
        fun(n,v,0,f);
        return v;
        
    }
};