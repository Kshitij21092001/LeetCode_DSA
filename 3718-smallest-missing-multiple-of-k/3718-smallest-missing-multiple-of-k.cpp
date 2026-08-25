class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        st.insert(nums.begin(),nums.end());

        int mul=1;
        while(true){
            int num=mul*k;
            if(st.count(num)==0){
                return num;
                break;
            }
            mul++;
        }
        return -1;
    }
};