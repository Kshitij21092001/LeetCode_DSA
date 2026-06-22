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

    vector<int> helper(TreeNode* root,int distance,int& count){
        if(root==NULL)return{};
        if(root->left==NULL && root->right==NULL)return {1};

        vector<int> leftNodes=helper(root->left,distance,count);
        vector<int> rightNodes=helper(root->right,distance,count);

        for(int i=0;i<leftNodes.size();i++){
            for(int j=0;j<rightNodes.size();j++){
                if(leftNodes[i]+rightNodes[j]<=distance)count++;
            }
        }

        vector<int> curr;

        for(int i=0;i<leftNodes.size();i++){
            if(leftNodes[i]+1<distance)curr.push_back(leftNodes[i]+1);
        }

        for(int i=0;i<rightNodes.size();i++){
            if(rightNodes[i]+1<distance)curr.push_back(rightNodes[i]+1);
        }
        return curr;
    }

    int countPairs(TreeNode* root, int distance) {
        int count=0;
        helper(root,distance,count);
        return count;
    }
};