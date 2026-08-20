class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 1;
        dp[0] = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; (j*j) <= i; j++) dp[i] = min(dp[i], dp[i-(j*j)] + 1);
        }

        // for(int i: dp) cout<<i<<" ";
        return dp[n];
    }
};