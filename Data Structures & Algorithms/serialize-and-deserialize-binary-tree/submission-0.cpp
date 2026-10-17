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

class Codec {

private:
    void dfsconvert(TreeNode* root, string& s){
        if(!root){
            s += "null,";
            return ;
        }
        s += to_string(root->val) + ',';
        dfsconvert(root->left, s);
        dfsconvert(root->right,s);
    }

    TreeNode* dfsdecode(stringstream& s){
        string val;
        getline(s,val, ',');
        if(val == "null"){return nullptr;}
        TreeNode* node = new TreeNode(stoi(val));
        node->left = dfsdecode(s);
        node->right = dfsdecode(s);
        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfsconvert(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return dfsdecode(s);
    }
};
