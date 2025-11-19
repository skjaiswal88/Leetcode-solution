/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* fun(ListNode* head){
        ListNode* prev=nullptr;
        

        while(head){
            ListNode* ne=head->next;
            head->next=prev;
            prev=head;
            head=ne;

        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=fun(slow);
        ListNode* f=head;

        while(temp){
            if(f->val!=temp->val){
                return false;
            }
            f=f->next;
            temp=temp->next;
        }

        return true;

    }
};