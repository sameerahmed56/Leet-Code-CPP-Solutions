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
    int maxValue = 0;
    vector<int> ans;
    void traverse(TreeNode* root){
        if(root==nullptr) return;
        int count = 0; 
        countMode(root,root->val,count);
        if(count > maxValue){
            maxValue = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(count == maxValue){
            ans.push_back(root->val);
        }
        traverse(root->left);
        traverse(root->right);
    }
    void countMode(TreeNode* root,int key, int &currCount){
        if(root == NULL ){
            return;
        }
        if(root->val == key) currCount++;
        countMode(root->left, key,currCount);
        countMode(root->right, key,currCount);
    } 
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return ans;
    }
};