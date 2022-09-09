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
    vector<int> ans;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> np = {-1};
        int i = 0;
        return solve(root,voyage,i) ? ans : np;
    }
    bool solve(TreeNode* root, vector<int>& voyage, int& i) {
        if(!root ) return true;
        if(i >= voyage.size() || voyage[i] != root->val) return false;
        i++;
        bool left = solve(root->left, voyage, i);
        if(!left){
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            ans.push_back(root->val);
            left = solve(root->left, voyage, i);
        }
        bool right = solve(root->right, voyage, i);
        return left && right;
    }
};