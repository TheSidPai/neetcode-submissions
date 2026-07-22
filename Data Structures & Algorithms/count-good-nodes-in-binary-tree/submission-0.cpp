/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int count = 0;
    int goodNodes(TreeNode* root) {
        traverse(root, -101);

        return count;
    }
    void traverse(TreeNode* root, int curr){
        if(!root) return;
        if(root->val >= curr){
            count++;
            curr = root->val;
        }

        traverse(root->left, curr);
        traverse(root->right, curr);
    }
};
