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
    pair<int,int> getMaxValue(TreeNode* root){
        if(root == NULL) return {0,0};
        pair<int,int> left = getMaxValue(root->left);
        pair<int,int> right = getMaxValue(root->right);
        pair<int,int> curr;
        curr.first = left.second + right.second + root->val;
        curr.second = max(left.first, left.second) + max(right.first, right.second);
        return curr;
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = getMaxValue(root);
        return max(ans.first,ans.second);
    }
};