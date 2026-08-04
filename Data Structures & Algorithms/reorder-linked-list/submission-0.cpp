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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;

        while(fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        prev->next = NULL;
        
        // cout<<head->val<<" "<<slow->val<<endl;
        ListNode* last = NULL;
        ListNode* curr = slow;

        while(curr){
            ListNode* after = curr->next;
            curr->next = last;
            last = curr;
            curr = after;
        }

        ListNode* half = last;
        ListNode* first = head;

        while(half){
            ListNode* temp = first->next;
            ListNode* temp2 = half->next;

            first->next = half;
            half->next = temp;

            first = temp;
            half = temp2;

        }
        
    }
};
