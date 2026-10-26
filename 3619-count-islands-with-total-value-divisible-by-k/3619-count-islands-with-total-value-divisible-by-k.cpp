class Solution {
public:

    int ans=0;
    int m,n;

    long long helper(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j){
        if(i>=m || j>=n || i<0 || j<0 || visited[i][j]==1 || grid[i][j]==0)return 0LL;

        visited[i][j]=1;

        return (long long)(grid[i][j]+helper(grid,visited,i+1,j)+helper(grid,visited,i-1,j)+helper(grid,visited,i,j+1)+helper(grid,visited,i,j-1));
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && visited[i][j]==0){
                    long long total=helper(grid,visited,i,j);
                    if(total%k==0)ans++;
                }
            }
        }
        return ans;
    }
};