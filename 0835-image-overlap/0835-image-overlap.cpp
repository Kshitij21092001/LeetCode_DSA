class Solution {
public:

    int helper(vector<vector<int>>& A, vector<vector<int>>& B,int dRow,int dCol){
        int n=A.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int newARow=i+dRow;
                int newACol=j+dCol;

                if(newARow<0 || newARow>=n || newACol<0 || newACol>=n)continue;

                if(A[newARow][newACol]==1 && B[i][j]==1)count++;
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();

        int ans=0;
        for(int dRow=-n+1;dRow<n;dRow++){
            for(int dCol=-n+1;dCol<n;dCol++){
                ans=max(ans,helper(A,B,dRow,dCol));
            }
        }
        return ans;
    }
};