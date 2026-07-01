class Solution {
public:

    int n;
    bool check(vector<vector<int>>& safeDist,int sf){
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(n,0));
        q.push({0,0});
        visited[0][0]=1;

        if(safeDist[0][0]<sf)return false;
        int dRow[]={1,0,-1,0};
        int dCol[]={0,1,0,-1};
        while(!q.empty()){
            auto element=q.front();
            q.pop();
            if(element.first==n-1 && element.second==n-1)return true;

            for(int i=0;i<4;i++){
                int new_i=element.first+dRow[i];
                int new_j=element.second+dCol[i];

                if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && visited[new_i][new_j]==0){
                    if(safeDist[new_i][new_j]<sf)continue;
                    q.push({new_i,new_j});
                    visited[new_i][new_j]=1;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> safeDist(n,vector<int> (n,-1));
        vector<vector<int>> visited(n,vector<int> (n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }

        int dRow[]={1,0,-1,0};
        int dCol[]={0,1,0,-1};
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr_i=q.front().first;
                int curr_j=q.front().second;
                q.pop();
                safeDist[curr_i][curr_j]=level;

                for(int i=0;i<4;i++){
                    int new_i=curr_i+dRow[i];
                    int new_j=curr_j+dCol[i];

                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && visited[new_i][new_j]==0){
                        q.push({new_i,new_j});
                        visited[new_i][new_j]=1;
                    }
                }
            }
            level++;
        }

        int left=0;
        int right=400;
        int ans=0;

        while(left<=right){
            int mid_sf=left+(right-left)/2;

            if(check(safeDist,mid_sf)){
                ans=mid_sf;
                left=mid_sf+1;
            }
            else{
                right=mid_sf-1;
            }
        }
        return ans;
    }
};