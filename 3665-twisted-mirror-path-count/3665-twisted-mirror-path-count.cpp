class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m,{0,0}));
        for(int i = n-1;i >= 0;i--){
            dp[i][m-1] = {1,0};
            if(grid[i][m-1]) break;
        }
        for(int i = m-1;i >= 0;i--){
            dp[n-1][i] = {0,1};
            if(grid[n-1][i]) break;
        }
        for(int i = n-2;i >= 0;i--){
            for(int j = m-2;j >= 0;j--){
                if(grid[i][j]){
                    dp[i][j] = {dp[i+1][j].second,dp[i][j+1].first};
                }
                else {
                    int total = (dp[i+1][j].second + dp[i][j+1].first)%mod;
                    dp[i][j] = {total,total};
                }
            }
        }
        return dp[0][0].first;
    }
};