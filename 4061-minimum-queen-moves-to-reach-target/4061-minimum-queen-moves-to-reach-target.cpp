class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int dRow=abs(source[0]-target[0]);
        int dCol=abs(source[1]-target[1]);

        if(dRow==0 && dCol==0)return 0;
        if((dRow==dCol)|| dRow==0 || dCol==0)return 1;
        return 2;
    }
};