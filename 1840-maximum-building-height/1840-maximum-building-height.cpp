class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(),restrictions.end());
        int restLen=restrictions.size();
        if(restLen==0)return n-1;
        bool isLastIndexInRestriction=(restrictions[restLen-1][0]==n);

        int newLen=restLen+1+(isLastIndexInRestriction ? 0 : 1);

        vector<vector<int>> newHeights(newLen,vector<int>(2,0));
        newHeights[0][0]=1;
        newHeights[0][1]=0;

        for(int i=0;i<restLen;i++){
            int indexDiff=restrictions[i][0]-newHeights[i][0];
            int possibleHeight=newHeights[i][1]+indexDiff;
            newHeights[i+1][0]=restrictions[i][0];
            newHeights[i+1][1]=min(restrictions[i][1],possibleHeight);
        }

        if(!isLastIndexInRestriction){
            int indexDiff=n-newHeights[restLen][0];
            int possibleHeight=newHeights[restLen][1]+indexDiff;
            newHeights[restLen+1][0]=n;
            newHeights[restLen+1][1]=min(n-1,possibleHeight);
        }

        for(int i=newLen-2;i>=0;i--){
            int indexDiff=newHeights[i+1][0]-newHeights[i][0];
            int possibleHeight=newHeights[i+1][1]+indexDiff;
            newHeights[i][1]=min(newHeights[i][1],possibleHeight);
        }

        int ans=0;

        for(int i=0;i<newLen-1;i++){
            int index1=newHeights[i][0];
            int index2=newHeights[i+1][0];

            int height1=newHeights[i][1];
            int height2=newHeights[i+1][1];

            ans=max(ans,(index2-index1-abs(height2-height1))/2 + max(height1,height2));
        }
        return ans;
    }
};