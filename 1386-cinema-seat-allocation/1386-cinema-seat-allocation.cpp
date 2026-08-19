class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;

        for(int i=0;i<reservedSeats.size();i++){
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }

        int ans=2*(n-mp.size());

        for(auto it:mp){
            set<int> st=it.second;

            if(st.count(2)==0 && st.count(3)==0 && st.count(4)==0 && st.count(5)==0){
                ans++;
                st.insert(2);
                st.insert(3);
                st.insert(4);
                st.insert(5);
            }

            if(st.count(4)==0 && st.count(5)==0 && st.count(6)==0 && st.count(7)==0){
                ans++;
                st.insert(4);
                st.insert(5);
                st.insert(6);
                st.insert(7);
            }

            if(st.count(6)==0 && st.count(7)==0 && st.count(8)==0 && st.count(9)==0){
                ans++;
                st.insert(6);
                st.insert(7);
                st.insert(8);
                st.insert(9);
            }
        }
        return ans;
    }
};