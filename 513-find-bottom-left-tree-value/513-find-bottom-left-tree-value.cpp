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
    void dfs(TreeNode* root, int level, int& maxLevel, int& ans){
        if(root == NULL) return;
        if(level>maxLevel){
            maxLevel = level;
            ans = root->val;
        }
        dfs(root->left,level+1,maxLevel,ans);
        dfs(root->right,level+1,maxLevel,ans);

    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, maxLevel = -1;
        dfs(root,0,maxLevel,ans);
        return ans;
    }
};