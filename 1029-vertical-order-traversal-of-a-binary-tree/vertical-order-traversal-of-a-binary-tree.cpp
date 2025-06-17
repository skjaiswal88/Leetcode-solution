/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Node{
    public:
    TreeNode* a;
    int x;
    int y;

    Node(TreeNode* q, int w, int e){
        this->a=q;
        this->x=w;
        this->y=e;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(root==nullptr) return v;
        queue<Node*> q;

        map<int,map<int,multiset<int>>> mp;

        Node* r=new Node(root,0,0);
        int s=1;
        q.push(r);

        while(!q.empty()){

            while(s){
                Node* temp=q.front();
                q.pop();

                if(temp->a->left!=nullptr) {
                    Node* e= new Node(temp->a->left,temp->x-1,temp->y+1);
                    q.push(e);
                }

                if(temp->a->right!=nullptr) {
                    Node* e= new Node(temp->a->right,temp->x+1,temp->y+1);
                    q.push(e);
                }

                mp[temp->x][temp->y].insert(temp->a->val);

                s--;
            }
            s=q.size();
        }

        for(auto it:mp){
            vector<int> t;
            for(auto i:it.second){
                for(auto j: i.second){
                    t.push_back(j);
                }

            }
            v.push_back(t);
        }

        return v;
    }
};


























