/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* element=q.front();
            q.pop();

            if(element==NULL)ans+="#,";
            else{
                ans+=to_string(element->val)+',';
                q.push(element->left);
                q.push(element->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)return NULL;
        stringstream newStream(data);
        string temp;
        getline(newStream,temp,',');
        TreeNode* root=new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* element=q.front();
            q.pop();

            getline(newStream,temp,',');

            if(temp=="#")element->left=NULL;
            else{
                TreeNode* newNode=new TreeNode(stoi(temp));
                element->left=newNode;
                q.push(newNode);
            }

            getline(newStream,temp,',');

            if(temp=="#")element->right=NULL;
            else{
                TreeNode* newNode=new TreeNode(stoi(temp));
                element->right=newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));