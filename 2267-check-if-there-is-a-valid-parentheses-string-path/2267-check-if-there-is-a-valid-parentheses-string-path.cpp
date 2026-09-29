class Solution {
public:

    int m;
    int n;

    bool helper(int i,int j,int balance,vector<vector<char>>& grid,vector<vector<vector<int>>>& dp){
        if(i==m-1 && j==n-1){
            if(grid[i][j]=='(')balance++;
            else balance--;
            if(balance==0)return true;
            return false;
        }
        if(grid[i][j]=='(')balance++;
        else balance--;

        if(balance<0)return false;
        
        if(dp[i][j][balance]!=-1)return dp[i][j][balance];


        bool right=false;
        if(j+1<n)right=helper(i,j+1,balance,grid,dp);
        bool down=false;
        if(i+1<m)down=helper(i+1,j,balance,grid,dp);

        return dp[i][j][balance]=right||down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        if((m+n-1)%2==1)return false;

        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(201,-1)));

        return helper(0,0,0,grid,dp);
    }
};