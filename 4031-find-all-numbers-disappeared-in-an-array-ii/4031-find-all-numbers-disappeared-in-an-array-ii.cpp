class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        unordered_set<int> st;
        st.insert(nums.begin(),nums.end());
        vector<int> temp;
        for(int i=lower;i<=upper;i++){

            if(st.count(i)==0){
                if(temp.size()==0)temp.push_back(i);
                if(temp.size()==1)temp.push_back(i);
                if(temp.size()==2){
                    temp.pop_back();
                    temp.push_back(i);
                }
            }
            else{
                if(temp.size()!=0){
                    ans.push_back(temp);
                    vector<int> temp2;
                    temp=temp2;
                    
                }

            }
        

        }
        if(temp.size()!=0)ans.push_back(temp);

        return ans;
    }
};