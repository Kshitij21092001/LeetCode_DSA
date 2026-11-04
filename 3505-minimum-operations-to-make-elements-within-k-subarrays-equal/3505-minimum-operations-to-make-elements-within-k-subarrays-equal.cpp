class Solution {
public:
    multiset<long long> small, large;   // two halves of the current window
    long long sumSmall = 0, sumLarge = 0;

    // keep sizes balanced: small has equal count, or one extra
    void balance() {
        while (small.size() > large.size() + 1) {
            long long val = *small.rbegin();      // biggest of small
            small.erase(small.find(val));
            sumSmall -= val;
            large.insert(val);
            sumLarge += val;
        }
        while (small.size() < large.size()) {
            long long val = *large.begin();       // smallest of large
            large.erase(large.find(val));
            sumLarge -= val;
            small.insert(val);
            sumSmall += val;
        }
    }

    void addNum(long long val) {
        if (small.empty() || val <= *small.rbegin()) {
            small.insert(val);
            sumSmall += val;
        } else {
            large.insert(val);
            sumLarge += val;
        }
        balance();
    }

    void removeNum(long long val) {
        if (val <= *small.rbegin()) {
            small.erase(small.find(val));
            sumSmall -= val;
        } else {
            large.erase(large.find(val));
            sumLarge -= val;
        }
        balance();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        small.clear();
        large.clear();
        sumSmall = 0;
        sumLarge = 0;

        // Step 1: cost[i] = operations to make window starting at i equal
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            addNum(nums[i]);
            if (i >= x) removeNum(nums[i - x]);   // window got too big, drop the old one

            if (i >= x - 1) {
                long long median = *small.rbegin();
                long long smallCount = small.size();
                long long largeCount = large.size();

                long long leftCost = median * smallCount - sumSmall;
                long long rightCost = sumLarge - median * largeCount;

                cost[i - x + 1] = leftCost + rightCost;
            }
        }

        // Step 2: dp[i][j] = min cost using first i elements and j windows
        long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++) dp[i][0] = 0;   // 0 windows costs 0

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                // choice 1: don't end a window here
                dp[i][j] = dp[i-1][j];

                // choice 2: a window ends at i-1 (it starts at i-x)
                if (i >= x && dp[i-x][j-1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i-x][j-1] + cost[i-x]);
                }
            }
        }

        return dp[n][k];
    }
};