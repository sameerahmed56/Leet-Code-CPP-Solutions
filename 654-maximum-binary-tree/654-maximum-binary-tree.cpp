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
    int findMax(vector<int>&nums, int l , int r){
        int maxIndex = -1, maxElem = -1;
        while(l <= r){
            if(maxElem < nums[l]){
                maxElem = nums[l];
                maxIndex = l;
            }
            l++;
        }
        return maxIndex;
        
    }
    TreeNode* constructBinaryTree(vector<int>& nums, int l, int r){
        if(l>r) return NULL;
        int maxIndex = findMax(nums,l,r);
        TreeNode* curr = new TreeNode(nums[maxIndex]);
        curr->left = constructBinaryTree(nums, l, maxIndex-1);
        curr->right = constructBinaryTree(nums, maxIndex+1, r);
        return curr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        return constructBinaryTree(nums, 0, nums.size()-1);;
    }
};