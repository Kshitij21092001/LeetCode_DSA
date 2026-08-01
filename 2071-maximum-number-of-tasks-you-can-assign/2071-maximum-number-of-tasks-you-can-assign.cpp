class Solution {
public:

    bool check(vector<int>& tasks,vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed=0;
        multiset<int> ms(workers.begin(),workers.begin()+mid);

        for(int i=mid-1;i>=0;i--){
            auto itr=prev(ms.end());

            if(*itr>=tasks[i])ms.erase(itr);
            else if(pillsUsed>=pills)return false;
            else{
                auto availableWorker=ms.lower_bound(tasks[i]-strength);
                if(availableWorker==ms.end())return false;
                ms.erase(availableWorker);
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m=tasks.size();
        int n=workers.size();
        int left=0;
        int right=min(m,n);

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());
        int ans=0;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(check(tasks,workers,pills,strength,mid)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};