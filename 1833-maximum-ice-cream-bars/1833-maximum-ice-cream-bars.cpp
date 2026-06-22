class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //same question using count sort
        //find the maximum cost and create array of that size
        int maxCost=0;
        for(int cost:costs)maxCost=max(maxCost,cost);

        vector<int> count(maxCost+1,0);
        //put the numbers based on their count
        for(int cost:costs)count[cost]++;

        int bars=0;
        int amountRemaining=coins;

        for(int i=0;i<=maxCost;i++){
            if(count[i]>0){
                int canBuy=min(count[i],amountRemaining/i);
                bars+=canBuy;
                amountRemaining-=canBuy*i;

                if(canBuy==0)break;
            }
        }
        return bars;
    }
};