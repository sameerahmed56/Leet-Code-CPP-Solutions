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
    vector<int> arr;
    TreeNode* createTree(int l, int r){
        if(l>r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = createTree(l,mid-1);
        root->right = createTree(mid+1,r);
        return root;
    }
    void traverse(TreeNode* root){
        if(root==NULL) return;
        traverse(root->left);
        arr.push_back(root->val);
        traverse(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        int l = 0, r = arr.size()-1;
        root = createTree(l,r);
        return root;
    }
};