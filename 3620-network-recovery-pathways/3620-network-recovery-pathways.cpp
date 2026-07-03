class Solution {
public:
    int n;
    bool dijikstra(long long& minWeight,vector<vector<pair<int,int>>>& adj, long long k){
        vector<long long> distance(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        distance[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto element=pq.top();
            pq.pop();

            if(element.first>distance[element.second])continue;
            if(element.second==n-1)return true;

            for(auto ngbr:adj[element.second]){
                if(ngbr.second<minWeight)continue;
                if(ngbr.second+element.first>k)continue;
                if(ngbr.second+element.first<distance[ngbr.first]){
                    distance[ngbr.first]=ngbr.second+element.first;
                    pq.push({ngbr.second+element.first,ngbr.first});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        int maxWeight=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            if(online[u]&&online[v]){
                adj[u].push_back({v,weight});
                maxWeight=max(maxWeight,weight);
            }
        }

        long long left=0;
        long long right=maxWeight;
        long long ans=-1;

        while(left<=right){
            long long mid=left+(right-left)/2;
            if(dijikstra(mid,adj,k)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};