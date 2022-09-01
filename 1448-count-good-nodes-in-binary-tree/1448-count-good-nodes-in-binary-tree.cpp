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
    int countNodes(TreeNode* root, int large){
        if(root == NULL) return 0;
        int toAdd = root->val >= large ? 1 : 0;
        large = max(large,root->val);
        return countNodes(root->left,large) + countNodes(root->right,large) + toAdd;
    }
    int goodNodes(TreeNode* root) {  
        if(root == NULL) return 0;
        return countNodes(root, root->val);
    }
};