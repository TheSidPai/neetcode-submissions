class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) dp[i][0] = false;
        for(int j = 1; j <= n; j++){
            if(p[j-1] == '*' && j >= 2) dp[0][j] = dp[0][j-2];
            else dp[0][j] = false;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                char curr = p[j-1];
                if(curr >= 'a' &&curr <= 'z') dp[i][j] = dp[i-1][j-1] && (curr == s[i-1]);
                else if(curr == '.') dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = dp[i][j-2];
                    if(dp[i][j-2]) continue;

                    if(p[j-2] == '.' || p[j-2] == s[i-1]) dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }
};
