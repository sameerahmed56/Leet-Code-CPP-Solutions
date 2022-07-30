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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            bool isEven = (level % 2 == 0);
            int prev =  isEven ? INT_MIN : INT_MAX;
            for(int i=0; i<n; i++){
                TreeNode* x =  q.front();
                q.pop();
                if(isEven && (prev >= x->val || x->val%2 == 0)){
                    return false;
                }
                else if(!isEven && (prev <= x->val || x->val%2 != 0)){
                    return false;
                }
                prev = x->val;
                if(x->left != NULL)
                    q.push(x->left);
                if(x->right != NULL)
                    q.push(x->right);
            }
            level++;
        }
        return true;
    }
};