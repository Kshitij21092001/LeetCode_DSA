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

    //inorder should be sorted, there are 2 cases where either swapping nodes may be adjacent or not
    //root and prev will manage the traversal and comparison
    //first will store the first number misplaces
    //if second occurance is not adjacent, then 'last' variable will capture it
    //else middle will store the next value after first to swap
    TreeNode* first=NULL;
    TreeNode* last=NULL;
    TreeNode* middle=NULL;
    TreeNode* prev=NULL;

    void inorder(TreeNode* root){
        if(root==NULL)return;

        inorder(root->left);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
        return;
    }

    void recoverTree(TreeNode* root) {
        first=last=middle=prev=NULL;
        inorder(root);

        if(first&&last)swap(first->val,last->val);
        else if(first&&middle)swap(first->val,middle->val);
        return;
    }
};