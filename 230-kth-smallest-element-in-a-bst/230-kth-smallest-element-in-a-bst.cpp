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
    int ans = 0;
    void traverse(TreeNode* root, int& index){
        if(!root) return;
        traverse(root->left,index);
        if(index==1){
            ans=root->val;
            index--;
            return;
        }
        index--;
        traverse(root->right,index);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return ans;
    }
};