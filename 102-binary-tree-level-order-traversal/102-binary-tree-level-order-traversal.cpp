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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> qu;
        if(root==NULL)
            return ans;
        qu.push(root);
        qu.push(NULL);
        vector<int> temp;
        while(!qu.empty()){
            TreeNode* front =  qu.front();
            qu.pop();
            if(front != NULL){
                temp.push_back(front->val);
                if(front->left != NULL)
                    qu.push(front->left);
                if(front->right != NULL)
                    qu.push(front->right);
            }
            else if(!qu.empty()){
                ans.push_back(temp);
                temp.clear();
                qu.push(NULL);
            }
        }
        if(temp.size()>0)
            ans.push_back(temp);
        return ans;
    }
};