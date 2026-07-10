class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<int> pos(n);
        for(int i=0;i<n;i++)pos[arr[i].second]=i;

        int log=1;
        while((1<<log)<n)log++;

        vector<vector<int>> up(n,vector<int> (log));
        int right=0;
        for(int left=0;left<n;left++){
            if(right<left)right=left;
            while((right+1<n)&& arr[right+1].first-arr[left].first<=maxDiff)right++;
            up[left][0]=right;
        }

        for(int j=1;j<log;j++){
            for(int i=0;i<n;i++){
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }

        vector<int> ans;
        for(auto it:queries){
            int src=pos[it[0]];
            int dst=pos[it[1]];

            if(src>dst)swap(src,dst);
            if(src==dst){
                ans.push_back(0);
                continue;
            }

            int curr=src;
            int hops=0;
            for(int j=log-1;j>=0;j--){
                if(up[curr][j]<dst){
                    curr=up[curr][j];
                    hops+=(1<<j);
                }
            }
            if(up[curr][0]>=dst)ans.push_back(hops+1);
            else ans.push_back(-1);
        }
        return ans;
    }
};