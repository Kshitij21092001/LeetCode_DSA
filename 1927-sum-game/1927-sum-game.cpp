class Solution {
public:
    bool sumGame(string num) {
        int leftSum=0;
        int rightSum=0;
        int leftQ=0;
        int rightQ=0;

        int n=num.length();
        for(int i=0;i<n;i++){
            if(i<(n/2)){
                if(num[i]=='?')leftQ++;
                else leftSum+=((num[i])-'0');
            }
            else{
                if(num[i]=='?')rightQ++;
                else rightSum+=((num[i])-'0');
            }
        }

        if((leftQ+rightQ)%2!=0)return true;
        return (2*leftSum+9*leftQ)!=(2*rightSum+9*rightQ);
    }
};