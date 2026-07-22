class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        dp.push_back({triangle[0][0]});

        for(int i = 1; i < n; i++){
            vector<int> curr (i+1, 0);
            for(int j = 0; j <= i; j++){
                int off = 0;
                if(j == 0) off = dp[i-1][j];
                else if(j == i) off = dp[i-1][j-1];
                else off = min(dp[i-1][j], dp[i-1][j-1]);

                curr[j] = triangle[i][j] + off;
            }
            dp.push_back(curr);
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};