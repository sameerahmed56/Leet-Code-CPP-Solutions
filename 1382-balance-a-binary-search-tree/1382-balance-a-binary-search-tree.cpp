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
    TreeNode* createTree(vector<int> arr, int l, int r){
        if(l>r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = createTree(arr,l,mid-1);
        root->right = createTree(arr,mid+1,r);
        return root;
    }
    void traverse(TreeNode* root,vector<int> &arr){
        if(root==NULL) return;
        arr.push_back(root->val);
        traverse(root->left,arr);
        traverse(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        traverse(root,arr);
        sort(arr.begin(),arr.end());
        int l = 0, r = arr.size()-1, mid = l + (r - l) / 2;
        TreeNode* ans = new TreeNode(arr[mid]);
        ans->left = createTree(arr,l,mid-1);
        ans->right = createTree(arr,mid+1,r);
        return ans;
    }
};