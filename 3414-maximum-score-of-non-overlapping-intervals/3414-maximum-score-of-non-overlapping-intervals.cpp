class Solution {
public:

    struct Node{
        long long weight=-1;
        vector<int> idxs;
    };

    vector<int> nextIndex;

    int findNextBS(vector<vector<int>>& intervals,int currEnd){
        int start=0;
        int end=intervals.size()-1;
        int result=end+1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(intervals[mid][0]>currEnd){
                result=mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return result;
    }

    Node helper(vector<vector<int>>& intervals,int ind,int k,vector<vector<Node>>& dp){
        if(ind>=intervals.size() || k==0)return Node();

        if(dp[ind][k].weight!=-1)return dp[ind][k];

        Node skip=helper(intervals,ind+1,k,dp);
        Node take=helper(intervals,nextIndex[ind],k-1,dp);

        int currWeight=intervals[ind][2];
        int currInd=intervals[ind][3];

        Node curr;
        curr.weight=take.weight+currWeight;
        curr.idxs=take.idxs;
        curr.idxs.push_back(currInd);

        sort(curr.idxs.begin(),curr.idxs.end());

        Node result;
        if(skip.weight<curr.weight)result=curr;
        else if(skip.weight>curr.weight)result=skip;
        else{
            result=(skip.idxs<curr.idxs)?skip:curr;
        }
        return dp[ind][k]=result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        nextIndex.resize(n);

        for(int i=0;i<n;i++)intervals[i].push_back(i);

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<n;i++){
            int currEnd=intervals[i][1];

            nextIndex[i]=findNextBS(intervals,currEnd);
        }

        vector<vector<Node>> dp(n+1,vector<Node> (5));
        //return helper(intervals,0,4,dp).idxs;

        for(int i=n-1;i>=0;i--){
            int currWeight=intervals[i][2];
            int currInd=intervals[i][3];
            for(int k=1;k<=4;k++){
                Node skip=dp[i+1][k];
                Node take=dp[nextIndex[i]][k-1];

                Node curr;
                curr.weight=take.weight+currWeight;
                curr.idxs=take.idxs;
                curr.idxs.push_back(currInd);

                sort(curr.idxs.begin(),curr.idxs.end());

                Node result;
                if(skip.weight<curr.weight)result=curr;
                else if(skip.weight>curr.weight)result=skip;
                else{
                    result=(skip.idxs<curr.idxs)?skip:curr;
                }
                dp[i][k]=result; 
            }       
        }
        return dp[0][4].idxs;
    }
};