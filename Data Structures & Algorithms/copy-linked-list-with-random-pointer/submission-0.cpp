/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        Node* prev = nullptr;

        while(curr){
            Node* node = new Node(curr->val);
            mp[curr] = node;
            if(prev) mp[prev]->next = mp[curr];

            prev = curr;
            curr = curr->next;
        }

        Node* newHead = mp[head];
        curr = head;

        while(curr){
            Node* copy = mp[curr];
            copy->random = mp[curr->random];

            curr = curr->next;
        }

        return newHead;
    }
};
