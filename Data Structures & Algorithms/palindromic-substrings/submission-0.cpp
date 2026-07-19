class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        for(int i = 0; i < n; i++) dp[i][i] = true;

        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) dp[i-1][i] = true;
        }

        for(int j = 2; j < n; j++){
            for(int i = j; i < n; i++){
                if(s[i] == s[i-j]){
                    dp[i-j][i] = dp[i+1-j][i-1];
                }
                else dp[i-j][i] = false;
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) if(dp[i][j]) count++;
        }

        return count;
    }
};
