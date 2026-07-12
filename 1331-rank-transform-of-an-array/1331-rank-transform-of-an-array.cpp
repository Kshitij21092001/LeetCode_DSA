class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return arr;

        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        int n=arr.size();
        vector<int> rank(n,0);
        rank[0]=1;
        for(int i=1;i<n;i++){
            if(temp[i]==temp[i-1])rank[i]=rank[i-1];
            else rank[i]=1+rank[i-1];
        }

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[temp[i]]=rank[i];
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};