class LFUCache {
public:

class listNode{
public:
    int key;
    int val;
    int c;
    listNode* prev;
    listNode* next;

    listNode(int x,int y): key(x), val(y),  c(1), prev(nullptr), next(nullptr) {}

};

    listNode* head;
    listNode* tail;
    unordered_map<int,listNode*> mp;
    int capacity;



    LFUCache(int capacity) : capacity(capacity) {
        head= new listNode(0,0);
        tail= new listNode(0,0);
        head->next=tail;
        tail->prev=head;
        
    }

    void insert(listNode* temp){
        temp->next=head->next;
        temp->prev=head;
        temp->next->prev=temp;
        head->next=temp;
    }

    void remove(listNode* temp){
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }

    listNode* fun(){
    int minFreq = INT_MAX;
        listNode* result = nullptr;

        for (listNode* node = tail->prev; node != head; node = node->prev) {
            if (node->c < minFreq) {
                minFreq = node->c;
                result = node;
            }
        }
        return result;
    }

    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            (mp[key]->c)++;
            remove(mp[key]);
            insert(mp[key]);
            return (mp[key])->val;
        }
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){
            (mp[key]->c)++;
            (mp[key])->val=value;
            remove(mp[key]);
            insert(mp[key]);
        }
        else{
            listNode* temp= new listNode(key,value);
            if(mp.size()==capacity){
                listNode* del=fun();
                mp.erase(del->key);
                remove(del);
                delete del;
                insert(temp);
                mp[key]=temp;
            }
            else{
                insert(temp);
                mp[key]=temp;
            }
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */