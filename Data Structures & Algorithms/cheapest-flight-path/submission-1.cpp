class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight: flights){
            int a = flight[0];
            int b = flight[1];
            int c = flight[2];
            adj[a].push_back({b, c});
        }

        vector<int> dp(n, INT_MAX);
        dp[src] = 0;

        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        while(!q.empty()){
            auto [idx, step, curr] = q.front();
            q.pop();

            if(step <= k){
                for(auto [dest, cost]: adj[idx]){
                    if(curr+cost < dp[dest]){
                        q.push({dest, step+1, curr+cost});
                        dp[dest] = curr+cost;
                    }
                }
            }
        }

        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};
