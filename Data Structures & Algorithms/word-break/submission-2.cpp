class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        int minLen = wordDict[0].size();
        for(string word: wordDict) minLen = min(minLen, (int)word.size());
        dp[0] = true;

        for(int i = 1; i <= len; i++){
            if(i < minLen) dp[i] = false;
            else{
                for(auto word: wordDict){
                    int n = word.size();
                    if(n > i) continue;
                    if(s.substr(i - n, n) == word) dp[i] = dp[i] || dp[i-n];
                }
            }
        }
        return dp[len];
    }
};
