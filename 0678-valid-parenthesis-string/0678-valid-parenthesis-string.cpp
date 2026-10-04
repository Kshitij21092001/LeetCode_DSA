class Solution {
public:

    bool helper(string& s,int ind,int count, vector<vector<int>>& dp){
        if(ind==s.length()){
            if(count==0)return true;
            return false;
        }
        if(count<0)return false;
        if(dp[ind][count]!=-1)return dp[ind][count];

        if(s[ind]=='(')return dp[ind][count]=helper(s,ind+1,count+1,dp);
        if(s[ind]==')')return dp[ind][count]=helper(s,ind+1,count-1,dp);
        if(s[ind]=='*'){
            bool opt1=helper(s,ind+1,count+1,dp);
            bool opt2=helper(s,ind+1,count-1,dp);
            bool opt3=helper(s,ind+1,count,dp);
            return dp[ind][count]=opt1 || opt2 || opt3;
        }
        return false;
    }

    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(s,0,0,dp);
    }
};