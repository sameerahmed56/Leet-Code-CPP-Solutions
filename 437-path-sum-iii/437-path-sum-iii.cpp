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
    void solve(TreeNode* root, int target, unordered_map<long long, long long> mp, int &ans){
        if(!root) return;
        if(root->val == target) ans++;
        if(mp.count(target-root->val)){
            ans = ans + mp[target-root->val];
        }
        unordered_map<long long, long long> temp;
        for(auto it: mp){
            temp[it.first+root->val] = it.second;
        }
        temp[root->val]++;
        solve(root->left,target, temp, ans);
        solve(root->right,target, temp, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> mp;
        int ans = 0;
        solve(root,targetSum, mp, ans);
        return ans;
    }
};