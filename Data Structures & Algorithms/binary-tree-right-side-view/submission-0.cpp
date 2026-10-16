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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* n;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz ; i++){
                n = q.front();
                q.pop();
                if(n->left){q.push(n->left);}
                if(n->right){q.push(n->right);}
            }
            result.push_back(n->val);
        }
        return result;
    }
};
