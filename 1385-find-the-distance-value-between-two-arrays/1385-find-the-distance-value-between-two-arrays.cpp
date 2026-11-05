class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        int m=arr1.size();
        int n=arr2.size();
        //unordered_set<int> st;

        for(int i=0;i<m;i++){
            bool check=true;
            for(int j=0;j<n;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    check=false;
                    break;
                }
            }
            if(check==true)ans++;
        }

        return ans;
    }
};