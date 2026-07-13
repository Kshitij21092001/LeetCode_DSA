class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str="123456789";
        vector<int> cases;
        for(int window=2;window<=9;window++){
            for(int i=0;i<9-window+1;i++){
                cases.push_back(stoi(str.substr(i,window)));
            }
        }

        vector<int> ans;
        for(int i=0;i<cases.size();i++){
            if(cases[i]>=low && cases[i]<=high){
                ans.push_back(cases[i]);
            }
        }
        return ans;
    }
};