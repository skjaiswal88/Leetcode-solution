class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;
        stack<int> s;
        int n=nums.size();

        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }

            if(s.empty()){v.push_back(-1);}
            else{v.push_back(s.top());}

            s.push(nums[i%n]);
        }

        reverse(v.begin(),v.end());

        vector<int> an(v.begin(),v.begin()+n);
        
        return an;
    }
};