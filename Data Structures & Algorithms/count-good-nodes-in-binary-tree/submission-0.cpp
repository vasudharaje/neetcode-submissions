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
    int count;
    int dfs(TreeNode* root, int maxsofar){
        if(!root){return 0;}
        int count=0;
        if(root->val >= maxsofar){
            maxsofar = root->val;
            count++;
        }
        return count+ dfs(root->left,maxsofar) + dfs(root->right, maxsofar);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        return dfs(root, root->val);
    }
};
