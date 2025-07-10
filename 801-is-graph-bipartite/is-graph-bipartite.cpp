class Solution {
public:

    bool fun(vector<vector<int>>& graph,vector<int> &v,int i,int c){
        if(v[i]==-1) {
            v[i]=c;

            for(auto e:graph[i]){
                if( !fun(graph,v,e,1-c) ){
                    return false;
                }
                
            }
            return true;
        }
        else if(v[i]==c){
            return true;
        }
            return false;
        
    } 

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> st(n,-1);
        bool an=false;

        for(int i=0;i<n;i++){
            if(st[i]==-1){
                an = fun(graph,st,i,0);
                if(!an) break;
            }
        }
        if(an) return true;
        else return false;


    }
};