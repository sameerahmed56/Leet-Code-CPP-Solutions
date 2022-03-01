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
    #define minimum -40000
    int ans = minimum;
    struct Info {
        int currSum;
        int min;
        int max;
        bool isBST;
    };
    Info largestBSTinBT(TreeNode* root){
        if(root == NULL)
            return {0,INT_MAX,INT_MIN,true};
        if(root->left == NULL && root->right == NULL){
            ans = max(ans,root->val);
            return {root->val,root->val,root->val,true};
        }
        Info leftInfo = largestBSTinBT(root->left);
        Info rightInfo = largestBSTinBT(root->right);
        Info curr;
        curr.currSum = root->val + leftInfo.currSum + rightInfo.currSum;
        curr.min = min({leftInfo.min,rightInfo.min,root->val});
        curr.max = max({leftInfo.max,rightInfo.max,root->val});
        if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->val && rightInfo.min> root->val){
            curr.isBST = true;
            ans = max(ans,curr.currSum);
            return curr;
        }
        curr.isBST = false;
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        Info i = largestBSTinBT(root);
        return max(ans,0);
    }
};