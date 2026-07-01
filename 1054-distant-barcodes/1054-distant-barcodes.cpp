class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> st;
        unordered_map<int,int> mp;
        for(int i=0;i<barcodes.size();i++)mp[barcodes[i]]++;
        for(auto it:mp){
            st.push({it.second,it.first});
        }

        vector<int> ans;
        while(st.size()>1){
            auto first=st.top();
            st.pop();
            auto second=st.top();
            st.pop();

            ans.push_back(first.second);
            if(first.first!=1)st.push({first.first-1,first.second});
            ans.push_back(second.second);
            if(second.first!=1)st.push({second.first-1,second.second});
        }

        while(!st.empty()){
            auto element=st.top();
            st.pop();
            ans.push_back(element.second);
            if(element.first!=1)st.push({element.first-1,element.second});
        }
        return ans;
    }
};