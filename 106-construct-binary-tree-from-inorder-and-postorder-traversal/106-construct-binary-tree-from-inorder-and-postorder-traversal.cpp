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
    TreeNode* constructTree(vector<int>& postorder, int left, int right, int &ind, unordered_map<int,int>& mp){
        if(left>right || ind < 0) return nullptr;
        int rootValue = postorder[ind--];
        TreeNode* root = new TreeNode(rootValue);
        root->right = constructTree(postorder,mp[rootValue]+1,right,ind,mp);
        root->left = constructTree(postorder,left,mp[rootValue]-1,ind,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), ind = n-1;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }        
        return constructTree(postorder,0,n-1,ind,mp);
    }
};