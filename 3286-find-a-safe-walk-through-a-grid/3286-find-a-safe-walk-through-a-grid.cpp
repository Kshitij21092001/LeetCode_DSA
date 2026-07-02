class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<tuple<int,int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> bestHealth(m,vector<int>(n,-1));
        int startHealth=health-grid[0][0];
        bestHealth[0][0]=startHealth;
        q.push({0,0,startHealth});

        while(!q.empty()){
            auto [row,col,currHealth]=q.front();
            q.pop();

            if(row==m-1 && col==n-1 && currHealth>0)return true;

            int dRow[]={1,0,-1,0};
            int dCol[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newRow=row+dRow[i];
                int newCol=col+dCol[i];

                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n){
                    int newHealth=currHealth-grid[newRow][newCol];
                    if(newHealth<=0)continue;
                    if(newHealth<=bestHealth[newRow][newCol])continue;
                    bestHealth[newRow][newCol]=newHealth;
                    q.push({newRow,newCol,newHealth});
                }
            }
        }
        return false;
    }
};