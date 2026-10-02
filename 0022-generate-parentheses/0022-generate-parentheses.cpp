class Solution {
public:
    vector<string> ans;

    void helper(int open,int close,int n,string s){
        if(open==close && close==n){
            ans.push_back(s);
            return;
        }

        if(open<close)return;
        if(open<n)helper(open+1,close,n,s+"(");
        if(close<open)helper(open,close+1,n,s+")");
        return;
    }

    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return ans;
    }
};