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
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && slow){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;

            if(slow == fast && slow != nullptr) return true;
        }

        return false;
    } 
};
