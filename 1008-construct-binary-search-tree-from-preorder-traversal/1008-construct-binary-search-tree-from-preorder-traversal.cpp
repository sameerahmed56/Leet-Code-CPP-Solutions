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
    TreeNode* constructBST(vector<int>& preorder,int &index, int key, int min, int max, int n) {
        if(index >= n) return NULL;
        TreeNode* root = NULL;
        if(key > min && key < max){
            cout << "inside ";
            root = new TreeNode(key);
            index = index + 1;
            
            if(index < n){
                root -> left = constructBST(preorder,index,preorder[index],min,key,n);
            }
            if(index < n){
                root -> right = constructBST(preorder,index,preorder[index],key,max,n);
            }
        }
        return root;
    }    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return constructBST(preorder,index, preorder[index], INT_MIN, INT_MAX, preorder.size());
    }
};