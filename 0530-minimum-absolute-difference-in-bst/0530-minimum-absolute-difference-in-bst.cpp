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

    void helper(vector<int>& v, TreeNode* root){
        if(root==NULL)return;

        v.push_back(root->val);
        helper(v,root->left);
        helper(v,root->right);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        helper(v,root);
        int minDiff=INT_MAX;
        sort(v.begin(),v.end());

        for(int i=0;i<v.size()-1;i++){
            minDiff=min(minDiff,v[i+1]-v[i]);
        }
        return minDiff;
    }
};