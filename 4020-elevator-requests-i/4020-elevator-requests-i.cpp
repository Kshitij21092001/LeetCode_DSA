class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr=0;
        int time=0;
        int reqSize=requests.size();
        for(int i=0;i<reqSize;i++){
            if(curr==requests[i])continue;
            time+=(abs(requests[i]-curr));
            curr=requests[i];
        }
        return time;
    }
};