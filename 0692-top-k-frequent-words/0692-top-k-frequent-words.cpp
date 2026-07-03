class Solution {
public:

    static bool comp(const pair<int,string>& val1,const pair<int,string>& val2){
        if(val1.first==val2.first)return val1.second<val2.second;
        return val1.first>val2.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(&comp)> heap(&comp);
        unordered_map<string,int> mp;

        for(int i=0;i<words.size();i++)mp[words[i]]++;
        for(auto i:mp){
            heap.push({i.second,i.first});
            if(heap.size()>k)heap.pop();
        }
        vector<string> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};