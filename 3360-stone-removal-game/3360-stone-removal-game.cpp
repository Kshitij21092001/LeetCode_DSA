class Solution {
public:
    bool canAliceWin(int n) {
        int ans=0;
        int curr=10;
        while(1){
            if(n<curr)break;
            n-=curr;
            curr--;
            ans++;
        }

        if(ans%2==0)return false;
        return true;
    }
};