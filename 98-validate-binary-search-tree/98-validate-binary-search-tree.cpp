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
    bool validateBST(TreeNode* root, TreeNode* minAllowed, TreeNode* maxAllowed){
        if(root == NULL) return true;
        if(minAllowed && root->val <= minAllowed->val) return false;
        if(maxAllowed && root->val >= maxAllowed->val) return false;
        bool leftValid = validateBST(root->left,minAllowed,root);
        bool rightValid = validateBST(root->right,root,maxAllowed);
        
        return  leftValid and rightValid;
    }
    bool isValidBST(TreeNode* root) {
        return validateBST(root,NULL, NULL);
    }
};