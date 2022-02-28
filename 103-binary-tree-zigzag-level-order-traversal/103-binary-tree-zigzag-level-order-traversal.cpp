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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool startRight = true;
        if(root==nullptr)
            return ans;
        deque<TreeNode*> q;
        q.push_front(root);
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i = 0; i<n; i++){
                TreeNode* curr = startRight ? q.front() : q.back();
                startRight ? q.pop_front() : q.pop_back();
                temp.push_back(curr->val);
                if(startRight){
                    if(curr -> left != nullptr){
                        startRight ? q.push_back(curr->left) : q.push_front(curr->left);
                    }
                    if(curr -> right != nullptr){
                        startRight ? q.push_back(curr->right) : q.push_front(curr->right);
                    }
                }
                else{
                    if(curr -> right != nullptr){
                        startRight ? q.push_back(curr->right) : q.push_front(curr->right);
                    }
                    if(curr -> left != nullptr){
                        startRight ? q.push_back(curr->left) : q.push_front(curr->left);
                    }
                }
            }
            ans.push_back(temp);
            startRight = !startRight;
        }
        return ans;
    }
};