class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dist=abs(start[0]-target[0])+abs(start[1]-target[1]);
        return dist%2==0;
    }
};