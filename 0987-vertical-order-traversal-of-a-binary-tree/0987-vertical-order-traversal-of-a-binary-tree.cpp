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

    void helper(TreeNode* root, map<int,vector<pair<int,int>>>& mp,int row,int col){
        if(root==NULL)return;
        mp[col].push_back({row,root->val});
        helper(root->left,mp,row+1,col-1);
        helper(root->right,mp,row+1,col+1);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;

        helper(root,mp,0,0);
        vector<vector<int>> ans;

        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            vector<int> temp;

            for(auto element:it.second){
                temp.push_back(element.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};