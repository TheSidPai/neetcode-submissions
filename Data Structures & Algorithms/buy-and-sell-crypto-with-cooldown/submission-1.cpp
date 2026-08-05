class Solution {
public:

    unordered_map<string, int> dp;


    int maxProfit(vector<int>& prices) {
        return dfs(0, prices, true);
    }

    int dfs(int idx, vector<int>& prices, bool canBuy){
        if(idx >= prices.size()){
            return 0;
        }

        string key = to_string(idx) + "-" + to_string(canBuy);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int cooldown = dfs(idx+1, prices, canBuy);

        if(canBuy){
            int buy = dfs(idx+1, prices, false) - prices[idx];
            dp[key] = max(buy, cooldown);
        } else{
            int sell = dfs(idx+2, prices, true) + prices[idx];
            dp[key] = max(sell, cooldown);
        }

        return dp[key];
    }
};
