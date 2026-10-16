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
    vector<int> result;
    void dfs(TreeNode* root, vector<int>& result){
        TreeNode* curr = root;
        if(!root){return;}
        dfs(root->left, result);
        result.push_back(root->val);
        dfs(root->right, result);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        result = {};
        dfs(root, result);
        return result[k-1];
    }
};
