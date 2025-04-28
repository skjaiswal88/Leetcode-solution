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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the starting point of the result linked list
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;

        // Loop until both l1 and l2 are fully traversed, and there is no carry left
        while ((l1 != NULL || l2 != NULL) || carry) {
            int sum = 0;

            // Add the value from l1 if l1 is not null
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add the value from l2 if l2 is not null
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add the carry from the previous operation
            sum += carry;

            // Update the carry for the next iteration
            carry = sum / 10;

            // Create a new node with the digit of the current sum
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        // Return the next node of the dummy node, which is the actual head of the result list
        return dummy->next;
    }
};
