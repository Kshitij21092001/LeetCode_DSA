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

    int count=0;

    pair<int,int> helper(TreeNode* node){
        if(node==NULL)return {0,0};

        pair<int,int> left=helper(node->left);
        pair<int,int> right=helper(node->right);

        if((node->val+left.first+right.first)/(1+left.second+right.second)==node->val)count++;

        return {left.first+right.first+node->val,1+left.second+right.second};
    }

    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};