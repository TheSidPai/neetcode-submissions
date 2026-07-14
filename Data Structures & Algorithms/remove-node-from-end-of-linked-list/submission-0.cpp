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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* res = head;
        ListNode* prev;
        for(int i = 0; i < n; i++) curr = curr->next;
        while(curr){
            curr = curr->next;
            prev=  res;
            res = res->next;
        }
        if(res == head) return head->next;
        prev->next = res->next;
        return head;
    }
};
