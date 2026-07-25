class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int coin: coins){
            for(int i = 1; i <= amount; i++){
                if(i - coin >= 0 && dp[i - coin] != -1){
                    if(dp[i] == -1) dp[i] = dp[i-coin]+1;
                    else dp[i] = min(dp[i], 1+dp[i-coin]);
                }
            }
        }

        return dp[amount];
    }
};
