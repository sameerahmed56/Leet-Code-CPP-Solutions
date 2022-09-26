
class Solution {
public:
    int longestUnivaluePath(TreeNode* root ) {
        if(!root) return 0;
        int path = solve(root->left,root->val, 0) + solve(root->right,root->val, 0);
        return max({path,longestUnivaluePath(root->left),longestUnivaluePath(root->right)});
    }
private:
    int solve(TreeNode* root, int prev, int count){
        if(!root || root->val != prev) return count;
        // cout << root->val;
        int left = solve(root->left,prev, count+1);
        int right = solve(root->right,prev, count+1);        
        return max(left,right);
    }
};