class LRUCache {
public:
    
    class ListNode {
    public:
    int key;
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int y,int x) : key(y), val(x), next(nullptr), prev{nullptr} {}
};
    unordered_map<int,ListNode*> mp;
    int capacity;
    ListNode* head;
    ListNode* tail;


    LRUCache(int capacity): capacity(capacity) {
        head= new ListNode(0,0);
        tail= new ListNode(0,0);
        head->next=tail;
        tail->prev=head;
        
    }

    void insert(ListNode* temp){
        temp->next=head->next;
        temp->prev=head->next->prev;
        temp->next->prev=temp;
        head->next=temp;
    }

    void remove(ListNode* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

    }

        void put(int key, int value) {
        if(get(key)!=-1){
            mp[key]->val=value;
        }
        else{
            ListNode* temp= new ListNode(key,value);

            if(mp.size()==capacity){
                int p=(tail->prev)->key;
                remove(tail->prev);
                insert(temp);
                mp.erase(p);
            }
            else{
                insert(temp);
            }
            mp[key]=temp;
        }
    }
    

    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else {
            
            ListNode* temp=mp[key];
            remove(temp);
            insert(temp);

            return (mp[key])->val;}
    }
    

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */