class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0=0;
        int count1=0;
        int count2=0;

        for(int i=0;i<stones.size();i++){
            int num=stones[i]%3;
            if(num==0)count0++;
            else if(num==1)count1++;
            else count2++;
        }

        if(count0%2==0)return count1>=1 && count2>=1;
        return count1-count2>2 || count2-count1>2;        
    }
};