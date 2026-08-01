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

    void helper(TreeNode* root, string curr,vector<string>& ans){
        if(root->left==NULL && root->right==NULL){
            curr+=to_string(root->val);
            ans.push_back(curr);
            return;
        }
        curr+=to_string(root->val);
        curr+="->";
        if(root->left!=NULL){
            helper(root->left,curr,ans);
        }
        if(root->right!=NULL){
            helper(root->right,curr,ans);
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string curr="";
        vector<string> ans;
        helper(root,curr,ans);
        return ans;
    }
};