#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        set<int> times;
        for(int i=0;i<s1.size();i++)times.insert(s1[i][0]);
        for(int i=0;i<s2.size();i++)times.insert(s2[i][0]);

        vector<vector<int>> ans;
        for(auto itr:times){
            vector<int> temp;
            vector<int> lb1;
            vector<int> lb2;
            temp.push_back(itr);
            vector<int> target={itr,0};
            auto it=lower_bound(s1.begin(),s1.end(),target);
            if(it!=s1.end()){
                lb1=*it;
            }
            else lb1=target;

            it=lower_bound(s2.begin(),s2.end(),target);
            if(it!=s2.end()){
                lb2=*it;
            }
            else lb2=target;
            temp.push_back(lb1[1]+lb2[1]);
            ans.push_back(temp);
        }
        return ans;
    }
};