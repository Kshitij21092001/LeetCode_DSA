class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> inactiveBlocks;
        int n=s.length();

        int oneCount=count(begin(s),end(s),'1');
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n&&s[i]=='0')i++;
                inactiveBlocks.push_back(i-start);
            }
            else i++;
        }

        int maxCount=0;
        for(int i=1;i<inactiveBlocks.size();i++){
            maxCount=max(maxCount,inactiveBlocks[i]+inactiveBlocks[i-1]);
        }

        return oneCount+maxCount;
    }
};