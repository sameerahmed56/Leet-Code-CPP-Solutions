/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans =  new TreeNode();
    void traverse(TreeNode* root, TreeNode* target){
        if(root ==nullptr) return;
        if(root->val == target->val){
            ans = root;
            return;
        }
        traverse(root->left, target);
        traverse(root->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(cloned,target);
        return ans;
    }
};