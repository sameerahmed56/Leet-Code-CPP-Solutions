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
    pair<int,int> average(TreeNode* root, int &ans){
        if(!root) return {0,0};
        pair<int, int> left = average(root->left,ans);
        pair<int, int> right = average(root->right,ans);
        int count = left.second + right.second + 1;
        if((left.first + right.first + root->val)/count == root->val){
            ans++;
        }
        return {left.first + right.first + root->val, left.second + right.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pair<int,int> sum = average(root,ans);
        return ans;
    }
};