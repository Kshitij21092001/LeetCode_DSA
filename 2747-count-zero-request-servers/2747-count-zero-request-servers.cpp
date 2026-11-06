class Solution {
public:

    static bool comp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();

        sort(logs.begin(),logs.end(),comp);
        
        vector<pair<int,int>> timeIndex;
        for(int i=0;i<queries.size();i++){
            timeIndex.push_back({queries[i],i});
        }
        sort(timeIndex.begin(),timeIndex.end());

        unordered_map<int,int> mp;
        vector<int> ans(queries.size());

        int i=0;
        int j=0;
        for(int k=0;k<timeIndex.size();k++){
            int start=timeIndex[k].first-x;
            int end=timeIndex[k].first;

            while(j<m && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0)mp.erase(logs[i][0]);
                i++;
            }

            ans[timeIndex[k].second]=n-mp.size();
        }
        return ans;
    }
};