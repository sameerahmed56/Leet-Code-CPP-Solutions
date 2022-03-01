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
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* mid = NULL;
    TreeNode* prev = NULL;
    void correctBST(TreeNode* root){   
        if(root==NULL) return;
        correctBST(root->left);
        if(prev && root->val < prev->val){
            if(!first){
                first = prev;
                mid = root;;
            }
            else{
                last = root;
            }
        }
        prev = root;
        correctBST(root->right);
    }
    void recoverTree(TreeNode* root) {
        correctBST(root);
        if(last == NULL){
            swap(first->val, mid->val);
        }
        else{
            swap(first->val, last->val);
        }
    }
};