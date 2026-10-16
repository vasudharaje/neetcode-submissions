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

private:
    bool dfs(TreeNode* root, TreeNode* minnode, TreeNode* maxnode){
        if(!root) return true;
        if(minnode && root->val <= minnode->val) return false;
        if(maxnode && root->val >= maxnode->val) return false;
        return dfs(root->left, minnode, root) && dfs(root->right, root, maxnode);
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};
