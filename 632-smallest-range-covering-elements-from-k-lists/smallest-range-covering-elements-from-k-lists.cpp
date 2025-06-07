class node{
    public:
    int data;
    int i;
    int j;

    node(int a, int b, int c){
        this->data=a;
        this->i=b;
        this->j=c;
    }
};

class compare{
    public:
    bool operator() (node* a, node* b){
        return a->data > b->data;
    }
};



class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> v;
        priority_queue<node* , vector<node*> , compare> pq;
        int a=nums[0][0]; int b=nums[nums.size()-1][0];

        for(int i=0;i<nums.size();i++){
            node* temp=new node(nums[i][0],i,0);
            pq.push(temp);
            a=min(a,nums[i][0]);
            b=max(b,nums[i][0]);
        }
        int r=b-a;
        int c=a;
        int d=b;

        while(pq.size()>0){
            node* temp=pq.top();

            pq.pop();
            if((temp->j) +1 >= nums[temp->i].size()) break;
            else{
                node* tem=new node(nums[temp->i][(temp->j)+1],temp->i,(temp->j)+1);
                pq.push(tem);

                d=max(d,nums[temp->i][(temp->j)+1]);
                c=pq.top()->data;

                if(r>d-c){
                    a=c; b=d; r=b-a;
                }
                
            }
        }

        v.push_back(a);
        v.push_back(b);

        return v;
    }
};