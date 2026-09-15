class Solution {
public:

    int n;

    bool isPalind(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(string& s,int k,int i,int j,vector<vector<int>>& dp){
        if(i>=n || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        if(isPalind(s,i,j)){
            int take=1+helper(s,k,j+1,j+k,dp);
            int skip=helper(s,k,i,j+1,dp);
            int slide=helper(s,k,i+1,j+1,dp);

            return dp[i][j]=max({take,skip,slide});
        }

        int skip=helper(s,k,i,j+1,dp);
        int slide=helper(s,k,i+1,j+1,dp);

        return dp[i][j]=max(skip,slide);
    }

    int maxPalindromes(string s, int k) {
        n=s.length();
        if(k==1)return n;

        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return helper(s,k,0,k-1,dp);
    }
};