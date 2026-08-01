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
    int maxDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL)return depth;

        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty()){
            auto element=q.front();
            q.pop();

            depth=max(depth,element.second);
            if(element.first->left!=NULL)q.push({element.first->left,element.second+1});
            if(element.first->right!=NULL)q.push({element.first->right,element.second+1});
        }
        return depth;
    }
};