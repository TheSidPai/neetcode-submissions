/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(map.count(node)) return map[node];
        Node* temp = new Node(node->val);
        map[node] = temp;

        for(auto a: node->neighbors){
            temp->neighbors.push_back(cloneGraph(a));
        }

        return temp;
    }
};
