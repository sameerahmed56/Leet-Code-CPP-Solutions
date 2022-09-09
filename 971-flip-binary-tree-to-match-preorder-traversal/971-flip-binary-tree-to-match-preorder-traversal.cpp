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
    vector<int> flips;
    bool traverse(TreeNode* root, vector<int>& voyage, int &pos) {
      if (root == nullptr) return true;
      if (root->val != voyage[pos++]) return false;
      auto l = root->left, r = root->right;
      if (l != nullptr && l->val != voyage[pos]) {
        flips.push_back(root->val);
        swap(l, r);
      }
      return traverse(l, voyage, pos) && traverse(r, voyage, pos);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage, int pos = 0) {
      return traverse(root, voyage, pos) ? flips : vector<int>() = { -1 };
    }
};