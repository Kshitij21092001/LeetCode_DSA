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

    int helper(TreeNode* root,int& ans){
        if(root==NULL)return INT_MIN;

        int left=max(helper(root->left,ans),root->val);
        int right=max(helper(root->right,ans),root->val);
        int currMax=max(root->val,max(left,right));
        if(currMax==root->val)ans++;
        return currMax;
    }

    int countDominantNodes(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};