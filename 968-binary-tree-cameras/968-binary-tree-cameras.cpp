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
    int cameraCover(TreeNode* root, int &count) {
        if(root == NULL) return 2;
        if(root->left == NULL && root->right == NULL) return 0;
        
        int left = cameraCover(root->left, count);
        int right = cameraCover(root->right, count);
        
        if(left == 0 || right == 0){
            count++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
    int minCameraCover(TreeNode* root) {
        int count = 0;
        int covered = cameraCover(root, count);
        
        return (covered == 0 ? 1 : 0) + count;
    }
};