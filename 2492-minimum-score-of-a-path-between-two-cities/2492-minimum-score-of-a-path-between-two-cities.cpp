class Solution {
public:

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int dist=roads[i][2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        int minScore=INT_MAX;
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(1);
        visited[1]=1;

        while(!q.empty()){
            int element=q.front();
            q.pop();

            for(auto ngbr:adj[element]){
                minScore=min(minScore,ngbr.second);
                if(visited[ngbr.first]!=1){
                    visited[ngbr.first]=1;
                    q.push(ngbr.first);
                }
            }
        }
        return minScore;
    }
};