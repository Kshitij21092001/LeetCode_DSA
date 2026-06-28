class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size();
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> v;
        
        int start=occupiedIntervals[0][0];
        int end=occupiedIntervals[0][1];

        for(int i=1;i<n;i++){
            if(end+1>=occupiedIntervals[i][0]){
                end=max(end,occupiedIntervals[i][1]);
            }
            else{
                v.push_back({start,end});
                start=occupiedIntervals[i][0];
                end=occupiedIntervals[i][1];
            }
        }
        v.push_back({start,end});

        vector<vector<int>> ans;

        for(auto& interval:v){
            int left=interval[0];
            int right=interval[1];

            if(right<freeStart || left>freeEnd){
                ans.push_back({left,right});
            }
            else if(left<freeStart && right>freeEnd){
                ans.push_back({left,freeStart-1});
                ans.push_back({freeEnd+1,right});
            }
            else if(left<freeStart){
                ans.push_back({left,freeStart-1});
            }
            else if(right>freeEnd){
                ans.push_back({freeEnd+1,right});
            }
        }
        return ans;
    }
};