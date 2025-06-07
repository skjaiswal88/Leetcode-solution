class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Add the first node of each list (if not null)
        for (auto list : lists) {
            if (list != nullptr)
                pq.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != nullptr)
                pq.push(curr->next);
        }

        return dummy.next;
    }
};
