class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& infected) {
        infected[node] = 1;

        for (auto ngbr : adj[node]) {
            if (!infected[ngbr]) {
                dfs(ngbr, adj, infected);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods
        vector<int> infected(n, 0);
        dfs(k, adj, infected);

        // If any non-suspicious method invokes a suspicious method,
        // nothing can be removed.
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!infected[u] && infected[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Otherwise remove all suspicious methods.
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!infected[i])
                ans.push_back(i);
        }

        return ans;
    }
};