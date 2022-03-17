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
    void getVerticalOrder(TreeNode* root, map<int,vector<pair<int,int>>> &mp, int hd,int lvl){
        if(root==nullptr)return;
        mp[hd].push_back({lvl,root->val});
        getVerticalOrder(root->left,mp,hd-1, lvl+1);
        getVerticalOrder(root->right,mp,hd+1, lvl+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> ans;
        getVerticalOrder(root,mp,0,0);
        for(auto it:mp){
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for(auto i:it.second)tmp.push_back(i.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};