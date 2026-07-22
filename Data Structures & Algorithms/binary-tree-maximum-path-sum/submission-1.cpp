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
int fin = INT_MIN;
    int maxPathSum(TreeNode* root){
        int t = maxPath(root);

        return fin;
    }
    int maxPath(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right){
            fin = max(fin, root->val);
            return root->val;
        }

        int one = !root->left ? 1e7*(-1) : maxPath(root->left);
        int two = !root->right ? 1e7*(-1) : maxPath(root->right);
        int curr = root->val;

        fin = max({fin, one, two, curr, one+curr, two+curr, one+two+curr});
        // cout<<"Node "<<curr<<", l and r are "<<one<<" and "<<two<<endl;
        // cout<<"fin is "<<fin<<endl<<endl;
        return max({one+curr, two+curr, curr});
    }
};
