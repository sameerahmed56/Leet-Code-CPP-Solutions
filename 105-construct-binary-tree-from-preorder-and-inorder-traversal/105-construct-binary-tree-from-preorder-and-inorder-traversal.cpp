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
    TreeNode* constructTree(vector<int>& preorder, int left, int right, int &ind, unordered_map<int,int>& mp){
        if(left>right) return nullptr;
        int rootValue = preorder[ind++];
        TreeNode* root = new TreeNode(rootValue);
        
        root->left = constructTree(preorder,left,mp[rootValue]-1,ind,mp);
        root->right = constructTree(preorder,mp[rootValue]+1,right,ind,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), ind = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        
        return constructTree(preorder,0,n-1,ind,mp);
    }
};