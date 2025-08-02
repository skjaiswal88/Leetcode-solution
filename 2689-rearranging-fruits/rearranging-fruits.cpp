class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long l=basket1.size();
        long long mini=*min_element(basket1.begin(),basket1.end());
        long long mini1=*min_element(basket2.begin(),basket2.end());
        long long fmini=min(mini,mini1);
        map<long long,long long>mpp;
         map<long long,long long>mpp1;
          map<long long,long long>mpp2;
        for(long long i=0;i<l;i++){
            mpp[basket1[i]]++;
            mpp[basket2[i]]++;
            mpp1[basket1[i]]++;
            mpp2[basket2[i]]++;
        }
        for(auto it:mpp){
            if(it.second%2==1){
                return -1;
            }
        }
        for(auto &it:mpp){
            it.second=it.second/2;
        }
        vector<long long>extra;
        vector<long long>need;

         
        for(auto it:mpp){
            
            if(mpp1.find(it.first)==mpp1.end()){
                while(it.second--){
                    need.push_back(it.first);
                }
            }
            else if(mpp1.find(it.first)!=mpp1.end()){
                if(mpp1[it.first]==it.second){
                    continue;
                }
                long long diff=mpp1[it.first]-it.second;
                if(diff<0){
                    long long dif=abs(diff);
                    while(dif--){
                        need.push_back(it.first);
                    }
                }
                else{
                    while(diff--){
                        extra.push_back(it.first);
                    }
                }
            }
        }
        sort(need.begin(),need.end());
        sort(extra.begin(),extra.end());
        long long ans=0;
        for(long long i=0;i<need.size();i++){
            ans+=min(min(need[i],extra[need.size()-i-1]),2*fmini);
        }
       
       return ans;


    }
};