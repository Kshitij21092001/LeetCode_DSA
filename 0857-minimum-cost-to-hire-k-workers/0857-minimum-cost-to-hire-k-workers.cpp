class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> ratios;
        for(int i=0;i<n;i++){
            double ratio=(double)wage[i]/quality[i];
            ratios.push_back({ratio,i});
        }

        sort(ratios.begin(),ratios.end());
        priority_queue<int> pq;
        int sum=0;
        for(int i=0;i<k;i++){
            pq.push(quality[ratios[i].second]);
            sum+=quality[ratios[i].second];
        }

        double ans=sum*ratios[k-1].first;
        for(int i=k;i<n;i++){
            sum+=quality[ratios[i].second];
            pq.push(quality[ratios[i].second]);

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            ans=min(ans,ratios[i].first*sum);
        }
        return ans;
    }
};